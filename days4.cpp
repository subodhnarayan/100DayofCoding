--------------------------------GFG POTD 12/07/2025-------------------------------

Gold Mine Problem
Difficulty: MediumAccuracy: 29.73%Submissions: 132K+Points: 4
Given a gold mine called mat[][]. Each field in this mine contains a positive integer which is the amount of gold in tons. Initially, the miner can start from any row in the first column. From a given cell, the miner can move -

to the cell diagonally up towards the right
to the right
to the cell diagonally down towards the right
Find out the maximum amount of gold that he can collect until he can no longer move.

Examples:

Input: mat[][] = [[1, 3, 3], [2, 1, 4], [0, 6, 4]]
Output: 12
Explaination: The path is (1, 0) -> (2, 1) -> (2, 2). Total gold collected is 2 + 6 + 4 = 12.
Input: mat[][] = [[1, 3, 1, 5], [2, 2, 4, 1], [5, 0, 2, 3], [0, 6, 1, 2]]
Output: 16
Explaination: The path is (2, 0) -> (3, 1) -> (2, 2) -> (2, 3) or (2, 0) -> (1, 1) -> (1, 2) -> (0, 3). 
Total gold collected is (5 + 6 + 2 + 3) or (5 + 2 + 4 + 5) = 16.
Input: mat[][] = [[1, 3, 3], [2, 1, 4], [0, 7, 5]]
Output: 14
Explaination: The path is (1,0) -> (2,1) -> (2,2). Total gold collected is 2 + 7 + 5 = 14.
Constraints:
1 ≤ mat.size(), mat[0].size() ≤ 500
0 ≤ mat[i][j] ≤ 100

Expected Complexities
Time Complexity: O(n * m)
Auxiliary Space: O(1)

class Solution {
  public:
    int n , m ; 
    int f(vector<vector<int>> & grid , vector<vector<int>> & dp , int i , int j){
        if(i >= n || j < 0 || j >= m || i < 0){
            return 0 ; 
        }
        if(dp[i][j] != -1) return dp[i][j] ; 
        return dp[i][j] = grid[i][j] + max({f(grid, dp , i+1 , j+1), f(grid , dp , i , j+1) , f(grid , dp , i-1 , j+1)});
    }
    int maxGold(vector<vector<int>>& mat) {
        // code here
        n = mat.size() , m = mat[0].size() ; 
        int res = 0 ; 
        vector<vector<int>> dp(n+1, vector<int>(m+1 , -1)) ; 
        for(int i = 0 ; i < n ; i++){
            res = max(res , f(mat ,dp , i , 0)) ; 
        }
        return res; 
    }
};


--------------------------------Leetcode POTD 12/07/2025---------------------------

