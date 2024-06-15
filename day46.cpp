// Mobile numeric keypad
// MediumAccuracy: 32.6%Submissions: 51K+Points: 4
// Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
// Daily rewards up for grabs!

// banner
// There is a standard numeric keypad on a mobile phone. You can only press the current button or buttons that are directly up, left, right, or down from it (for ex if you press 5, then pressing 2, 4, 6 & 8 are allowed). Diagonal movements and pressing the bottom row corner buttons (* and #) are prohibited.

// Given a number n, find the number of possible unique sequences of length n that you can create by pressing buttons. You can start from any digit.

// Examples

// Input: n = 1
// Output: 10
// Explanation: Number of possible numbers are 10 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
// Input: n = 2
// Output: 36
// Explanation: Possible numbers: 00, 08, 11, 12, 14, 22, 21, 23, 25 and so on. If we start with 0, valid numbers will be 00, 08 (count: 2). If we start with 1, valid numbers will be 11, 12, 14 (count: 3). If we start with 2, valid numbers  will be 22, 21, 23,25 (count: 4). If we start with 3, valid numbers will be 33, 32, 36 (count: 3). If we start with 4, valid numbers will be 44,41,45,47 (count: 4). If we start with 5, valid numbers will be 55,54,52,56,58 (count: 5) and so on.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ n ≤ 25

class Solution
{
public:
    long long getCount(int n)
    {
        if (n == 1)
        {
            return 10;
        }
        int arr[10][5] = {
            {0, 8, -1, -1, -1}, // 0 can move to 8
            {1, 2, 4, -1, -1},  // 1 can move to 2, 4
            {1, 2, 3, 5, -1},   // 2 can move to 1, 3, 5
            {2, 3, 6, -1, -1},  // 3 can move to 2, 6
            {1, 4, 5, 7, -1},   // 4 can move to 1, 5, 7
            {2, 4, 5, 6, 8},    // 5 can move to 2, 4, 6, 8
            {3, 5, 6, 9, -1},   // 6 can move to 3, 5, 9
            {4, 7, 8, -1, -1},  // 7 can move to 4, 8
            {0, 5, 7, 8, 9},    // 8 can move to 0, 5, 7, 9
            {6, 8, 9, -1, -1}   // 9 can move to 6, 8
        };
        long long dp[n + 1][10];

        for (int i = 0; i < 10; i++)
        {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                dp[i][j] = 0;
                for (int k = 0; k < 5; k++)
                {
                    if (arr[j][k] != -1)
                    {
                        dp[i][j] += dp[i - 1][arr[j][k]];
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i <= 9; i++)
        {
            ans += dp[n][i];
        }
        return ans;
    }
};