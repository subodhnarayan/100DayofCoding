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


3375. Minimum Operations to Make Array Values Equal to K
Solved
Easy
Topics
Companies
Hint
You are given an integer array nums and an integer k.

An integer h is called valid if all values in the array that are strictly greater than h are identical.

For example, if nums = [10, 8, 10, 8], a valid integer is h = 9 because all nums[i] > 9 are equal to 10, but 5 is not a valid integer.

You are allowed to perform the following operation on nums:

Select an integer h that is valid for the current values in nums.
For each index i where nums[i] > h, set nums[i] to h.
Return the minimum number of operations required to make every element in nums equal to k. If it is impossible to make all elements equal to k, return -1.

 

Example 1:

Input: nums = [5,2,5,4,5], k = 2

Output: 2

Explanation:

The operations can be performed in order using valid integers 4 and then 2.

Example 2:

Input: nums = [2,1,2], k = 2

Output: -1

Explanation:

It is impossible to make all the values equal to 2.

Example 3:

Input: nums = [9,7,5,3], k = 1

Output: 4

Explanation:

The operations can be performed using valid integers in the order 7, 5, 3, and 1.

 

Constraints:

1 <= nums.length <= 100 
1 <= nums[i] <= 100
1 <= k <= 100


class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
             unordered_set<int> st;
            for (int x : nums) {
                if (x < k) {
                    return -1;
                } else if (x > k) {
                    st.insert(x);
                }
            }
            return st.size();
        }
};





