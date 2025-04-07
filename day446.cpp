-- -- -- -- -- -- -- -- -GFG - POTD - 07 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Directed Graph Cycle
Difficulty: MediumAccuracy: 27.88%Submissions: 467K+Points: 4
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

Examples:

Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 3]]



Output: true
Explanation: 3 -> 3 is a cycle
Input: V = 3, edges[][] = [[0, 1], [1, 2]]



Output: false
Explanation: no cycle in the graph
Constraints:
1 ≤ V, E ≤ 105

class Solution {
    public:
       bool fun(int i, vector<vector<int>> &adj, vector<bool> &vis1, vector<bool> &vis2){
          vis1[i] = true;
          vis2[i] = true;
          
          for(auto x : adj[i]){
              if(!vis1[x]){
                  if(fun(x, adj, vis1, vis2))
                      return true;
                  
              }
              else if(vis2[x])
                  return true;
          }
          
          vis2[i] = false;
          return false;
      }
      bool isCyclic(int V, vector<vector<int>> &edges) {
          // code here
            vector<vector<int>> adj(V);
          for(auto z : edges){
              adj[z[0]].push_back(z[1]);
          }
          
          vector<bool> vis1(V, false);
          vector<bool> vis2(V, false);
          
          for(int i=0;i<V;i++){
              if(!vis1[i] && fun(i, adj, vis1, vis2))
                  return true;
              
          }
          return false;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 07 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------



