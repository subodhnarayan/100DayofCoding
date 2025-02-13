-- -- -- -- -- -- -- -- -GFG - POTD - 13 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Pair Sum in BST
Difficulty: MediumAccuracy: 44.02%Submissions: 72K+Points: 4Average Time: 40m
Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 

Examples:

Input: root = [7, 3, 8, 2, 4, N, 9], target = 12
       bst
Output: True
Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.
Input: root = [9, 5, 10, 2, 6, N, 12], target = 23
          bst-3
Output: False
Explanation: In the binary tree above, there are no such two nodes exists that add up to 23.
Constraints:

1 ≤ Number of Nodes ≤ 105
1 ≤ target ≤ 106


class Solution {
    public:
     unordered_map<int,int> map;
  
   bool preorder(Node* root, int target) {
          
          if(root == nullptr){
              return false;
          }
          if(map.find(target - root->data) != map.end()){
              return true;
          }
          map[root->data] = 1;
          if(preorder(root->left,target)) return true;;
          if(preorder(root->right,target)) return true;
          
          return false;
      }
      bool findTarget(Node *root, int target) {
          // your code here.
          if(preorder(root,target)){
              return true;
          }
          return false;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 13 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

