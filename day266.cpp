-- -- -- -- -- -- -- -- -GFG - POTD - 19 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


-- -- -- -- -- -- -- -- -LeetCode - POTD - 20 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

407. Trapping Rain Water II
Solved
Hard
Topics
Companies
Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

 

Example 1:


Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.
Example 2:


Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10
 

Constraints:

m == heightMap.length
n == heightMap[i].length
1 <= m, n <= 200
0 <= heightMap[i][j] <= 2 * 104


class Solution {
public:
    int trapRainWater(vector<vector<int>>& height) {
         int n = height.size();
        int m = height[0].size();

        // pair<int, pair<int, int>> 
        //{height, {r, c}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> vis(n, vector<int>(m));

        //first and last column
        for(int i=0; i<n; i++){
            vis[i][0] = 1;
            vis[i][m-1] = 1;
            pq.push({height[i][0], {i, 0}});
            pq.push({height[i][m-1], {i, m-1}});
        }
        //first and last row
        for(int i=0; i<m; i++){
            vis[0][i]=1;
            vis[n-1][i]=1;
            pq.push({height[0][i], {0, i}});
            pq.push({height[n-1][i], {n-1, i}});
        }
        int ans=0;
        while(!pq.empty()){
            int h = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, -1, 0, 1};
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                    ans+=max(0, h-height[nr][nc]);
                    pq.push({max(h, height[nr][nc]), {nr, nc}});
                    vis[nr][nc] = 1;
                }
            }
        }
        return ans;
    }
};