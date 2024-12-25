-- -- -- -- -- -- -- -- -GFG - POTD - 25 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Set Matrix Zeroes
Difficulty: MediumAccuracy: 52.54%Submissions: 20K+Points: 4
You are given a 2D matrix mat[][] of size n×m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0 and do it in constant space complexity.

Examples:

Input: mat[][] = [[1, -1, 1],
                [-1, 0, 1],
                [1, -1, 1]]
Output: [[1, 0, 1],
        [0, 0, 0],
        [1, 0, 1]]
Explanation: mat[1][1] = 0, so all elements in row 1 and column 1 are updated to zeroes.
Input: mat[][] = [[0, 1, 2, 0],
                [3, 4, 5, 2],
                [1, 3, 1, 5]]
Output: [[0, 0, 0, 0],
        [0, 4, 5, 0],
        [0, 3, 1, 0]]
Explanation: mat[0][0] and mat[0][3] are 0s, so all elements in row 0, column 0 and column 3 are updated to zeroes.
Constraints:
1 ≤ n, m ≤ 500
- 231 ≤ mat[i][j] ≤ 231 - 1

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int row = mat.size();
        int col = mat[0].size();
    
        // Flag to determine if the first row and first column need to be zeroed
        bool firstRowZero = false;
        bool firstColZero = false;
    
        // Step 1: Check if the first row has any zero
        for (int j = 0; j < col; j++) {
            if (mat[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
    
        // Step 2: Check if the first column has any zero
        for (int i = 0; i < row; i++) {
            if (mat[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
    
        // Step 3: Use the first row and first column to mark zeros for other rows and columns
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0; // Mark the start of the row
                    mat[0][j] = 0; // Mark the start of the column
                }
            }
        }
    
        // Step 4: Zero out the rows based on the first column
        for (int i = 1; i < row; i++) {
            if (mat[i][0] == 0) {
                for (int j = 1; j < col; j++) {
                    mat[i][j] = 0;
                }
            }
        }
    
        // Step 5: Zero out the columns based on the first row
        for (int j = 1; j < col; j++) {
            if (mat[0][j] == 0) {
                for (int i = 1; i < row; i++) {
                    mat[i][j] = 0;
                }
            }
        }
    
        // Step 6: Zero out the first row if needed
        if (firstRowZero) {
            for (int j = 0; j < col; j++) {
                mat[0][j] = 0;
            }
        }
    
        // Step 7: Zero out the first column if needed
        if (firstColZero) {
            for (int i = 0; i < row; i++) {
                mat[i][0] = 0;
            }
        }
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 25 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
515. Find Largest Value in Each Tree Row
Solved
Medium
Topics
Companies
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]
Example 2:

Input: root = [1,2,3]
Output: [1,3]
 

Constraints:

The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
    
    void dfs(TreeNode* node, int depth) {
        if (node == nullptr) {
            return;
        }
        
        if (depth == ans.size()) {
            ans.push_back(node->val);
        } else {
            ans[depth] = max(ans[depth], node->val);
        }
        
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};
