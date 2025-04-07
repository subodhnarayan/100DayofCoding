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



416. Partition Equal Subset Sum
Solved
Medium
Topics
Companies
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100


class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int totalSum = 0;
            for (int num : nums) totalSum += num;
    
            if (totalSum % 2 != 0) return false;
    
            int targetSum = totalSum / 2;
            vector<bool> dp(targetSum + 1, false);
            dp[0] = true;
            for (int num : nums) {
                for (int currSum = targetSum; currSum >= num; --currSum) {
                    dp[currSum] = dp[currSum] || dp[currSum - num];
                    if (dp[targetSum]) return true;
                }
            }
            return dp[targetSum];
        }
 };