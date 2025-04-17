-- -- -- -- -- -- -- -- -GFG - POTD - 17 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Difficulty: HardAccuracy: 62.05%Submissions: 10K+Points: 8
Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents the edge between the nodes u and v having w edge weight.
Your task is to find the minimum weight cycle in this graph.

Examples:

Input: V = 5, edges[][] = [[0, 1, 2], [1, 2, 2], [1, 3, 1], [1, 4, 1], [0, 4, 3], [2, 3, 4]]

Output: 6
Explanation: 

Minimum-weighted cycle is  0 → 1 → 4 → 0 with a total weight of 6(2 + 1 + 3)
Input: V = 5, edges[][] = [[0, 1, 3], [1, 2, 2], [0, 4, 1], [1, 4, 2], [1, 3, 1], [3, 4, 2], [2, 3, 3]]

Output: 5
Explanation: 

Minimum-weighted cycle is  1 → 3 → 4 → 1 with a total weight of 5(1 + 2 + 2)
Constraints:
1 ≤ V ≤ 100
1 ≤ E = edges.size() ≤ 103 
1 ≤ edges[i][j] ≤ 100

Expected Complexities
Time Complexity: O(E * (V + E) log V)
Auxiliary Space: O(V + E)
  
class Solution {
    public:
      int dijkstra(int src, int dest, int V, vector<vector<int>>adj[]){
          vector<int>dist(V, 1e9);
          priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
          pq.push({0, src});
          dist[src]=0;
          while(!pq.empty()){
              auto &it=pq.top();
              int node=it.second;
              int d=it.first;
              pq.pop();
              
              for(auto& it:adj[node]){
                  int adjN=it[0];
                  int adjW=it[1];
                  if((node==src && adjN==dest) || (node==dest && adjN==src)) continue;
                  if(d+adjW<dist[adjN]){
                      dist[adjN]=d+adjW;
                      pq.push({dist[adjN], adjN});
                  }
              }
          }
          
          return dist[dest];
      }
      int findMinCycle(int V, vector<vector<int>>& edges) {
          // code here
           vector<vector<int>>adj[V];
          for(auto &it:edges){
              int u=it[0];
              int v=it[1];
              int w=it[2];
              adj[u].push_back({v, w});
              adj[v].push_back({u, w});
          }
          
          int mini=1e9;
          
          for(int i=0; i<edges.size(); i++){
              int dist=(dijkstra(edges[i][0], edges[i][1], V, adj));
              if(dist!=1e9){
                  mini=min(mini, dist+edges[i][2]);
              }
          }
          
          return mini;
          
      }
  };

-- -- -- -- -- -- -- -- -Leetcode - POTD - 17 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

2176. Count Equal and Divisible Pairs in an Array
Solved
Easy
Topics
Companies
Hint
Given a 0-indexed integer array nums of length n and an integer k, return the number of pairs (i, j) where 0 <= i < j < n, such that nums[i] == nums[j] and (i * j) is divisible by k.
 

Example 1:

Input: nums = [3,1,2,2,2,1,3], k = 2
Output: 4
Explanation:
There are 4 pairs that meet all the requirements:
- nums[0] == nums[6], and 0 * 6 == 0, which is divisible by 2.
- nums[2] == nums[3], and 2 * 3 == 6, which is divisible by 2.
- nums[2] == nums[4], and 2 * 4 == 8, which is divisible by 2.
- nums[3] == nums[4], and 3 * 4 == 12, which is divisible by 2.
Example 2:

Input: nums = [1,2,3,4], k = 1
Output: 0
Explanation: Since no value in nums is repeated, there are no pairs (i,j) that meet all the requirements.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i], k <= 100

class Solution {
    public:
        int countPairs(vector<int>& nums, int k) {
            int n=nums.size();
            int count=0;
            for(int i=0;i<n-1;i++){
                for(int j=i+1;j<n;j++){
                    if(nums[i]==nums[j] && (i*j==0 || (i*j)%k==0)){
                        count++;
                    }
                }
            }
            return count;
        }
};