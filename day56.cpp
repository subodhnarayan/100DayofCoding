// GFG POTD 6/26/2024

// Coverage of all Zeros in a Binary Matrix
// Difficulty: EasyAccuracy: 55.68%Submissions: 21K+Points: 2
// Given a binary matrix contains 0s and 1s only, we need to find the sum of coverage of all zeros of the matrix where coverage for a particular 0 is defined as a total number of ones around a zero in left, right, up and bottom directions.

// Examples:

// Input:
// matrix = [[0, 1, 0],
//           [0, 1, 1],
//           [0, 0, 0]]
// Output: 6
// Explanation: There are a total of 6 coverage are there

// Input:
// matrix = [[0, 1]]
// Output: 1
// Explanation: There are only 1 coverage.
// Expected Time Complexity: O(n * m)
// Expected Space Complexity: O(1)

// Constraints:
// 1 <= matrix.size, matrix[0].size <= 100

class Solution
{
public:
    int findCoverage(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    if (j + 1 < col && matrix[i][j + 1] == 1)
                        count++;
                    if (j - 1 >= 0 && matrix[i][j - 1] == 1)
                        count++;
                    if (i + 1 < row && matrix[i + 1][j] == 1)
                        count++;
                    if (i - 1 >= 0 && matrix[i - 1][j] == 1)
                        count++;
                }
            }
        }
        return count;
    }
};

// Leetcode POTD 6/26/2024

// 1382. Balance a Binary Search Tree
// Solved
// Medium
// Topics
// Companies
// Hint
// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

// Example 1:

// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
// Example 2:

// Input: root = [2,1,3]
// Output: [2,1,3]

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 105

class Solution
{
public:
    void inorder(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    TreeNode *solve(int l, int r, vector<int> &ans)
    {
        if (l > r)
        {
            return NULL;
        }
        int mid = l + (r - l) / 2;

        TreeNode *root = new TreeNode(ans[mid]);
        root->left = solve(l, mid - 1, ans);
        root->right = solve(mid + 1, r, ans);
        return root;
    }

    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> ans;
        inorder(root, ans);
        int l = 0;
        int r = ans.size() - 1;
        return solve(l, r, ans);
    }
};