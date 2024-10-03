-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 03 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Majority Vote
Difficulty: MediumAccuracy: 48.1%Submissions: 58K+Points: 4
You are given an array of integer nums[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return -1. 

Note: The answer should be returned in an increasing format.

Examples:

Input: nums = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more n/3 times.
Input: nums = [1, 2, 3, 4, 5]
Output: [-1]
Explanation: no candidate occur more than n/3 times.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraint:
1 <= nums.size() <= 106
0 <= nums[i] <= 109


class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
       unordered_map<int ,int>m;
        for(auto &i:nums)
            m[i]++;
        vector<int>ans;
        int n=nums.size();
        for(auto &i:m)
            if(i.second>n/3)
                ans.emplace_back(i.first);
        sort(ans.begin(),ans.end());
        if(ans.size()==0)
            ans.emplace_back(-1);
        return ans;         
    }
};



-- -- -- -- -- -- -- -- -- -- -- -- -- Leetcode - POTD - 04 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

1590. Make Sum Divisible by P
Solved
Medium
Topics
Companies
Hint
Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.

 

Example 1:

Input: nums = [3,1,4,2], p = 6
Output: 1
Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
Example 2:

Input: nums = [6,3,5,2], p = 9
Output: 2
Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.
Example 3:

Input: nums = [1,2,3], p = 3
Output: 0
Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= p <= 109


class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
         long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // Find the remainder when total sum is divided by p
        int rem = totalSum % p;
        if (rem == 0) return 0; // If the remainder is 0, no subarray needs to be removed

        unordered_map<int, int> prefixMod;
        prefixMod[0] = -1;  // Initialize for handling full prefix
        long prefixSum = 0;
        int minLength = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            int currentMod = prefixSum % p;
            int targetMod = (currentMod - rem + p) % p;

            if (prefixMod.find(targetMod) != prefixMod.end()) {
                minLength = min(minLength, i - prefixMod[targetMod]);
            }

            prefixMod[currentMod] = i;
        }

        return minLength == nums.size() ? -1 : minLength;
    }
};
