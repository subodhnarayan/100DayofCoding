// 17/07/2024
Construct Binary Tree from Parent Array
// Difficulty: MediumAccuracy: 47.34%Submissions: 53K+Points: 4
Given an array parent that is used to represent a tree. The array indices (0-based indexing) are the values of the tree nodes and parent[i] denotes the parent node of a particular node. The parent of the root node would always be -1, as there is no parent for the root. Construct the standard linked representation of Binary Tree from this array representation and return the root node of the constructed tree.

// Note: If two elements have the same parent, the one that appears first in the array will be the left child and the other is the right child. You don't need to print anything, the driver code will print the level order traversal of the returned root node to verify the output.

// Examples:

// Input: parent[] = [-1, 0, 0, 1, 1, 3,5]
// Output: 0 1 2 3 4 5 6
// Explanation: the tree generated
// will have a structure like 
//           0
//         /   \
//        1     2
//       / \
//      3   4
//     /
//    5
//  /
// 6
// Input: parent[] = [2, 0, -1]
// Output: 2 0 1
// Explanation: the tree generated will
// have a sturcture like
//              2
//             /   
//            0      
//           /   
//          1     
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ parent.size() ≤ 103


class Solution
{
public:
    // Function to construct binary tree from parent array.
    Node *createTree(vector<int> parent)
    {
        // first making the nodes of all the elements

        int n = parent.size();
        vector<Node *> pt;
        for (int i = 0; i < n; i++)
        {
            pt.push_back(new Node(i));
        } // made all the node

        // now mapping all these nodes

        Node *head = NULL;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] != -1)
            {
                if ((pt[parent[i]]->left) == NULL)
                {
                    pt[parent[i]]->left = pt[i];
                }
                else
                {
                    pt[parent[i]]->right = pt[i];
                }
            }
            else
            {
                head = pt[i];
            }
        }
        return head;
    }
};

// 1110. Delete Nodes And Return Forest
// Solved
// Medium
// Topics
// Companies
// Given the root of a binary tree, each node in the tree has a distinct value.

// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

// Return the roots of the trees in the remaining forest. You may return the result in any order.

// Example 1:

// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]
// Example 2:

// Input: root = [1,2,4,null,3], to_delete = [3]
// Output: [[1,2,4]]

// Constraints:

// The number of nodes in the given tree is at most 1000.
// Each node has a distinct value between 1 and 1000.
// to_delete.length <= 1000
// to_delete contains distinct values between 1 and 1000.

class Solution
{
public:
    bool set[1001] = {};
    void dfs(TreeNode *&root, bool flag, vector<TreeNode *> &res)
    {
        if (root == nullptr)
            return;
        dfs(root->left, set[root->val], res);
        dfs(root->right, set[root->val], res);
        if (!set[root->val] && flag)
            res.push_back(root);
        if (set[root->val])
            root = nullptr;
    }
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> res;
        for (int num : to_delete)
            set[num] = true;
        dfs(root, true, res);
        return res;
    }
};
