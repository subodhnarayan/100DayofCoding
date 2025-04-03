-- -- -- -- -- -- -- -- -GFG - POTD - 03 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Rotten Oranges
Difficulty: MediumAccuracy: 46.02%Submissions: 171K+Points: 4Average Time: 20m
Given a matrix mat[][] of dimension n * m where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cell have fresh oranges
2 : Cell have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and right) in a unit time.

Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.

Examples:

Input: mat[][] = [[0, 1, 2], [0, 1, 2], [2, 1, 1]]
Output: 1
Explanation: Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time.
Input: mat[][] = [[2, 2, 0, 1]]
Output: -1
Explanation: Oranges at (0,0) and (0,1) can't rot orange at (0,3).
Input: mat[][] = [[2, 2, 2], [0, 2, 0]]
Output: 0
Explanation: There is no fresh orange. 
Constraints:
1 ≤ mat.size() ≤ 500
1 ≤ mat[0].size() ≤ 500
mat[i][j] = {0, 1, 2} 

class Solution {
  public:
    vector<vector<int>> dirs =  {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int orangesRotting(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis (n, vector<bool>(m, false));
        queue<pair<int, pair<int, int>>> q;
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 2) {
                    q.push ({0, {i, j}});
                    vis[i][j] = true;
                }
                if (mat[i][j] == 1)
                    cnt++;
            }
        }
        int time = 0, cf = 0;
        while (!q.empty()) {
            int t = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            time = fmax(time, t);
            q.pop();
            for (int i = 0; i < dirs.size(); ++i){
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mat[nr][nc] == 1) {
                    q.push ({t + 1, {nr, nc}});
                    vis[nr][nc] = true;
                    cf++;
                }
            }
        }
        return (cf != cnt) ? - 1 : time;
        
    }
};




-- -- -- -- -- -- -- -- -LeetCode - POTD - 03 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

