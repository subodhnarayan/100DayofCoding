-- -- -- -- -- -- -- -- -GFG - POTD - 08 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Bridge edge in a graph
Difficulty: MediumAccuracy: 34.61%Submissions: 63K+Points: 4
Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u,v] represents the edge between the vertices u and v. Determine whether a specific edge between two vertices (c, d) is a bridge.

Note:

An edge is called a bridge if removing it increases the number of connected components of the graph.
if there’s only one path between c and d (which is the edge itself), then that edge is a bridge.
Examples :

Input:

c = 1, d = 2
Output: true
Explanation: From the graph, we can clearly see that blocking the edge 1-2 will result in disconnection of the graph.
Hence, it is a Bridge.
Input:

c = 0, d = 2
Output: false
Explanation:

Blocking the edge between nodes 0 and 2 won't affect the connectivity of the graph.
So, it's not a Bridge Edge. All the Bridge Edges in the graph are marked with a blue line in the above image.
Constraints:
1 ≤ V, E ≤ 105
0 ≤ c, d ≤ V-1



class Solution {
    public:
    void dfs(int node,vector<int>adj[],int c, int d,vector<int>&vis){
          vis[node]=true;
          for(auto it:adj[node]){
              if(!vis[it] && !(node==c && it==d)){
                  dfs(it,adj,c,d,vis);
              }
          }
      }
      bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
          // Code here
          vector<int>adj[V];
          for(int i=0;i<edges.size();i++){
              int u=edges[i][0];
              int v=edges[i][1];
              adj[u].push_back(v);
              adj[v].push_back(u);
          }
          vector<int>vis(V,0);
          dfs(c,adj,c,d,vis);
          if(vis[d]) return false;
          return true;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 08 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------



3396. Minimum Number of Operations to Make Elements in Array Distinct
Solved
Easy
Topics
Companies
Hint
You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following operation any number of times:

Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.
Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in the array distinct.

 

Example 1:

Input: nums = [1,2,3,4,2,3,3,5,7]

Output: 2

Explanation:

In the first operation, the first 3 elements are removed, resulting in the array [4, 2, 3, 3, 5, 7].
In the second operation, the next 3 elements are removed, resulting in the array [3, 5, 7], which has distinct elements.
Therefore, the answer is 2.

Example 2:

Input: nums = [4,5,6,4,4]

Output: 2

Explanation:

In the first operation, the first 3 elements are removed, resulting in the array [4, 4].
In the second operation, all remaining elements are removed, resulting in an empty array.
Therefore, the answer is 2.

Example 3:

Input: nums = [6,7,8,9]

Output: 0

Explanation:

The array already contains distinct elements. Therefore, the answer is 0.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100


class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            vector<bool> seen(128);
            for(int i=nums.size()-1;i>=0;i--){
                if(seen[nums[i]]){
                    return i/3+1;
                }
                seen[nums[i]]=true;
            }
            return 0;
        }
    };