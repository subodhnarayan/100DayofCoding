-- -- -- -- -- -- -- -- -GFG - POTD - 27/ 06 / 2025 ----------------------------------------

Mobile numeric keypad
Difficulty: MediumAccuracy: 32.6%Submissions: 66K+Points: 4Average Time: 30m
There is a standard numeric keypad on a mobile phone. You can press the current button or any button that is directly above, below, to the left, or to the right of it. For example, if you press 5, then pressing 2, 4, 6, or 8 is allowed. However, diagonal movements and pressing the bottom row corner buttons (* and #) are not allowed.


Given an integer n, determine how many unique sequences of length n can be formed by pressing buttons on the keypad, starting from any digit.

Examples :

Input: n = 1
Output: 10
Explanation: Possible 1-digit numbers follow keypad moves - From 0 → 0, 1 → 1, 2 → 2 and so on, total 10 valid combinations are possible.
Input: n = 2
Output: 36
Explanation: Possible 2-digit numbers follow keypad moves -
From 0 → 00, 08 (2), 
From 1 → 11, 12, 14 (3),
From 3 → 33, 32, 36 (3), and so on,
total 36 valid combinations are possible.
Constraints:
1 ≤ n ≤ 15

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

class Solution {
  public:
    int getCount(int n) {
        // code here
        if (n == 1) {
            return 10;
        }

        int arr[10][5] = {
            {0, 8, -1, -1, -1},   // 0 can move to 8
            {1, 2, 4, -1, -1},    // 1 can move to 2, 4
            {1, 2, 3, 5, -1},     // 2 can move to 1, 3, 5
            {2, 3, 6, -1, -1},    // 3 can move to 2, 6
            {1, 4, 5, 7, -1},     // 4 can move to 1, 5, 7
            {2, 4, 5, 6, 8},      // 5 can move to 2, 4, 6, 8
            {3, 5, 6, 9, -1},     // 6 can move to 3, 5, 9
            {4, 7, 8, -1, -1},    // 7 can move to 4, 8
            {0, 5, 7, 8, 9},      // 8 can move to 0, 5, 7, 9
            {6, 8, 9, -1, -1}     // 9 can move to 6, 8
        };

        long long dp[n+1][10];

        for (int i = 0; i < 10; i++) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                dp[i][j] = 0;
                for (int k = 0; k < 5; k++) {
                    if (arr[j][k] != -1) {
                        dp[i][j] += dp[i - 1][arr[j][k]];
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i <= 9; i++) {
            ans += dp[n][i];
        }

        return ans;
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 27 / 06 / 2025 ----------------------------------------


s
Solutions
Accepted
Accepted
Submissions
Submissions


Code
Testcase
Testcase
Test Result
2014. Longest Subsequence Repeated k Times
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.

For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.

 

Example 1:

example 1
Input: s = "letsleetcode", k = 2
Output: "let"
Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
"let" is the lexicographically largest one.
Example 2:

Input: s = "bb", k = 2
Output: "b"
Explanation: The longest subsequence repeated 2 times is "b".
Example 3:

Input: s = "ab", k = 2
Output: ""
Explanation: There is no subsequence repeated 2 times. Empty string is returned.
 

Constraints:

n == s.length
2 <= n, k <= 2000
2 <= n < k * 8
s consists of lowercase English letters.