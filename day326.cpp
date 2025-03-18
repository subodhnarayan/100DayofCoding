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


