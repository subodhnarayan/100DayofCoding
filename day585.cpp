-- -- -- -- -- -- -- -- -GFG - POTD - 05/ 07 / 2025 ----------------------------------------

Max Score from Subarray Mins
Difficulty: MediumAccuracy: 43.26%Submissions: 130K+Points: 4
You are given an array arr[] of integers. Your task is to find the maximum sum of the smallest and second smallest elements across all subarrays (of size >= 2) of the given array.

Examples :

Input: arr[] = [4, 3, 5, 1]
Output: 8
Explanation: All subarrays with at least 2 elements and find the two smallest numbers in each:
[4, 3] → 3 + 4 = 7
[4, 3, 5] → 3 + 4 = 7
[4, 3, 5, 1] → 1 + 3 = 4
[3, 5] → 3 + 5 = 8
[3, 5, 1] → 1 + 3 = 4
[5, 1] → 1 + 5 = 6
Maximum Score is 8.
Input: arr[] = [1, 2, 3]
Output: 5
Explanation: All subarray with at least 2 elements and find the two smallest numbers in each:
[1, 2] → 1 + 2 = 3
[1, 2, 3] → 1 + 2 = 3
[2, 3] → 2 + 3 = 5
Maximum Score is 5
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
         int count=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            count=max(count,arr[i]+arr[i+1]);
        }
        return count;
    }
};
-- -- -- -- -- -- -- -- -Leetcode - POTD - 05/ 07 / 2025 ----------------------------------------


1394. Find Lucky Integer in an Array
Solved
Easy
Topics
premium lock icon
Companies
Hint
Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.

 

Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
Example 3:

Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.
 

Constraints:

1 <= arr.length <= 500
1 <= arr[i] <= 500