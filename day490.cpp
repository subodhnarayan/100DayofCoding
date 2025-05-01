-- -- -- -- -- -- -- -- -GFG - POTD - 01 / 05 / 2025 -----------------------------------

Pascal Triangle
Difficulty: MediumAccuracy: 23.68%Submissions: 125K+Points: 4Average Time: 20m
Given a positive integer n, return the nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.

File:PascalTriangleAnimated2.gif

Examples:

Input: n = 4
Output: [1, 3, 3, 1]
Explanation: 4th row of pascal's triangle is [1, 3, 3, 1].
Input: n = 5
Output: [1, 4, 6, 4, 1]
Explanation: 5th row of pascal's triangle is [1, 4, 6, 4, 1].
Input: n = 1
Output: [1]
Explanation: 1st row of pascal's triangle is [1].
Constraints:
1 ≤ n ≤ 20

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

class Solution {
  public:
    
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<int> ans;
        int val=1;
        ans.push_back(val);
        for(int i=1;i<n;i++){
            val=val*(n-i)/i;
            ans.push_back(val);
        }
        return ans;
        
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 01 / 05 / 2025 -----------------------------------


