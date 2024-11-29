-- -- -- -- -- -- -- -- -GFG - POTD - 29 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Add Binary Strings
Difficulty: MediumAccuracy: 23.25%Submissions: 76K+Points: 4
Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110
Constraints:
1 ≤s1.size(), s2.size()≤ 106



class Solution {
  public:
   string find(string &str1,string &str2){
      
       int n=str1.size(),m=str2.size();
      
      int i=n-1,j=m-1;
      int carry=0;
      string st="";
      while(i>=0&&j>=0){
          
          int sum=(str1[i]-'0')+(str2[j]-'0')+carry;
          
          if(sum==2){
              st+="0";
              carry=1;
          }
        else if(sum==3){
              st+="1";
              carry=1;
          }
         
          else {
              st+=to_string(sum);
              carry=0;
          }
          i--;j--;
      }
      
      while(i>=0){
            int sum=(str1[i]-'0')+carry;
          
            if(sum==2){
              st+="0";
              carry=1;
          }
             else if(sum==3){
              st+="1";
              carry=1;
          }
          else {
              st+=to_string(sum);
              carry=0;
          }
          i--;
      }
      if(carry)st+=to_string(carry);
      
      while(st.back()=='0'){
          st.pop_back();
      }
      reverse(st.begin(),st.end());
      return st;
      
  }
    string addBinary(string& s1, string& s2) {
        
        int n=s1.size(),m=s2.size();
        
        if(n>m)return find(s1,s2);
        else return find(s2,s1);
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 29 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


2577. Minimum Time to Visit a Cell In a Grid
Solved
Hard
Topics
Companies
Hint
You are given a m x n matrix grid consisting of non-negative integers where grid[row][col] represents the minimum time required to be able to visit the cell (row, col), which means you can visit the cell (row, col) only when the time you visit it is greater than or equal to grid[row][col].

You are standing in the top-left cell of the matrix in the 0th second, and you must move to any adjacent cell in the four directions: up, down, left, and right. Each move you make takes 1 second.

Return the minimum time required in which you can visit the bottom-right cell of the matrix. If you cannot visit the bottom-right cell, then return -1.

 

Example 1:



Input: grid = [[0,1,3,2],[5,1,2,5],[4,3,8,6]]
Output: 7
Explanation: One of the paths that we can take is the following:
- at t = 0, we are on the cell (0,0).
- at t = 1, we move to the cell (0,1). It is possible because grid[0][1] <= 1.
- at t = 2, we move to the cell (1,1). It is possible because grid[1][1] <= 2.
- at t = 3, we move to the cell (1,2). It is possible because grid[1][2] <= 3.
- at t = 4, we move to the cell (1,1). It is possible because grid[1][1] <= 4.
- at t = 5, we move to the cell (1,2). It is possible because grid[1][2] <= 5.
- at t = 6, we move to the cell (1,3). It is possible because grid[1][3] <= 6.
- at t = 7, we move to the cell (2,3). It is possible because grid[2][3] <= 7.
The final time is 7. It can be shown that it is the minimum time possible.
Example 2:



Input: grid = [[0,2,4],[3,2,1],[1,0,4]]
Output: -1
Explanation: There is no path from the top left to the bottom-right cell.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
0 <= grid[i][j] <= 105
grid[0][0] == 0


class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        priority_queue<pair<int, pair<int, int>>, 
                      vector<pair<int, pair<int, int>>>, 
                      greater<pair<int, pair<int, int>>>> minHeap;
        
        minHeap.push({0, {0, 0}}); // time, row(x), col(y)
        
        vector<vector<int>> seen(rows, vector<int>(cols, 0));
        seen[0][0] = 1;
        
        vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            int currTime = curr.first;
            int currRow = curr.second.first;
            int currCol = curr.second.second;
            
            minHeap.pop();
            
            if (currRow == rows - 1 && currCol == cols - 1) 
                return currTime;
            
            for (auto move : moves) {
                int nextRow = move.first + currRow;
                int nextCol = move.second + currCol;
                
                if (nextRow >= 0 && nextCol >= 0 && 
                    nextRow < rows && nextCol < cols && 
                    !seen[nextRow][nextCol]) {
                    
                    int waitTime = ((grid[nextRow][nextCol] - currTime) % 2 == 0) ? 1 : 0;
                    int nextTime = max(currTime + 1, grid[nextRow][nextCol] + waitTime);
                    
                    minHeap.push({nextTime, {nextRow, nextCol}});
                    seen[nextRow][nextCol] = 1;
                }
            }
        }
        return -1;
    }
};