- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 5 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Kadane's Algorithm
Difficulty: MediumAccuracy: 36.28%Submissions: 969K+Points: 4
Given an integer array arr[]. Find the contiguous sub-array(containing at least one number) that has the maximum sum and return its sum.

Examples:

Input: arr[] = [1, 2, 3, -2, 5]
Output: 9
Explanation: Max subarray sum is 9 of elements (1, 2, 3, -2, 5) which is a contiguous subarray.
Input: arr[] = [-1, -2, -3, -4]
Output: -1
Explanation: Max subarray sum is -1 of element (-1)
Input: arr[] = [5, 4, 7]
Output: 16
Explanation: Max subarray sum is 16 of element (5, 4, 7)
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 105
-107 ≤ arr[i] ≤ 107

class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
         int max_end_here=0,max_so_far=INT_MIN;
        int n=arr.size();
        for(int i=0;i<n;i++){
            max_end_here+=arr[i];
            
            max_so_far=max(max_end_here,max_so_far);
            
            
            max_end_here=max(max_end_here,0);
        }
        return max_so_far;
    }
};