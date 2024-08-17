- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 17 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


Product array puzzle
Difficulty: EasyAccuracy: 33.46%Submissions: 226K+Points: 2
Given an array nums[], construct a Product Array nums[] such that nums[i] is equal to the product of all the elements of nums except nums[i].

Examples:

Input: nums[] = [10, 3, 5, 6, 2]
Output: [180, 600, 360, 300, 900]
Explanation: For i=0, P[i] = 3*5*6*2 = 180.
For i=1, P[i] = 10*5*6*2 = 600.
For i=2, P[i] = 10*3*6*2 = 360.
For i=3, P[i] = 10*3*5*2 = 300.
For i=4, P[i] = 10*3*5*6 = 900.
Input: nums[] = [12,0]
Output: [0, 12]


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
         int n = nums.size();
        
        // Initialize the left and right product arrays
        vector<long long int> left(n, 1), right(n, 1), result(n, 1);
        
        // Fill the left array
        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        
        // Fill the right array
        for (int i = n - 2; i >= 0; --i) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        
        // Construct the result array
        for (int i = 0; i < n; ++i) {
            result[i] = left[i] * right[i];
        }
        
        return result;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends











1937. Maximum Number of Points with Cost
Solved
Medium
Topics
Companies
Hint
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

x for x >= 0.
-x for x < 0.
 

Example 1:


Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.
Example 2:


Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.



class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();
        
        // dp array to store maximum points at each cell
        vector<long long> dp(n, 0);
        
        // Initialize dp with the first row
        for (int j = 0; j < n; ++j) {
            dp[j] = points[0][j];
        }
        
        // Iterate over each row
        for (int i = 1; i < m; ++i) {
            vector<long long> leftMax(n, 0), rightMax(n, 0), newDp(n, 0);
            
            // Fill leftMax array
            leftMax[0] = dp[0];
            for (int j = 1; j < n; ++j) {
                leftMax[j] = max(leftMax[j - 1], dp[j] + j);
            }
            
            // Fill rightMax array
            rightMax[n - 1] = dp[n - 1] - (n - 1);
            for (int j = n - 2; j >= 0; --j) {
                rightMax[j] = max(rightMax[j + 1], dp[j] - j);
            }
            
            // Calculate new dp values
            for (int j = 0; j < n; ++j) {
                newDp[j] = max(leftMax[j] - j, rightMax[j] + j) + points[i][j];
            }
            
            // Move to the next row
            dp = newDp;
        }
        
        // Return the maximum value in the last dp array
        return *max_element(dp.begin(), dp.end());
    }
};
