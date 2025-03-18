-- -- -- -- -- -- -- -- -GFG - POTD - 18 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Partition Equal Subset Sum
Difficulty: MediumAccuracy: 30.24%Submissions: 259K+Points: 4
Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.

Note: Each element must be in exactly one subset.

Examples:

Input: arr = [1, 5, 11, 5]
Output: true
Explanation: The two parts are [1, 5, 5] and [11].
Input: arr = [1, 3, 5]
Output: false
Explanation: This array can never be partitioned into two such parts.
Constraints:
1 ≤ arr.size ≤ 100
1 ≤ arr[i] ≤ 200

class Solution {
    public:
      bool equalPartition(vector<int>& arr) {
          // code here
          int N=arr.size();
           long int sum=0;
          for(int i=0;i<N;i++)
          {
              sum=sum+arr[i];
          }
          if(sum%2!=0)
          return false;
       long long targetSum = sum / 2;
  
          // Create a 2D array manually
          bool dp[N + 1][targetSum + 1];
  
          // Initialize the first row
          for (int j = 0; j <= targetSum; j++) {
              dp[0][j] = false;
          }
  
          // Initialize the first column
          for (int i = 0; i <= N; i++) {
              dp[i][0] = true;
          }
  
          // Fill the DP table
          for (int i = 1; i <= N; i++) {
              for (int j = 1; j <= targetSum; j++) {
                  if (arr[i - 1] > j) {
                      dp[i][j] = dp[i - 1][j];
                  } else {
                      dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                  }
              }
          }
  
          return dp[N][targetSum];
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 18 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


2401. Longest Nice Subarray
Medium
Topics
Companies
Hint
You are given an array nums consisting of positive integers.

We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.

Return the length of the longest nice subarray.

A subarray is a contiguous part of an array.

Note that subarrays of length 1 are always considered nice.

 

Example 1:

Input: nums = [1,3,8,48,10]
Output: 3
Explanation: The longest nice subarray is [3,8,48]. This subarray satisfies the conditions:
- 3 AND 8 = 0.
- 3 AND 48 = 0.
- 8 AND 48 = 0.
It can be proven that no longer nice subarray can be obtained, so we return 3.
Example 2:

Input: nums = [3,1,5,11,13]
Output: 1
Explanation: The length of the longest nice subarray is 1. Any subarray of length 1 can be chosen.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
