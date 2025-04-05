-- -- -- -- -- -- -- -- -GFG - POTD - 05 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Find the number of islands
Difficulty: MediumAccuracy: 42.12%Submissions: 234K+Points: 4Average Time: 20m
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:

Input: grid[][] = [['L', 'L', 'W', 'W', 'W'], ['W', 'L', 'W', 'W', 'L'], ['L', 'W', 'W', 'L', 'L'], ['W', 'W', 'W', 'W', 'W'], ['L', 'W', 'L', 'L', 'W']]
Output: 4
Explanation:
The image below shows all the 4 islands in the grid.
 
Input: grid[][] = [['W', 'L', 'L', 'L', 'W', 'W', 'W'], ['W', 'W', 'L', 'L', 'W', 'L', 'W']]
Output: 2
Expanation:
The image below shows 2 islands in the grid.
 
Constraints:
1 ≤ n, m ≤ 500
grid[i][j] = {'L', 'W'}

class Solution {
    public:
      int row,col;
     void islandHelper(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j)
      {
          if(i>=row||i<0||j>=col||j<0||grid[i][j]=='W'||vis[i][j]==1)return ;
          vis[i][j] = 1;
          islandHelper(grid,vis,i+1,j);
          islandHelper(grid,vis,i-1,j);
          islandHelper(grid,vis,i,j+1);
          islandHelper(grid,vis,i,j-1);
          islandHelper(grid,vis,i+1,j+1);
          islandHelper(grid,vis,i+1,j-1);
          islandHelper(grid,vis,i-1,j+1);
          islandHelper(grid,vis,i-1,j-1);
      }
      int countIslands(vector<vector<char>>& grid) {
          // Code here
          row = grid.size();
          col = grid[0].size();
          vector<vector<int>>vis(row,vector<int>(col,0));
          int islands = 0;
          for(int i =0 ;i<row;i++)
          {
              for(int j = 0;j<col;j++)
              {
                  if(!vis[i][j]&&grid[i][j]=='L')
                  {
                      islands++;
                      islandHelper(grid,vis,i,j);
                  }
              }
          }
          return islands;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 05 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


