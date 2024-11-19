-- -- -- -- -- -- -- -- -GFG - POTD - 19 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Next Permutation
Difficulty: MediumAccuracy: 40.66%Submissions: 156K+Points: 4
Given an array of integers arr[] representing a permutation, implement the next permutation that rearranges the numbers into the lexicographically next greater permutation. If no such permutation exists, rearrange the numbers into the lowest possible order (i.e., sorted in ascending order). 

Note - A permutation of an array of integers refers to a specific arrangement of its elements in a sequence or linear order.

Examples:

Input: arr = [2, 4, 1, 7, 5, 0]
Output: [2, 4, 5, 0, 1, 7]
Explanation: The next permutation of the given array is {2, 4, 5, 0, 1, 7}.
Input: arr = [3, 2, 1]
Output: [1, 2, 3]
Explanation: As arr[] is the last permutation, the next permutation is the lowest one.
Input: arr = [3, 4, 2, 5, 1]
Output: [3, 4, 5, 1, 2]
Explanation: The next permutation of the given array is {3, 4, 5, 1, 2}.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        //next_permutation(arr.begin(), arr.end());
         int n=arr.size();
        if(n==1)return;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                int ele = arr[i];
                int idx=i;
                int k = INT_MAX;
                for(int j=i+1;j<n;j++){
                    if(arr[j]<k and arr[j]>arr[i]){
                        k=arr[j];
                        idx = j;
                    }
                }
                swap(arr[i],arr[idx]);
                sort(arr.begin()+i+1, arr.end());
                
                return;
            }
        }
        sort(arr.begin(), arr.end());
    }
};



-- -- -- -- -- -- -- -- -GFG - POTD - 19 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

2461. Maximum Sum of Distinct Subarrays With Length K
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
 

Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 105


