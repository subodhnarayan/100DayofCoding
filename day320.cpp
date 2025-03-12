-- -- -- -- -- -- -- -- -GFG - POTD - 12 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
Min Cost Climbing Stairs
Difficulty: MediumAccuracy: 50.04%Submissions: 27K+Points: 4
Given an array of integers cost[] where cost[i] is the cost of the ith step on a staircase. Once the cost is paid, you can either climb one or two steps. Return the minimum cost to reach the top of the floor.
Assume 0-based Indexing. You can either start from the step with index 0, or the step with index 1.

Examples:

Input: cost[] = [10, 15, 20]
Output: 15
Explanation: Cheapest option is to start at cost[1], pay that cost, and go to the top.



Input: cost[] = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest option is to start on cost[0], and only step on 1s, skipping cost[3].


Constraints:
2 ≤ cost.size() ≤ 105
0 ≤ cost[i] ≤ 999

class Solution {
    public:
    int helper(int i,int n,vector<int>&cost,vector<int>&dp){
          if(i>=n) return 0;
          //pay and take the one step
          if(dp[i]!=-1) return dp[i];
          int onestep=cost[i]+helper(i+1,n,cost,dp);
          //pay and take two step
          int twostep=cost[i]+helper(i+2,n,cost,dp);
          
          return dp[i]=min(onestep,twostep);
          
      }
      int minCostClimbingStairs(vector<int>& cost) {
          // Write your code here
          int n=cost.size();
          vector<int>dp(n,-1);
          //in question is given that the it can either start from 0 index or from 1 index
          return min(helper(0,n,cost,dp),helper(1,n,cost,dp));
      }
  };

-- -- -- -- -- -- -- -- -LeetCode - POTD - 12 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


2529. Maximum Count of Positive Integer and Negative Integer
Solved
Easy
Topics
Companies
Hint
Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.

In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
Note that 0 is neither positive nor negative.

 

Example 1:

Input: nums = [-2,-1,-1,1,2,3]
Output: 3
Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
Example 2:

Input: nums = [-3,-2,-1,0,0,1,2]
Output: 3
Explanation: There are 2 positive integers and 3 negative integers. The maximum count among them is 3.
Example 3:

Input: nums = [5,20,66,1314]
Output: 4
Explanation: There are 4 positive integers and 0 negative integers. The maximum count among them is 4.
 

Constraints:

1 <= nums.length <= 2000
-2000 <= nums[i] <= 2000
nums is sorted in a non-decreasing order.
 

Follow up: Can you solve the problem in O(log(n)) time complexity?