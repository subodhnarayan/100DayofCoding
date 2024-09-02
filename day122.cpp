- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 2 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Minimum Cost Path
Difficulty: HardAccuracy: 26.99%Submissions: 103K+Points: 8
Given a square grid of size N, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a path from the top left cell to the bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).  

Examples :

Input: grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.
Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.
Expected Time Complexity: O(n2*log(n))
Expected Auxiliary Space: O(n2) 
 Constraints:
1 ≤ n ≤ 500
1 ≤ cost of cells ≤ 500


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	int help(vector<vector<int>> &dp,int i,int j,vector<vector<int>> &grid){
	    if(i==0 && j==0) return grid[i][j];
	    if(i<0 || j<0) return 1e9;
	    if(dp[i][j]!=-1) return dp[i][j];
	    
	   // int up=grid[i][j]+help(dp,i,j+1,grid);
	   // int down=grid[i][j]+help(dp,i,j-1,grid);
	   // int right=grid[i][j]+help(dp,i+1,j,grid);
	   // int left=grid[i][j]+help(dp,i-1,j,grid);
	    
	   // return dp[i][j]=min(left,min(right,min(up,down)));
	    int cost = 1e9;

        // Recursive cases for all four possible movements (up, down, left, right).
        if (i > 0) cost = min(cost, grid[i][j] + help(dp, i - 1, j, grid));  // Up.
        if (j > 0) cost = min(cost, grid[i][j] + help(dp, i, j - 1, grid));  // Left.
	    
	    
	}
	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // int n=grid.size();
        // vector<vector<int>> dp(n,vector<int> (n,-1));
        // return help(dp,n-1,n-1,grid);
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        dis[0][0]=grid[0][0];
        pq.push({grid[0][0],{0,0}});
        int dirX[] = {-1,1,0,0};
        int dirY[] = {0,0,-1,1};
        while(pq.size()){
            auto temp = pq.top();
            pq.pop();
            int d = temp.first;
            for(int k=0;k<4;k++){
                int i = temp.second.first+dirX[k];
                int j = temp.second.second+dirY[k];
                if(i<n and j<n and i>=0 and j>=0 and d+grid[i][j]<dis[i][j]){
                    dis[i][j]=d+grid[i][j];
                    pq.push({d+grid[i][j],{i,j}});
                }
            }
        }
        return dis[n-1][n-1];
    }
};




- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 2 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


Code
Testcase
Testcase
Test Result
1894. Find the Student that Will Replace the Chalk
Solved
Medium
Topics
Companies
Hint
There are n students in a class numbered from 0 to n - 1. The teacher will give each student a problem starting with the student number 0, then the student number 1, and so on until the teacher reaches the student number n - 1. After that, the teacher will restart the process, starting with the student number 0 again.

You are given a 0-indexed integer array chalk and an integer k. There are initially k pieces of chalk. When the student number i is given a problem to solve, they will use chalk[i] pieces of chalk to solve that problem. However, if the current number of chalk pieces is strictly less than chalk[i], then the student number i will be asked to replace the chalk.

Return the index of the student that will replace the chalk pieces.

 

Example 1:

Input: chalk = [5,1,5], k = 22
Output: 0
Explanation: The students go in turns as follows:
- Student number 0 uses 5 chalk, so k = 17.
- Student number 1 uses 1 chalk, so k = 16.
- Student number 2 uses 5 chalk, so k = 11.
- Student number 0 uses 5 chalk, so k = 6.
- Student number 1 uses 1 chalk, so k = 5.
- Student number 2 uses 5 chalk, so k = 0.
Student number 0 does not have enough chalk, so they will have to replace it.
Example 2:

Input: chalk = [3,4,1,2], k = 25
Output: 1
Explanation: The students go in turns as follows:
- Student number 0 uses 3 chalk so k = 22.
- Student number 1 uses 4 chalk so k = 18.
- Student number 2 uses 1 chalk so k = 17.
- Student number 3 uses 2 chalk so k = 15.
- Student number 0 uses 3 chalk so k = 12.
- Student number 1 uses 4 chalk so k = 8.
- Student number 2 uses 1 chalk so k = 7.
- Student number 3 uses 2 chalk so k = 5.
- Student number 0 uses 3 chalk so k = 2.
Student number 1 does not have enough chalk, so they will have to replace it.
 

Constraints:

chalk.length == n
1 <= n <= 105
1 <= chalk[i] <= 105
1 <= k <= 109


