-- -- -- -- -- -- -- -- -GFG - POTD - 09 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Articulation Point - II
Difficulty: HardAccuracy: 55.15%Submissions: 22K+Points: 8Average Time: 30m
You are given an undirected graph with V vertices and E edges. The graph is represented as a 2D array edges[][], where each element edges[i] = [u, v] indicates an undirected edge between vertices u and v.
Your task is to return all the articulation points (or cut vertices) in the graph.
An articulation point is a vertex whose removal, along with all its connected edges, increases the number of connected components in the graph.

Note: The graph may be disconnected, i.e., it may consist of more than one connected component.
If no such point exists, return {-1}.

Examples :

Input: V = 5, edges[][] = [[0, 1], [1, 4], [4, 3], [4, 2], [2, 3]]

Output: [1, 4]
Explanation: Removing the vertex 1 or 4 will disconnects the graph as-
   
Input: V = 4, edges[][] = [[0, 1], [0, 2]]
Output: [0]
Explanation: Removing the vertex 0 will increase the number of disconnected components to 3.  
Constraints:
1 ≤ V, E ≤ 104


class Solution {
    public:
       void dfs(int u, int parent, vector<int> adj[], vector<bool> &visited,
               vector<int> &disc, vector<int> &low, vector<int> &isAP, int &timer) {
          
          visited[u] = true;
          disc[u] = low[u] = timer++;
          int children = 0;
  
          for (int v : adj[u]) {
              if (v == parent) continue;
  
              if (!visited[v]) {
                  dfs(v, u, adj, visited, disc, low, isAP, timer);
                  low[u] = min(low[u], low[v]);
  
                  if (parent != -1 && low[v] >= disc[u]) {
                      isAP[u] = 1;
                  }
                  children++;
              } else {
                  // back edge
                  low[u] = min(low[u], disc[v]);
              }
          }
  
          if (parent == -1 && children > 1) {
              isAP[u] = 1;
          }
      }
      vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
          // Code here
           vector<int> adj[V];
          for (auto &e : edges) {
              adj[e[0]].push_back(e[1]);
              adj[e[1]].push_back(e[0]);
          }
  
          vector<bool> visited(V, false);
          vector<int> disc(V, -1), low(V, -1), isAP(V, 0);
          int timer = 0;
  
          for (int i = 0; i < V; i++) {
              if (!visited[i]) {
                  dfs(i, -1, adj, visited, disc, low, isAP, timer);
              }
          }
  
          vector<int> res;
          for (int i = 0; i < V; i++) {
              if (isAP[i]) res.push_back(i);
          }
  
          if (res.empty()) return {-1};
          return res;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 10 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


