-- -- -- -- -- -- -- -- -GFG - POTD - 11 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Check for BST
Difficulty: EasyAccuracy: 25.37%Submissions: 561K+Points: 2Average Time: 30m
Given the root of a binary tree. Check whether it is a BST or not.
Note: We are considering that BSTs can not contain duplicate Nodes.
A BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Examples:

Input: root = [2, 1, 3, N, N, N, 5]


Output: true 
Explanation: The left subtree of every node contains smaller keys and right subtree of every node contains greater keys. Hence, the tree is a BST.
Input: root = [2, N, 7, N, 6, N, 9] 



Output: false 
Explanation: Since the node to the right of node with key 7 has lesser key value, hence it is not a valid BST.
Input: root = [10, 5, 20, N, N, 9, 25]


Output: false
Explanation: The node with key 9 present in the right subtree has lesser key value than root node.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 10

class Solution {
    public:
      // Function to check whether a Binary Tree is BST or not
       bool solve(Node* node, int l, int r){
          if(!node)
          return true;
          
          if(node->data<=l || node->data>=r)
          return false;
          
          int rl = solve(node->left, l, node->data);
          int rr = solve(node->right, node->data, r);
          
          return rl && rr;
      }
      bool isBST(Node* root) {
          return solve(root, -1e9, 1e9);
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 11 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
