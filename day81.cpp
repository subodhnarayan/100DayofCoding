// GFG 24/7/2024
//  Check for BST
//  Difficulty: EasyAccuracy: 25.37%Submissions: 528K+Points: 2
//  Given the root of a binary tree. Check whether it is a BST or not.
//  Note: We are considering that BSTs can not contain duplicate Nodes.
//  A BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// Examples:

// Input:
//    2
//  /    \
// 1      3
//         \
//          5
// Output: true
// Explanation:
// The left subtree of every node contains smaller keys and right subtree of every node contains greater. Hence, the tree is a BST.
// Input:
//   2
//    \
//     7
//      \
//       6
//        \
//         9
// Output: false
// Explanation:
// Since the node with value 7 has right subtree nodes with keys less than 7, this is not a BST.
// Input:
//    10
//  /    \
// 5      20
//       /   \
//      9     25
// Output: false
// Explanation: The node is present in the right subtree of 10, but it is smaller than 10.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(Height of the tree)
// where n is the number of nodes in the given tree

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 105

class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    void inorder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    bool isBST(Node *root)
    {
        vector<int> ans;
        inorder(root, ans);
        int n = ans.size();
        for (int i = 1; i < n; i++)
        {
            if (ans[i - 1] == ans[i] || ans[i - 1] > ans[i])
            {
                return false;
            }
        }
        return true;
    }
};

// LEETCODE POTD 2024/7/24

2191. Sort the Jumbled Numbers
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.
 

Example 1:

Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
Output: [338,38,991]
Explanation: 
Map the number 991 as follows:
1. mapping[9] = 6, so all occurrences of the digit 9 will become 6.
2. mapping[1] = 9, so all occurrences of the digit 1 will become 9.
Therefore, the mapped value of 991 is 669.
338 maps to 007, or 7 after removing the leading zeros.
38 maps to 07, which is also 7 after removing leading zeros.
Since 338 and 38 share the same mapped value, they should remain in the same relative order, so 338 comes before 38.
Thus, the sorted array is [338,38,991].
Example 2:

Input: mapping = [0,1,2,3,4,5,6,7,8,9], nums = [789,456,123]
Output: [123,456,789]
Explanation: 789 maps to 789, 456 maps to 456, and 123 maps to 123. Thus, the sorted array is [123,456,789].
 

Constraints:

mapping.length == 10
0 <= mapping[i] <= 9
All the values of mapping[i] are unique.
1 <= nums.length <= 3 * 104
0 <= nums[i] < 109

