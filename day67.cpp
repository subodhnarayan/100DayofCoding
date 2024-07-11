// GFG POTD 2024/7/11
//  Largest square formed in a matrix
//  Difficulty: MediumAccuracy: 36.98%Submissions: 106K+Points: 4
//  Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.

// Examples:

// Input: n = 6, m = 5
// mat = [[0, 1, 1, 0, 1],
//        [1, 1, 0, 1, 0],
//        [0, 1, 1, 1, 0],
//        [1, 1, 1, 1, 0],
//        [1, 1, 1, 1, 1],
//        [0, 0, 0, 0, 0]]
// Output: 3
// Explanation:

// The maximum length of a side of the square sub-matrix is 3 where every element is 1.
// Input: n = 2, m = 2
// mat = [[1, 1],
//        [1, 1]]
// Output: 2
// Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
// Input: n = 2, m = 2
// mat = [[0, 0],
//        [0, 0]]
// Output: 0
// Explanation: There is no 1 in the matrix.
// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500
// 0 ≤ mat[i][j] ≤ 1

int solve(vector<vector<int>> &mat, int row, int col, vector<vector<int>> &dp, int &ans)
{
    if (row >= mat.size() || col >= mat[0].size())
    {
        return 0;
    }
    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }
    int right = solve(mat, row, col + 1, dp, ans);
    int diagnol = solve(mat, row + 1, col + 1, dp, ans);
    int down = solve(mat, row + 1, col, dp, ans);

    if (mat[row][col] == 1)
    {
        dp[row][col] = 1 + min(right, min(diagnol, down));
        ans = max(ans, dp[row][col]);
        return dp[row][col];
    }
    else
    {
        return dp[row][col] = 0;
    }
}
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int ans = 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    solve(mat, 0, 0, dp, ans);
    return ans;
}

Letcode POTD 11/7/2024

1598. Crawler Log Folder
Solved
Easy
Topics
Companies
Hint
The Leetcode file system keeps a log each time some user performs a change folder operation.

The operations are described below:

"../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
"./" : Remain in the same folder.
"x/" : Move to the child folder named x (This folder is guaranteed to always exist).
You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.

The file system starts in the main folder, then the operations in logs are performed.

Return the minimum number of operations needed to go back to the main folder after the change folder operations.

Example 1:

Input: logs = ["d1/","d2/","../","d21/","./"]
Output: 2
Explanation: Use this change folder operation "../" 2 times and go back to the main folder.
Example 2:

Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
Output: 3
Example 3:

Input: logs = ["d1/","../","../","../"]
Output: 0

Constraints:

1 <= logs.length <= 103
2 <= logs[i].length <= 10
logs[i] contains lowercase English letters, digits, '.', and '/'.
logs[i] follows the format described in the statement.
Folder names consist of lowercase English letters and digits.

int minOperations(vector<string> &logs)
{
    int count = 0;
    int n = logs.size();
    for (int i = 0; i < n; i++)
    {
        if (logs[i] == "../")
        {
            if (count > 0)
                count--;
        }
        else if (logs[i] == "./")
        {
            count = count;
        }
        else
        {
            count++;
        }
    }
    return count;
}
};