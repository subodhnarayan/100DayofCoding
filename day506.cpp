-- -- -- -- -- -- -- -- -GFG - POTD - 17 / 05 / 2025 ----------------------------------------

Sort the given array after applying the given equation
Difficulty: MediumAccuracy: 36.21%Submissions: 24K+Points: 4
Given an integer array arr[] sorted in ascending order, along with three integers: A, B, and C. The task is to transform each element x in the array using the quadratic function A*(x2) + B*x + C. After applying this transformation to every element, return the modified array in sorted order.

Examples:

Input: arr[] = [-4, -2, 0, 2, 4], A = 1, B = 3, C = 5
Output: [3, 5, 9, 15, 33]
Explanation: After applying f(x) = 1*(x2)+ 3*x + 5 to each x, we get [9, 3, 5, 15, 33]. After sorting this array, the array becomes [3, 5, 9, 15, 33].
Input: arr[] = [-3, -1, 2, 4], A = -1, B = 0, C = 0
Output: [-16, -9, -4, -1]
Explanation: After applying f(x) = -1*(x2) + 0*x + 0 to each x, we get [ -9, -1, -4, -16 ]. After sorting this array, the array becomes  [-16, -9, -4, -1].
Constraints:
1 ≤ arr.size() ≤ 106
-103 ≤ arr[i], A, B, C ≤ 103

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)


class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // code here
         vector<int> ans; // To store transformed values
        
        // Step 1: Apply quadratic transformation to each element
        for(int x : arr){
            long long int temp = (A * x * x) + (B * x) + C; // Compute A*(x^2) + B*x + C
            ans.push_back((int)(temp)); // Store the result (cast to int)
        }
        
        // Step 2: Sort the transformed array
        sort(ans.begin(), ans.end());
        
        return ans; // Return sorted transformed array
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 17 / 05 / 2025 ----------------------------------------


75. Sort Colors
Solved
Medium
Topics
Companies
Hint
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.