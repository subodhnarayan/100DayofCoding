// GFG POTD 12/7/2024
Root to leaf path sum
    // Difficulty: EasyAccuracy: 40.79%Submissions: 117K+Points: 2
    // Given a binary tree and an integer target, check whether there is a root-to-leaf path with its sum as target.

    // Examples :

    // Input: tree = 1, target = 2
    //             /   \
//           2     3
    // Output: false
    // Explanation: There is no root to leaf path with sum 2.
    // Input: tree = 1,  target = 4
    //             /   \
//           2     3
    // Output: true
    // Explanation: The sum of path from leaf node 3 to root 1 is 4.
    // Expected Time Complexity: O(n)
    // Expected Auxiliary Space: O(height of tree)

    // Constraints:
    // 1 ≤ number of nodes ≤ 104
    // 1 ≤ target ≤ 106

    class Solution
{
public:
    bool solve(Node *root, int target, int ans)
    {
        if (root == NULL)
        {
            return false;
        }
        ans += root->data;
        if (root->left == NULL && root->right == NULL)
            return ans == target;
        return solve(root->left, target, ans) || solve(root->right, target, ans);
    }
    bool hasPathSum(Node *root, int target)
    {
        int sum = 0;
        return solve(root, target, 0);
    }
};

Leetcode 12 / 7 / 2024

    1717. Maximum Score From Removing Substrings
    // Solved
    // Medium
    // Topics
    // Companies
    // Hint
    // You are given a string s and two integers x and y. You can perform two types of operations any number of times.

    // Remove substring "ab" and gain x points.
    // For example, when removing "ab" from "cabxbae" it becomes "cxbae".
    // Remove substring "ba" and gain y points.
    // For example, when removing "ba" from "cabxbae" it becomes "cabxe".
    // Return the maximum points you can gain after applying the above operations on s.

    // Example 1:

    // Input: s = "cdbcbbaaabab", x = 4, y = 5
    // Output: 19
    // Explanation:
    // - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
    // - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
    // - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
    // - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
    // Total score = 5 + 4 + 5 + 5 = 19.
    // Example 2:

    // Input: s = "aabbaaxybbaabb", x = 5, y = 4
    // Output: 20

    // Constraints:

    // 1 <= s.length <= 105
    // 1 <= x, y <= 104
    // s consists of lowercase English letters.

    class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        string hstr = "";
        string lstr = "";
        int high = 0;
        int low = 0;
        int res = 0;
        vector<char> st;
        if (x > y)
        {
            hstr = "ab";
            high = x;
            lstr = "ba";
            low = y;
        }
        else
        {
            hstr = "ba";
            high = y;
            lstr = "ab";
            low = x;
        }

        for (char c : s)
        {
            if (c == hstr[1] && !st.empty() && st.back() == hstr[0])
            {
                res += high;
                st.pop_back();
            }
            else
            {
                st.push_back(c);
            }
        }

        vector<char> newstr;
        for (char c : st)
        {
            if (c == lstr[1] && !newstr.empty() && newstr.back() == lstr[0])
            {
                res += low;
                newstr.pop_back();
            }
            else
            {
                newstr.push_back(c);
            }
        }
        return res;
    }
};
