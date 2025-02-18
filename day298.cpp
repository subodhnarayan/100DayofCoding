-- -- -- -- -- -- -- -- -GFG - POTD - 18 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

K Closest Points to Origin
Difficulty: MediumAccuracy: 62.4%Submissions: 16K+Points: 4
Given an array of points where each point is represented as points[i] = [xi, yi] on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance, defined as: 

sqrt( (x2 - x1)2 + (y2 - y1)2 )

Note: You can return the k closest points in any order, driver code will sort them before printing.

Examples:

Input: k = 2, points[] = [[1, 3], [-2, 2], [5, 8], [0, 1]]
Output: [[-2, 2], [0, 1]]
Explanation: The Euclidean distances from the origin are:
Point (1, 3) = sqrt(10)
Point (-2, 2) = sqrt(8)
Point (5, 8) = sqrt(89)
Point (0, 1) = sqrt(1)
The two closest points to the origin are [-2, 2] and [0, 1].
Input: k = 1, points = [[2, 4], [-1, -1], [0, 0]]
Output: [[0, 0]]
Explanation: The Euclidean distances from the origin are:
Point (2, 4) = sqrt(20)
Point (-1, -1) = sqrt(2)
Point (0, 0) = sqrt(0)
The closest point to origin is (0, 0).
Constraints:

1 <= k <= points.size() <= 105
-104 <= xi, yi <= 104


Time Complexity: O (N log K)Auxiliary Space: O (K)

class Solution {
    public:
      vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
          // Your code here
          
          priority_queue<pair<int,int>> pq; //max-heap
          
          int n=points.size();
          
          for(int i=0;i<n;i++){
              int x=points[i][0];
              int y=points[i][1];
              int d = x*x + y*y;
              
              pq.push({d,i});
              
              if(pq.size()>k)
              pq.pop();
          }
          
          vector<vector<int>> res;
          
          while(!pq.empty()){
              int i = pq.top().second;
              pq.pop();
              res.push_back({points[i][0],points[i][1]});
          }
          
          return res;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 18 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

2375. Construct Smallest Number From DI String
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed string pattern of length n consisting of the characters 'I' meaning increasing and 'D' meaning decreasing.

A 0-indexed string num of length n + 1 is created using the following conditions:

num consists of the digits '1' to '9', where each digit is used at most once.
If pattern[i] == 'I', then num[i] < num[i + 1].
If pattern[i] == 'D', then num[i] > num[i + 1].
Return the lexicographically smallest possible string num that meets the conditions.

 

Example 1:

Input: pattern = "IIIDIDDD"
Output: "123549876"
Explanation:
At indices 0, 1, 2, and 4 we must have that num[i] < num[i+1].
At indices 3, 5, 6, and 7 we must have that num[i] > num[i+1].
Some possible values of num are "245639871", "135749862", and "123849765".
It can be proven that "123549876" is the smallest possible num that meets the conditions.
Note that "123414321" is not possible because the digit '1' is used more than once.
Example 2:

Input: pattern = "DDD"
Output: "4321"
Explanation:
Some possible values of num are "9876", "7321", and "8742".
It can be proven that "4321" is the smallest possible num that meets the conditions.
 

Constraints:

1 <= pattern.length <= 8
pattern consists of only the letters 'I' and 'D'.


class Solution {
    public:
        string smallestNumber(string pattern) {
             int n = pattern.length();
            string result = "";
            int stack[n + 1];
            int index = 0;
    
            for (int i = 0; i <= n; i++) {
                stack[index++] = i + 1;
    
                if (i == n || pattern[i] == 'I') {
                    while (index > 0) {
                        result += to_string(stack[--index]);
                    }
                }
            }
            return result;
        }
};