-- -- -- -- -- -- -- -- -GFG - POTD - 15 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Lowest Common Ancestor in a BST
Difficulty: EasyAccuracy: 65.2%Submissions: 165K+Points: 2Average Time: 20m
Given a Binary Search Tree (with all values unique) and two nodes n1 and n2 (n1 != n2). You may assume that both nodes exist in the tree. Find the Lowest Common Ancestor (LCA) of the given two nodes in the BST.

LCA between two nodes n1 and n2 is defined as the lowest node that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).

Examples:

Input: root = [5, 4, 6, 3, N, N, 7, N, N, N, 8], n1 = 7, n2 = 8
        
Output: 7
Explanation: 7 is the closest node to both 7 and 8, which is also an ancestor of both the nodes.
Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], n1 = 8, n2 = 14
                
Output: 8
Explanation: 8 is the closest node to both 8 and 14, which is also an ancestor of both the nodes.
Input: root = [2, 1, 3], n1 = 1, n2 = 3
        
Output: 2
Explanation: 2 is the closest node to both 1 and 3, which is also an ancestor of both the nodes.
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105
1 <= n1, n2 <= 105


class Solution {
    public:
      Node* LCA(Node* root, Node* n1, Node* n2) {
          if(!root) return NULL;
          if(root->data>n1->data && root->data>n2->data){
              LCA(root->left,n1,n2);
          }
          else if(root->data<n1->data && root->data<n2->data){
              LCA(root->right,n1,n2);
          }
          else{
              return root;
          }
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 15 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

2698. Find the Punishment Number of an Integer
Solved
Medium
Topics
Companies
Hint
Given a positive integer n, return the punishment number of n.

The punishment number of n is defined as the sum of the squares of all integers i such that:

1 <= i <= n
The decimal representation of i * i can be partitioned into contiguous substrings such that the sum of the integer values of these substrings equals i.
 

Example 1:

Input: n = 10
Output: 182
Explanation: There are exactly 3 integers i in the range [1, 10] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 and 1 with a sum equal to 8 + 1 == 9.
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 and 0 with a sum equal to 10 + 0 == 10.
Hence, the punishment number of 10 is 1 + 81 + 100 = 182
Example 2:

Input: n = 37
Output: 1478
Explanation: There are exactly 4 integers i in the range [1, 37] that satisfy the conditions in the statement:
- 1 since 1 * 1 = 1. 
- 9 since 9 * 9 = 81 and 81 can be partitioned into 8 + 1. 
- 10 since 10 * 10 = 100 and 100 can be partitioned into 10 + 0. 
- 36 since 36 * 36 = 1296 and 1296 can be partitioned into 1 + 29 + 6.
Hence, the punishment number of 37 is 1 + 81 + 100 + 1296 = 1478
 

Constraints:

1 <= n <= 1000