
-- -- -- -- -- -- -- -- -Leetcode - POTD - 24 / 04 / 2025 -----------------------------------
Unique Number III
Difficulty: MediumAccuracy: 49.87%Submissions: 60K+Points: 4Average Time: 20m
Given an array of integers arr[] where, every element appears thrice except for one which occurs once.
Find that element which occurs once.

Examples:

Input: arr[] = [1, 10, 1, 1]
Output: 10
Explanation: 10 occurs once in the array while the other element 1 occurs thrice.
Input: arr[] = [3, 2, 1, 34, 34, 1, 2, 34, 2, 1]
Output: 3
Explanation: All elements except 3 occurs thrice in the array.
Constraints:
1 ≤ arr.size() ≤ 105
arr.size() % 3 = 1
-109 ≤ arr[i] ≤ 109

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

class Solution {
    public:
      bool checkbit(int x, int i){
           return ((x >> i) & 1) == 1;
      }
      int ans = 0;
      int getSingle(vector<int> &arr) {
          // code here
          //brute force approach tc=0(n) and sc=0(n)
          // unordered_map<int,int> mp;
          // for(int ele:arr){
          //     mp[ele]++;
          // }
          // for(auto ele:mp){
          //     if(ele.second==1){
          //         return ele.first;
          //     }
          // }
          // return 0;
          
             for(int i = 0; i <= 31; i++){
              int count = 0;
              for(int j = 0; j < arr.size(); j++){
                  if(checkbit(arr[j], i)){
                      count  = count +1;
                  }
              }
              if(count % 3 == 1){
                  ans = ans + (1 << i);
              }
          }
          return ans;
      }
  };


-- -- -- -- -- -- -- -- -Leetcode - POTD - 24 / 04 / 2025 -----------------------------------

2799. Count Complete Subarrays in an Array
Solved
Medium
Topics
Companies
Hint
You are given an array nums consisting of positive integers.

We call a subarray of an array complete if the following condition is satisfied:

The number of distinct elements in the subarray is equal to the number of distinct elements in the whole array.
Return the number of complete subarrays.

A subarray is a contiguous non-empty part of an array.

 

Example 1:

Input: nums = [1,3,1,2,2]
Output: 4
Explanation: The complete subarrays are the following: [1,3,1,2], [1,3,1,2,2], [3,1,2] and [3,1,2,2].
Example 2:

Input: nums = [5,5,5,5]
Output: 10
Explanation: The array consists only of the integer 5, so any subarray is complete. The number of subarrays that we can choose is 10.
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2000





