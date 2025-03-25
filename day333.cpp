-- -- -- -- -- -- -- -- -GFG - POTD - 25 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Boolean Parenthesization
Difficulty: HardAccuracy: 20.15%Submissions: 131K+Points: 8Average Time: 30m
You are given a boolean expression s containing
    'T' ---> true
    'F' ---> false 
and following operators between symbols
   &   ---> boolean AND
    |   ---> boolean OR
   ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer is guaranteed to fit within a 32-bit integer.

Examples:

Input: s = "T|T&F^T"
Output: 4
Explaination: The expression evaluates to true in 4 ways: ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Input: s = "T^F|F"
Output: 2
Explaination: The expression evaluates to true in 2 ways: ((T^F)|F) and (T^(F|F)).
Constraints:
1 ≤ |s| ≤ 100 

Time Complexity: O(n^3)Auxiliary Space: O(n^2)

class Solution {
    public:
       bool evaluate(int b1,int b2,char &op)
      {
          if(op=='&')
              return b1&b2;
          if(op=='|')
              return b1|b2;
          if(op=='^')
              return b1^b2;
          
      }
        int helper(int start,int end,int req,string &s,  vector<vector<vector<int>>>&dp)
      {
          if(start==end)
              return (req==(s[start]=='T'))?1:0;
          if(dp[start][end][req]!=-1)
              return dp[start][end][req];
          int ans=0;
          for(int k=start+1;k<end;k++)
          {
              int leftTrue=helper(start,k-1,1,s,dp);
              int leftFalse=helper(start,k-1,0,s,dp);
              
              int rightTrue=helper(k+1,end,1,s,dp);
              int rightFalse=helper(k+1,end,0,s,dp);
              
              if(evaluate(1,1,s[k])==req)
                  ans+=leftTrue*rightTrue;
              if(evaluate(1,0,s[k])==req)
                  ans+=leftTrue*rightFalse;
              if(evaluate(0,1,s[k])==req)
                  ans+=leftFalse*rightTrue;
              if(evaluate(0,0,s[k])==req)
                  ans+=leftFalse*rightFalse;
              
          }
          return dp[start][end][req]=ans;
      }
      int countWays(string &s) {
          // code here
         int n=s.length();
         vector<vector<vector<int>>>dp(n,vector<vector<int>>
         (n,vector<int>(2,-1)));
         return helper(0,n-1,1,s,dp);
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 25 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


3394. Check if Grid can be Cut into Sections
Solved
Medium
Topics
Companies
Hint
You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [startx, starty, endx, endy], representing a rectangle on the grid. Each rectangle is defined as follows:

(startx, starty): The bottom-left corner of the rectangle.
(endx, endy): The top-right corner of the rectangle.
Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:

Each of the three resulting sections formed by the cuts contains at least one rectangle.
Every rectangle belongs to exactly one section.
Return true if such cuts can be made; otherwise, return false.

 

Example 1:

Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]

Output: true

Explanation:



The grid is shown in the diagram. We can make horizontal cuts at y = 2 and y = 4. Hence, output is true.

Example 2:

Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]

Output: true

Explanation:



We can make vertical cuts at x = 2 and x = 3. Hence, output is true.

Example 3:

Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]

Output: false

Explanation:

We cannot make two horizontal or two vertical cuts that satisfy the conditions. Hence, output is false.

 

Constraints:

3 <= n <= 109
3 <= rectangles.length <= 105
0 <= rectangles[i][0] < rectangles[i][2] <= n
0 <= rectangles[i][1] < rectangles[i][3] <= n
No two rectangles overlap.

class Solution {
    public:
        bool check(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end());
            
            int sections = 0;
            int max_end = intervals[0][1];
            
            for (auto& interval : intervals) {
                int start = interval[0], end = interval[1];
                if (max_end <= start) {
                    sections++;
                }
                max_end = max(max_end, end);
            }
            
            return sections >= 2;
        }
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
             vector<vector<int>> x_intervals, y_intervals;
            
            for (auto& rect : rectangles) {
                x_intervals.push_back({rect[0], rect[2]});
                y_intervals.push_back({rect[1], rect[3]});
            }
            
            return check(x_intervals) || check(y_intervals);
        }
    };