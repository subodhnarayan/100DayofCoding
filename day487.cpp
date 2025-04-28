-- -- -- -- -- -- -- -- -GFG - POTD - 29 / 04 / 2025 -----------------------------------

Maximum sum of Non-adjacent nodes
Difficulty: MediumAccuracy: 55.35%Submissions: 85K+Points: 4Average Time: 45m
Given a binary tree with a value associated with each node. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

Examples:

Input: root[] = [11, 1, 2]

Output: 11
Explanation: The maximum sum is obtained by selecting the node 11.

Input: root[] = [1, 2, 3, 4, N, 5, 6]

Output: 16
Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6, which are not directly connected to each other. Their total sum is 16.  

Constraints:
1 ≤ no. of nodes in the tree ≤ 104
1 ≤ Node.val ≤ 105
Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)


class Solution {
    public:
      // Function to return the maximum sum of non-adjacent nodes.
      int solve(Node* root,unordered_map<Node*,int>&mp){
          if(root == nullptr)return 0;
          if(mp.find(root) !=mp.end())return mp[root];
          int nontake = solve(root->left,mp)+solve(root->right,mp);
          int take = root->data;
          if(root->left){
              take += solve(root->left->left,mp);
              take += solve(root->left->right,mp);
          }
          if(root->right){
              take += solve(root->right->left,mp);
              take += solve(root->right->right,mp);
          }
          return mp[root] = max(take,nontake);
      }
      int getMaxSum(Node *root) {
          // code here
         unordered_map<Node*,int>mp;
          return solve(root,mp); 
      }
  };


-- -- -- -- -- -- -- -- -Leetcode - POTD - 29 / 04 / 2025 -----------------------------------



