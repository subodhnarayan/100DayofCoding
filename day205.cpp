-- -- -- -- -- -- -- -- -GFG - POTD - 24 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Kadane's Algorithm
Difficulty: MediumAccuracy: 36.28%Submissions: 1MPoints: 4
Given an integer array arr[]. You need to find the maximum sum of a subarray.

Examples:

Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
Output: 11
Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
Input: arr[] = [-2, -4]
Output: -2
Explanation: The subarray {-2} has the largest sum -2.
Input: arr[] = [5, 4, 1, 7, 8]
Output: 25
Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.
Constraints:
1 ≤ arr.size() ≤ 105
-109 ≤ arr[i] ≤ 104


class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        int n=arr.size();
        int max_sum=arr[0],curr_sum=arr[0];
        for(int i=1;i<n;i++){
            curr_sum=max(arr[i],curr_sum+arr[i]);
            max_sum=max(curr_sum,max_sum);
        }
        return max_sum;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 24 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

1975. Maximum Matrix Sum
Solved
Medium
Topics
Companies
Hint
You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

 

Example 1:


Input: matrix = [[1,-1],[-1,1]]
Output: 4
Explanation: We can follow the following steps to reach sum equals 4:
- Multiply the 2 elements in the first row by -1.
- Multiply the 2 elements in the first column by -1.
Example 2:


Input: matrix = [[1,2,3],[-1,-2,-3],[1,2,3]]
Output: 16
Explanation: We can follow the following step to reach sum equals 16:
- Multiply the 2 last elements in the second row by -1.
 

Constraints:

n == matrix.length == matrix[i].length
2 <= n <= 250
-105 <= matrix[i][j] <= 105


class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
         long long sum=0;
        int minAbs=INT_MAX;
        bool negOdd=0;
        for(auto& row: matrix){
            for(int x: row){
                minAbs=min(minAbs, abs(x));
                if (x<0){
                    sum-=x;
                    negOdd=!negOdd;
                }
                else sum+=x;
            }
        }
        return sum-2*(negOdd)*minAbs;
    }
};