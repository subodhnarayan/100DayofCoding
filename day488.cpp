-- -- -- -- -- -- -- -- -GFG - POTD - 30 / 04 / 2025 -----------------------------------




-- -- -- -- -- -- -- -- -Leetcode - POTD - 30 / 04 / 2025 -----------------------------------

2962. Count Subarrays Where Max Element Appears at Least K Times
Solved
Medium
Topics
Companies
You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105



class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
             int maxElement = *max_element(nums.begin(), nums.end());
            vector<int> indexesOfMaxElements;
            long long ans = 0;
    
            for (int index = 0; index < nums.size(); index++) {
                if (nums[index] == maxElement) {
                    indexesOfMaxElements.push_back(index);
                }
    
                int freq = indexesOfMaxElements.size();
                if (freq >= k) {
                    ans += indexesOfMaxElements[freq - k] + 1;
                }
            }
    
            return ans;
        }
};
