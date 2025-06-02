-- -- -- -- -- -- -- -- -GFG - POTD - 02 / 06 / 2025 ----------------------------------------

Unique Paths in a Grid
Difficulty: MediumAccuracy: 50.47%Submissions: 46K+Points: 4
You are given a 2d list grid[][] of size n x m consisting of values 0 and 1.
A value of 0 means that you can enter that cell and 1 implies that entry to that cell is not allowed.
You start at the upper-left corner of the grid (1, 1) and you have to reach the bottom-right corner (n, m) such that you can only move in the right or down direction from every cell.
Your task is to calculate the total number of ways of reaching the target.

Note: The first (1, 1) and last (n, m) cell of the grid can also be 1.
It is guaranteed that the total number of ways will fit within a 32-bit integer.

Examples:

Input: n = 3, m = 3,
grid[][] = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
Output: 2
Explanation: There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Input: n = 1, m = 3,
grid[][] = [[1, 0, 1]]
Output: 0
Explanation: There is no possible path to reach the end.
Constraints:
1 ≤ n*m ≤ 106

Expected Complexities
Time Complexity: O(n * m)
Auxiliary Space: O(n * m)

class Solution {
  public:
     int helper(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp){
        if(row==0 && col==0 && grid[row][col]==0) return 1;
        if(row<0 || col<0 || grid[row][col]==1) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int up = helper(grid, row-1, col, dp);
        int left = helper(grid, row, col-1, dp);
        dp[row][col] = up+left;
        return dp[row][col];
    }
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
        int paths = helper(grid, grid.size()-1, grid[0].size()-1, dp);
        return paths;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 02 / 06 / 2025 ----------------------------------------

135. Candy
Solved
Hard
Topics
premium lock icon
Companies
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 

Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 

Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104

