-- -- -- -- -- -- -- -- -GFG - POTD - 02 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Count Subarrays with given XOR
Difficulty: MediumAccuracy: 58.86%Submissions: 21K+Points: 4
Given an array of integers arr[] and a number k, count the number of subarrays having XOR of their elements as k.

Examples: 

Input: arr[] = [4, 2, 2, 6, 4], k = 6
Output: 4
Explanation: The subarrays having XOR of their elements as 6 are [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], and [6]. Hence, the answer is 4.
Input: arr[] = [5, 6, 7, 8, 9], k = 5
Output: 2
Explanation: The subarrays having XOR of their elements as 5 are [5] and [5, 6, 7, 8, 9]. Hence, the answer is 2.
Input: arr[] = [1, 1, 1, 1], k = 0
Output: 4
Explanation: The subarrays are [1, 1], [1, 1], [1, 1] and [1, 1, 1, 1].
Constraints:

1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤105
0 ≤ k ≤ 105

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
         unordered_map<int,int>mp;

        int preXor=0,count=0;

        for(int i=0;i<arr.size();i++){

            preXor^=arr[i];

            if(preXor==k) count++;

            if(mp.find(preXor^k)!=mp.end()) count+=mp[preXor^k];

            mp[preXor]++;

        }

        return count;
    }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 02 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
2270. Number of Ways to Split Array
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums of length n.

nums contains a valid split at index i if the following are true:

The sum of the first i + 1 elements is greater than or equal to the sum of the last n - i - 1 elements.
There is at least one element to the right of i. That is, 0 <= i < n - 1.
Return the number of valid splits in nums.

 

Example 1:

Input: nums = [10,4,-8,7]
Output: 2
Explanation: 
There are three ways of splitting nums into two non-empty parts:
- Split nums at index 0. Then, the first part is [10], and its sum is 10. The second part is [4,-8,7], and its sum is 3. Since 10 >= 3, i = 0 is a valid split.
- Split nums at index 1. Then, the first part is [10,4], and its sum is 14. The second part is [-8,7], and its sum is -1. Since 14 >= -1, i = 1 is a valid split.
- Split nums at index 2. Then, the first part is [10,4,-8], and its sum is 6. The second part is [7], and its sum is 7. Since 6 < 7, i = 2 is not a valid split.
Thus, the number of valid splits in nums is 2.
Example 2:

Input: nums = [2,3,1,0]
Output: 2
Explanation: 
There are two valid splits in nums:
- Split nums at index 1. Then, the first part is [2,3], and its sum is 5. The second part is [1,0], and its sum is 1. Since 5 >= 1, i = 1 is a valid split. 
- Split nums at index 2. Then, the first part is [2,3,1], and its sum is 6. The second part is [0], and its sum is 0. Since 6 >= 0, i = 2 is a valid split.
 

Constraints:

2 <= nums.length <= 105
-105 <= nums[i] <= 105


class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        // Prefix sum array to store cumulative sums
        vector<long long> prefSum(n);
        prefSum[0] = nums[0];

        // Build prefix sum array
        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + nums[i];
        }

        int count = 0;
        // Check each possible split position
        for (int i = 0; i < n - 1; i++) {
            // Sum of left part (0 to i)
            long long leftSum = prefSum[i];
            // Sum of right part (i+1 to n-1)
            long long rightSum = prefSum[n - 1] - prefSum[i];

            if (leftSum >= rightSum) {
                count++;
            }
        }

        return count;
    }
};
