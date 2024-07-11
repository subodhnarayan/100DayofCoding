//GFG POTD 11/7/2024
// Maximum Connected group
// Difficulty: HardAccuracy: 49.48%Submissions: 34K+Points: 8
// You are given a square binary grid. A grid is considered binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1's. Two cells are said to be connected if both are adjacent(top, bottom, left, right) to each other and both have the same value.

// Examples :

// Input: grid = [1, 1]
//              [0, 1]
// Output: 4
// Explanation: By changing cell (2,1), we can obtain a connected group of 4 1's
// [1, 1]
// [1, 1]
// Input: grid = [1, 0, 1]
//              [1, 0, 1]
//              [1, 0, 1]
// Output: 7
// Explanation: By changing cell (3,2), we can obtain a connected group of 7 1's
// [1, 0, 1]
// [1, 0, 1]
// [1, 1, 1]
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 <= size of the grid<= 500
// 0 <= grid[i][j] <= 1



class Solution {
  public:
  unordered_map<int, int> unmap;
 
// Depth-first search (DFS) function to calculate
// the size of an island.
int dfs(int i, int j, vector<vector<int> >& grid,
        vector<vector<bool> >& visited, int key)
{
    int n = grid.size();
 
    // Base cases: Check for boundaries,
    // visited status, and water (grid[i][j] == 0).
    if (i < 0 || j < 0 || i >= n || j >= n || visited[i][j]
        || grid[i][j] == 0) {
        return 0;
    }
 
    // Mark the current cell as visited.
    visited[i][j] = true;
 
    // Recursively explore adjacent cells and
    // accumulate the island size.
    int count = 1 + dfs(i + 1, j, grid, visited, key)
                + dfs(i - 1, j, grid, visited, key)
                + dfs(i, j + 1, grid, visited, key)
                + dfs(i, j - 1, grid, visited, key);
 
    // Update the cell's value to the key
    // representing the island.
    grid[i][j] = key;
    return count;
}
  
    int MaxConnection(vector<vector<int>>& grid) {
         int n = grid.size();
    int key = 2;
    vector<vector<bool> > visited(n,
                                vector<bool>(n, false));
 
    // Traverse the grid to identify and mark
    // islands, and store their sizes in the map.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == false && grid[i][j] == 1) {
                int count = dfs(i, j, grid, visited, key);
 
                // Store island size in the map.
                unmap[key] = count;
                key++;
            }
        }
    }
 
    int result = -1;
    vector<vector<bool> > visited2(n,
                                vector<bool>(n, false));
 
    // Traverse the grid again to identify water
    // cells and calculate the largest
    // possible island.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
 
                // Check adjacent cells and
                // gather island sizes from the map.
                int a = (i + 1 < n) ? grid[i + 1][j] : 0;
                int b = (i - 1 >= 0) ? grid[i - 1][j] : 0;
                int c = (j + 1 < n) ? grid[i][j + 1] : 0;
                int d = (j - 1 >= 0) ? grid[i][j - 1] : 0;
 
                // Store unique island sizes
                // around the current water cell.
                set<int> st;
                st.insert(a);
                st.insert(b);
                st.insert(c);
                st.insert(d);
 
                int res = 1;
 
                // Calculate the combined size
                // of neighboring islands.
                for (auto it = st.begin(); it != st.end();
                    it++) {
                    res += unmap[*it];
                }
 
                // Update the largest island size.
                result = max(result, res);
            }
        }
    }
 
    // If no land cells were present (only water),
    // return the size of the entire grid.
    if (result == -1) {
        return n * n;
    }
    return result;
    }
};