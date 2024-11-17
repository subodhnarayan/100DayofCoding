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