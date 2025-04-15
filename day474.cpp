-- -- -- -- -- -- -- -- -GFG - POTD - 14 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Bellman-Ford
Difficulty: MediumAccuracy: 48.11%Submissions: 189K+Points: 4Average Time: 25m
Given an weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.

Your task is to compute the shortest distances from the source to all other vertices. If a vertex is unreachable from the source, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.

Examples:

Input: V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0

Output: [0, 5, 6, 6, 7]
Explanation: Shortest Paths:
For 0 to 1 minimum distance will be 5. By following path 0 → 1
For 0 to 2 minimum distance will be 6. By following path 0 → 1  → 2
For 0 to 3 minimum distance will be 6. By following path 0 → 1  → 2 → 4 → 3 
For 0 to 4 minimum distance will be 7. By following path 0 → 1  → 2 → 4
Input: V = 4, edges[][] = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0

Output: [-1]
Explanation: The graph contains a negative weight cycle formed by the path 1 → 2 → 3 → 1, where the total weight of the cycle is negative.
Constraints:
1 ≤ V ≤ 100
1 ≤ E = edges.size() ≤ V*(V-1)
-1000 ≤ w ≤ 1000
0 ≤ src < V

Expected Complexities
Time Complexity: O(V * E)
Auxiliary Space: O(V)

class Solution {
    public:
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
            vector<int> dist(V,1e8);
          dist[src] = 0;
          for(int i = 0; i < V-1; i++)
          {
              for(auto &it : edges)
              {
                  int u = it[0];
                  int v = it[1];
                  int w = it[2];
                  
                  if(dist[u] != 1e8 and dist[u] + w < dist[v])
                  {
                      dist[v] =  dist[u] + w;     
                  }
                  
              }
          }
          
          for(auto &it : edges)
          {
              int u = it[0];
              int v = it[1];
              int w = it[2];
                  
              if(dist[u] != 1e8 and dist[u] + w < dist[v])
              {
                  return {-1};
              }
                  
          }
          return dist;
      }
  };
-- -- -- -- -- -- -- -- -LeetCode - POTD - 14 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

2179. Count Good Triplets in an Array
Solved
Hard
Topics
Companies
Hint
You are given two 0-indexed arrays nums1 and nums2 of length n, both of which are permutations of [0, 1, ..., n - 1].

A good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2. In other words, if we consider pos1v as the index of the value v in nums1 and pos2v as the index of the value v in nums2, then a good triplet will be a set (x, y, z) where 0 <= x, y, z <= n - 1, such that pos1x < pos1y < pos1z and pos2x < pos2y < pos2z.

Return the total number of good triplets.

 

Example 1:

Input: nums1 = [2,0,1,3], nums2 = [0,1,2,3]
Output: 1
Explanation: 
There are 4 triplets (x,y,z) such that pos1x < pos1y < pos1z. They are (2,0,1), (2,0,3), (2,1,3), and (0,1,3). 
Out of those triplets, only the triplet (0,1,3) satisfies pos2x < pos2y < pos2z. Hence, there is only 1 good triplet.
Example 2:

Input: nums1 = [4,0,1,3,2], nums2 = [4,1,0,2,3]
Output: 4
Explanation: The 4 good triplets are (4,0,3), (4,0,2), (4,1,3), and (4,1,2).
 

Constraints:

n == nums1.length == nums2.length
3 <= n <= 105
0 <= nums1[i], nums2[i] <= n - 1
nums1 and nums2 are permutations of [0, 1, ..., n - 1].

