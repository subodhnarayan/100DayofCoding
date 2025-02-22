-- -- -- -- -- -- -- -- -GFG - POTD - 21 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Longest valid Parentheses
Difficulty: HardAccuracy: 26.13%Submissions: 139K+Points: 8Average Time: 20m
Given a string s consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
The closing parenthesis must be after its opening parenthesis.
Examples :

Input: s = "((()"
Output: 2
Explanation: The longest valid parenthesis substring is "()".
Input: s = ")()())"
Output: 4
Explanation: The longest valid parenthesis substring is "()()".
Input: s = "())()"
Output: 2
Explanation: The longest valid parenthesis substring is "()".
Constraints:
1 ≤ s.size() ≤ 106  
s consists of '(' and ')' only

Time Complexity: O(n)Auxiliary Space: O(n)

class Solution {
    public:
      int maxLength(string& s) {
          stack<int> st;
          st.push(-1);
          for(int i=0;i<s.size();i++){
              if(s[st.top()]=='(' && st.size()>1 && s[i]==')'){
                  st.pop();
              }
              else{
                  st.push(i);
              }
          }
          
          int lim=s.size(),ans=0;
          while(!st.empty()){
              int p=st.top();
              st.pop();
              ans=max(ans,lim-p-1);
              lim=p;
          }
          return ans;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 21 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

1028. Recover a Tree From Preorder Traversal
Solved
Hard
Topics
Companies
Hint
We run a preorder depth-first search (DFS) on the root of a binary tree.

At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

If a node has only one child, that child is guaranteed to be the left child.

Given the output traversal of this traversal, recover the tree and return its root.

 

Example 1:


Input: traversal = "1-2--3--4-5--6--7"
Output: [1,2,5,3,4,6,7]
Example 2:


Input: traversal = "1-2--3---4-5--6---7"
Output: [1,2,5,3,null,6,null,4,null,7]
Example 3:


Input: traversal = "1-401--349---90--88"
Output: [1,401,null,349,88,90]

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
        string s;
        int idx = 0, level = 0;
        void helper(TreeNode* parent, int lvl) {
            while (idx < s.length() && lvl == level) {
                int num = 0;
                while (idx < s.length() && isdigit(s[idx])) {
                    num = num * 10 + (s[idx++] - '0');
                }
                TreeNode* node = new TreeNode(num);
                if (!parent->left)
                    parent->left = node;
                else
                    parent->right = node;
                level = 0;
                while (idx < s.length() && s[idx] == '-') {
                    level++;
                    idx++;
                }
                helper(node, lvl + 1);
            }
        }
        TreeNode* recoverFromPreorder(string traversal) {
            s = traversal;
            TreeNode* node = new TreeNode(-1);
            helper(node, 0);
            return node->left;
        }
};