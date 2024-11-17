-- -- -- -- -- -- -- -- -GFG - POTD - 17 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Reverse an Array
Difficulty: EasyAccuracy: 55.32%Submissions: 59K+Points: 2
You are given an array of integers arr[]. Your task is to reverse the given array.

Examples:

Input: arr = [1, 4, 3, 2, 6, 5]
Output: [5, 6, 2, 3, 4, 1]
Explanation: The elements of the array are 1 4 3 2 6 5. After reversing the array, the first element goes to the last position, the second element goes to the second last position and so on. Hence, the answer is 5 6 2 3 4 1.
Input: arr = [4, 5, 2]
Output: [2, 5, 4]
Explanation: The elements of the array are 4 5 2. The reversed array will be 2 5 4.
Input: arr = [1]
Output: [1]
Explanation: The array has only single element, hence the reversed array is same as the original.
Constraints:
1<=arr.size()<=105
0<=arr[i]<=105

class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int n=arr.size();
        int start=0;
        int end=n-1;
        while(start<end){
            int temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 17 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- --

862. Shortest Subarray with Sum at Least K
Solved
Hard
Topics
Companies
Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1], k = 1
Output: 1
Example 2:

Input: nums = [1,2], k = 4
Output: -1
Example 3:

Input: nums = [2,-1,2], k = 3
Output: 3
 

Constraints:

1 <= nums.length <= 105
-105 <= nums[i] <= 105
1 <= k <= 109

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        //brute force approach
        // int ans = INT_MAX;
        // int n = nums.size();
        
        // for (int i = 0; i < n; i++) {
        //     int sum = 0;
        //     for (int j = i; j < n; j++) {
        //         sum += nums[j];
        //         if (sum >= k) {
        //             ans = min(ans, j - i + 1);
        //             break; // Exit inner loop as we found a valid subarray starting at i
        //         }
        //     }
        // }
        
        // return ans == INT_MAX ? -1 : ans;
        //optimized approach

        int n = nums.size();
        vector<long long> culsum(n); // Prefix sum array
        deque<int> deq;             // Monotonic deque
        int ans = INT_MAX;

        // Compute prefix sums and process with deque
        for (int j = 0; j < n; j++) {
            // Compute prefix sum
            culsum[j] = nums[j] + (j > 0 ? culsum[j - 1] : 0);

            // Check if the current prefix sum itself meets the condition
            if (culsum[j] >= k) {
                ans = min(ans, j + 1);
            }

            // Check if any subarray ending at j meets the condition
            while (!deq.empty() && culsum[j] - culsum[deq.front()] >= k) {
                ans = min(ans, j - deq.front());
                deq.pop_front(); // Correctly pop from the front
            }

            // Maintain monotonicity of the deque
            while (!deq.empty() && culsum[j] <= culsum[deq.back()]) {
                deq.pop_back();
            }

            // Push the current index to the deque
            deq.push_back(j);
        }

        // Return the result
        return ans == INT_MAX ? -1 : ans;
    }
};