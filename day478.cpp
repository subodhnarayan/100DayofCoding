-- -- -- -- -- -- -- -- -GFG - POTD - 19 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
Maximum XOR of two numbers in an array
Difficulty: MediumAccuracy: 50.0%Submissions: 19K+Points: 4
Given an array arr[] of non-negative integers of size n. Find the maximum possible XOR between two numbers present in the array.

Examples:

Input: arr[] = [25, 10, 2, 8, 5, 3]
Output: 28
Explanation: The maximum possible XOR is 5 ^ 25 = 28.
Input: arr[] = [1, 2, 3, 4, 5, 6, 7]
Output: 7
Explanation : The maximum possible XOR is 1 ^ 6 = 7.
Constraints:
2 ≤ arr.size() ≤ 5*104
1 ≤ arr[i] ≤ 106



-- -- -- -- -- -- -- -- -Leetcode - POTD - 19 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
2563. Count the Number of Fair Pairs
Solved
Medium
Topics
Companies
Hint
Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.

A pair (i, j) is fair if:

0 <= i < j < n, and
lower <= nums[i] + nums[j] <= upper
 

Example 1:

Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
Output: 6
Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
Example 2:

Input: nums = [1,7,9,2,5], lower = 11, upper = 11
Output: 1
Explanation: There is a single fair pair: (2,3).
 

Constraints:

1 <= nums.length <= 105
nums.length == n
-109 <= nums[i] <= 109
-109 <= lower <= upper <= 109

class Solution {
    public:
        long long countFairPairs(vector<int>& v, int lower, int upper) {
            long long ans = 0;
            sort(v.begin(), v.end());
    
            for (int i = 0; i < v.size() - 1; i++) {
                auto up = upper_bound(v.begin() + i + 1, v.end(), upper - v[i]);
                auto low = lower_bound(v.begin() + i + 1, v.end(), lower - v[i]);
                ans += (up - low);
            }
            return ans;
        }
};