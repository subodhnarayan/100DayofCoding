-- -- -- -- -- -- -- -- -GFG - POTD - 04 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Undirected Graph Cycle
Difficulty: MediumAccuracy: 30.13%Submissions: 548K+Points: 4Average Time: 20m
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V ≤ 105
1 ≤ E = edges.size() ≤ 105

Time Complexity: O(V + E)Auxiliary Space: O(V)

class Solution {
    public:
      bool isCycle(int V, vector<vector<int>>& edges) {
          // Code here
           vector<vector<int>> adj(V);
          vector<bool> visited(V, false);        
          visited[0] = true;
          
          for(auto &i : edges) {
              int u = i[0], v = i[1];
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
              
          function<bool(int, int)> dfs = [&](int curr, int prev) -> bool {
              bool res = false;
              for(auto i : adj[curr]) {
                  if(i != prev && visited[i] == true) return true;
                  else if(i != prev) {
                      visited[i] = true;
                      res |= dfs(i, curr);
                      if(res) return res;
                  }
              }
              return res;
          };
          
          return dfs(0, -1);
      }
  };



-- -- -- -- -- -- -- -- -LeetCode - POTD - 04 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


