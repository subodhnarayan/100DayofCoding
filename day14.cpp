// Path With Minimum Effort
//             MediumAccuracy : 53.13 %
//         Submissions : 31K +
//     Points : 4 In need of more Geekbits
//     ? Win from a pool of 3500 + Geekbits via DSA - based Coding Contest every sunday !

//                                                    banner You are a hiker preparing for an upcoming hike.You are given heights[][],
//     a 2D array of size rows x columns, where heights[row][col] represents the height of cell(row, col).You are situated in the top - left cell, (0, 0), and you hope to travel to the bottom - right cell, (rows - 1, columns - 1)(i.e., 0 - indexed).You can move up, down, left, or right, and you wish to find the route with minimum effort.

//                                                                                                                                                                                                                                                                                                  Note : A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

//     Example 1 :

//     Input : row = 3 columns = 3 heights = [ [ 1, 2, 2 ], [ 3, 8, 2 ], [ 5, 3, 5 ] ] Output : 2 Explaination : The route 1 -> 3->5->3->5 has a maximum absolute difference of 2 in consecutive cells.This is better than the route 1->2->2->2->5,
//             where the maximum absolute difference is 3. Example 2 :

//     Input :
//     row = 2 columns = 2 heights = [ [ 7, 7 ], [ 7, 7 ] ] Output :
//     0 Explaination :
//     Any route from the top - left cell to the bottom - right cell has a maximum absolute difference of 0 in consecutive cells.Your Task :
//     You don't need to read input or print anything. Your task is to complete the function MinimumEffort() which takes intergers rows, columns, and the 2D array heights[][]  and returns the minimum effort required to travel from the top-left cell to the bottom-right cell.

//     Expected Time Complexity : O(rowsxcolumns)
//         Expected Space Complexity : O(rowsxcolumns)

//             Constraints :
//     1 <= rows,
//             columns <= 100 rows == heights.length columns == heights[i].length 0 <= heights[i][j] <= 106



class Solution {
  public:
    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
              vector<vector<int>>dp(rows,vector<int>(columns,1000000000));
            dp[0][0] = 0;
        queue<pair<int,int>>q;
        vector<pair<int,int>>dir{{-1,0},{1,0},{0,1},{0,-1}};
        q.push({0,0});
        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();
            int x = p.first,y = p.second;
            for(auto it:dir){
                int i = x + it.first,j = y + it.second;
                if(i<0 || j<0 || i>=rows || j>=columns)continue;
                if(dp[i][j]>max(abs(heights[i][j]-heights[x][y]),dp[x][y])){
                    dp[i][j]=max(abs(heights[i][j]-heights[x][y]),dp[x][y]);
                    q.push({i,j});
                }
            }
        }
        return dp[rows-1][columns-1];
    }
};