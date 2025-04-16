-- -- -- -- -- -- -- -- -GFG - POTD - 16 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Floyd Warshall
Difficulty: MediumAccuracy: 32.89%Submissions: 184K+Points: 4Average Time: 15m
You are given an weighted directed graph, represented by an adjacency matrix, dist[][] of size n x n, where dist[i][j] represents the weight of the edge from node i to node j. If there is no direct edge, dist[i][j] is set to a large value (i.e., 108) to represent infinity.
The graph may contain negative edge weights, but it does not contain any negative weight cycles.

Your task is to find the shortest distance between every pair of nodes i and j in the graph.

Note: Modify the distances for every pair in place.

Examples :

Input: dist[][] = [[0, 4, 108, 5, 108], [108, 0, 1, 108, 6], [2, 108, 0, 3, 108], [108, 108, 1, 0, 2], [1, 108, 108, 4, 0]]

Output: [[0, 4, 5, 5, 7], [3, 0, 1, 4, 6], [2, 6, 0, 3, 5], [3, 7, 1, 0, 2], [1, 5, 5, 4, 0]]

Explanation: Each cell dist[i][j] in the output shows the shortest distance from node i to node j, computed by considering all possible intermediate nodes. 
Input: dist[][] = [[0, -1, 2], [1, 0, 108], [3, 1, 0]]

Output: [[0, -1, 2], [1, 0, 3], [2, 1, 0]]

Explanation: Each cell dist[i][j] in the output shows the shortest distance from node i to node j, computed by considering all possible intermediate nodes.
From 2 to 0 shortest distance should be 2 by following path 2 -> 1 -> 0
From 1 to 2 shortest distance should be 3 by following path 1 -> 0 -> 2
Constraints:
1 ≤ dist.size() ≤ 100
-1000 ≤ dist[i][j] ≤ 1000

Expected Complexities
Time Complexity: O(n^3)
Auxiliary Space: O(1)

class Solution {
    public:
      void floydWarshall(vector<vector<int>> &dist) {
          // Code here
             int n = dist.size();
          const int INF = 1e8;
  
          for (int k = 0; k < n; ++k) {
              for (int i = 0; i < n; ++i) {
                  for (int j = 0; j < n; ++j) {
                      if (dist[i][k] < INF && dist[k][j] < INF) {
                          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                      }
                  }
              }
          }
      }
  };

  

-- -- -- -- -- -- -- -- -Leetcode - POTD - 16 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

2537. Count the Number of Good Subarrays
Solved
Medium
Topics
Companies
Hint
Given an integer array nums and an integer k, return the number of good subarrays of nums.

A subarray arr is good if there are at least k pairs of indices (i, j) such that i < j and arr[i] == arr[j].

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,1,1,1,1], k = 10
Output: 1
Explanation: The only good subarray is the array nums itself.
Example 2:

Input: nums = [3,1,4,3,2,2,4], k = 2
Output: 4
Explanation: There are 4 different good subarrays:
- [3,1,4,3,2,2] that has 2 pairs.
- [3,1,4,3,2,2,4] that has 3 pairs.
- [1,4,3,2,2,4] that has 2 pairs.
- [4,3,2,2,4] that has 2 pairs.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i], k <= 109

class Solution {
    public:
        long long countGood(vector<int>& nums, int k) {
            int n = nums.size();
            int same = 0, right = -1;
            unordered_map<int, int> cnt;
            long long ans = 0;
            for (int left = 0; left < n; ++left) {
                while (same < k && right + 1 < n) {
                    ++right;
                    same += cnt[nums[right]];
                    ++cnt[nums[right]];
                }
                if (same >= k) {
                    ans += n - right;
                }
                --cnt[nums[left]];
                same -= cnt[nums[left]];
            }
            return ans;
        }
};