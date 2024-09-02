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