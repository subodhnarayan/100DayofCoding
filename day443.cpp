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


1123. Lowest Common Ancestor of Deepest Leaves
Solved
Medium
Topics
Companies
Hint
Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.

Recall that:

The node of a binary tree is a leaf if and only if it has no children
The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.
 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]
Explanation: We return the node with value 2, colored in yellow in the diagram.
The nodes coloured in blue are the deepest leaf-nodes of the tree.
Note that nodes 6, 0, and 8 are also leaf nodes, but the depth of them is 2, but the depth of nodes 7 and 4 is 3.
Example 2:

Input: root = [1]
Output: [1]
Explanation: The root is the deepest node in the tree, and it's the lca of itself.
Example 3:

Input: root = [0,1,3,null,2]
Output: [2]
Explanation: The deepest leaf node in the tree is 2, the lca of one node is itself.
 

Constraints:

The number of nodes in the tree will be in the range [1, 1000].
0 <= Node.val <= 1000
The values of the nodes in the tree are unique.
 

