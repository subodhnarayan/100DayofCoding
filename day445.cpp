-- -- -- -- -- -- -- -- -GFG - POTD - 06 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Topological sort
Difficulty: MediumAccuracy: 56.52%Submissions: 278K+Points: 4Average Time: 15m
Given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], where each entry edges[i] = [u, v] denotes an directed edge u -> v. Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

Examples:

Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]
Constraints:
2  ≤  V  ≤  103
1  ≤  E = edges.size()  ≤  (V * (V - 1)) / 2


class Solution {
    public:
      vector<int> topoSort(int V, vector<vector<int>>& edges) {
          // code here
          vector<int>ans;
          
          vector<int>deg(V + 1, 0);
          vector<vector<int>>graf(V);
          for(auto i : edges){
              graf[i[0]].push_back(i[1]);
              deg[i[1]]++;
          }
          queue<int>q;
          for(int i = 0; i < V; i++){
              if(deg[i] == 0){
                  q.push(i);
                  ans.push_back(i);
                  deg[i] = -1;
              }
          }
          while(!q.empty()){
              int f = q.front();
              q.pop();
              
              for(auto i : graf[f]){
                  deg[i]--;
                  
                  if(deg[i] == 0){
                      deg[i] = -1;
                      q.push(i);
                      ans.push_back(i);
                  }
              }
          }
          return ans;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 06 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


368. Largest Divisible Subset
Solved
Medium
Topics
Companies
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

 

Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.

