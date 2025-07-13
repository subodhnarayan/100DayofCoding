--------------------------------GFG POTD 13/07/2025-------------------------------
Maximum sum of elements not part of LIS
Difficulty: MediumAccuracy: 48.67%Submissions: 16K+Points: 4
Given an array arr[] of positive integers, your task is to find the maximum possible sum of all elements that are not part of the Longest Increasing Subsequence (LIS).

Examples:

Input: arr[] = [4, 6, 1, 2, 3, 8]
Output: 10
Explanation: The elements which are not in LIS is 4 and 6.
Input: arr[] = [5, 4, 3, 2, 1]
Output: 14
Explanation: The elements which are not in LIS is 5, 4, 3 and 2.
Constraints:
1 ≤ arr.size() ≤ 103
1 ≤ arr[i] ≤ 105

Expected Complexities
Time Complexity: O(n log n)
Auxiliary Space: O(n)

class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
         int n = arr.size();
        vector<pair<int, int>> dp (n, {0, 0});
        dp[0].first = 1;
        dp[0].second = arr[0];
        int maxLen = 1;
        int sum = arr[0];
        for(int i = 1; i < n; i++){
            int currLen = 1;
            int currVal = arr[i];
            for(int j = 0; j < i; j++){
                if(arr[j] < arr[i]){
                    int newLen = dp[j].first + 1;
                    if(newLen > currLen){
                        currLen = newLen;
                        currVal = dp[j].second + arr[i];
                    }else if(newLen == currLen){
                        currVal = min(currVal, dp[j].second + arr[i]);
                    }
                }
            }
            dp[i].first = currLen;
            dp[i].second = currVal;
            if(maxLen < currLen){
                maxLen = currLen;
                sum = currVal;
            }else if(maxLen == currLen){
                sum = min(sum, currVal);
            }
        }
        
        
        int totalSum = 0;
        for(auto &e : arr){
            totalSum += e;
        }
        return totalSum - sum;
    }
};


--------------------------------Leetcode POTD 13/07/2025---------------------------

2410. Maximum Matching of Players With Trainers
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.

The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.

Return the maximum number of matchings between players and trainers that satisfy these conditions.

 

Example 1:

Input: players = [4,7,9], trainers = [8,2,5,8]
Output: 2
Explanation:
One of the ways we can form two matchings is as follows:
- players[0] can be matched with trainers[0] since 4 <= 8.
- players[1] can be matched with trainers[3] since 7 <= 8.
It can be proven that 2 is the maximum number of matchings that can be formed.
Example 2:

Input: players = [1,1,1], trainers = [10]
Output: 1
Explanation:
The trainer can be matched with any of the 3 players.
Each player can only be matched with one trainer, so the maximum answer is 1.
 

Constraints:

1 <= players.length, trainers.length <= 105
1 <= players[i], trainers[j] <= 109