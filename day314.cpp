-- -- -- -- -- -- -- -- -GFG - POTD - 06 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
Longest Common Subsequence
Difficulty: MediumAccuracy: 41.68%Submissions: 301K+Points: 4
Given two strings s1 and s2, return the length of their longest common subsequence (LCS). If there is no common subsequence, return 0.

A subsequence is a sequence that can be derived from the given string by deleting some or no elements without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".

Examples:

Input: s1 = "ABCDGH", s2 = "AEDFHR"
Output: 3
Explanation: The longest common subsequence of "ABCDGH" and "AEDFHR" is "ADH", which has a length of 3.
Input: s1 = "ABC", s2 = "AC"
Output: 2
Explanation: The longest common subsequence of "ABC" and "AC" is "AC", which has a length of 2.
Input: s1 = "XYZW", s2 = "XYWZ"
Output: 3
Explanation: The longest common subsequences of "XYZW" and "XYWZ" are "XYZ" and "XYW", both of length 3.
Constraints:
1<= s1.size(), s2.size() <=103
Both strings s1 and s2 contain only uppercase English letters.

Time Complexity: O(n * m)Auxiliary Space: O(n)


class Solution {
  public:
    vector<vector<int>> dp; // Memoization table

    int abc(string &s1, string &s2, int i, int j) {
        
        if (i < 0 || j < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        
        if (s1[i] == s2[j]) {
            return dp[i][j] = 1 + abc(s1, s2, i - 1, j - 1);
        } 
        
        else {
            return dp[i][j] = max(abc(s1, s2, i - 1, j), abc(s1, s2, i, j - 1));
        }
    }
    
    int lcs(string &s1, string &s2) {
        // code here
        int m = s1.size(), n = s2.size();
        dp.assign(m, vector<int>(n, -1)); 
        return abc(s1, s2, m - 1, n - 1);
    }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 06 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
2965. Find Missing and Repeated Values
Solved
Easy
Topics
Companies
You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

 

Example 1:

Input: grid = [[1,3],[2,2]]
Output: [2,4]
Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
Example 2:

Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
Output: [9,5]
Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].
 

Constraints:

2 <= n == grid.length == grid[i].length <= 50
1 <= grid[i][j] <= n * n
For all x that 1 <= x <= n * n there is exactly one x that is not equal to any of the grid members.
For all x that 1 <= x <= n * n there is exactly one x that is equal to exactly two of the grid members.
For all x that 1 <= x <= n * n except two of them there is exatly one pair of i, j that 0 <= i, j <= n - 1 and grid[i][j] == x.

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0, sqrSum = 0;
        long long n = grid.size();
        long long total = n * n;

        // Calculate actual sum and squared sum from grid
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                sum += grid[row][col];
                sqrSum +=
                    static_cast<long long>(grid[row][col]) * grid[row][col];
            }
        }

        // Calculate differences from expected sums
        // Expected sum: n(n+1)/2, Expected square sum: n(n+1)(2n+1)/6
        long long sumDiff = sum - total * (total + 1) / 2;
        long long sqrDiff = sqrSum - total * (total + 1) * (2 * total + 1) / 6;

        // Using math: If x is repeated and y is missing
        // sumDiff = x - y
        // sqrDiff = x² - y²
        int repeat = (sqrDiff / sumDiff + sumDiff) / 2;
        int missing = (sqrDiff / sumDiff - sumDiff) / 2;

        return {repeat, missing};
    }
};
