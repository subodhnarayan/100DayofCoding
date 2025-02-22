-- -- -- -- -- -- -- -- -GFG - POTD - 20 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Parenthesis Checker
Difficulty: EasyAccuracy: 28.56%Submissions: 642K+Points: 2
Given a string s, composed of different combinations of '(' , ')', '{', '}', '[', ']', verify the validity of the arrangement.
An input string is valid if:

         1. Open brackets must be closed by the same type of brackets.
         2. Open brackets must be closed in the correct order.

Examples :

Input: s = "[{()}]"
Output: true
Explanation: All the brackets are well-formed.
Input: s = "[()()]{}"
Output: true
Explanation: All the brackets are well-formed.
Input: s = "([]"
Output: False
Explanation: The expression is not balanced as there is a missing ')' at the end.
Input: s = "([{]})"
Output: False
Explanation: The expression is not balanced as there is a closing ']' before the closing '}'.
Constraints:
1 ≤ s.size() ≤ 106
s[i] ∈ {'{', '}', '(', ')', '[', ']'}


Time Complexity: O(n)Auxiliary Space: O(n)

class Solution {
    public:
      bool isBalanced(string& s) {
          stack<char> st;
          for(char c: s){
              if(st.empty() || c=='(' || c=='{' ||  c=='['){
                  st.push(c);
              }
              else{
                  if(st.empty()) return false;
                  if((c==')' && st.top()=='(') ||
                          (c=='}' && st.top()=='{') ||
                          (c==']' && st.top()=='[') )
                          {
                              st.pop();
                          }
                  else{
                      return false;
                  }
              }
          }
          return st.empty()?true:false;
      }
  };

-- -- -- -- -- -- -- -- -LeetCode - POTD - 20 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

1261. Find Elements in a Contaminated Binary Tree
Solved
Medium
Topics
Companies
Hint
Given a binary tree with the following rules:

root.val == 0
For any treeNode:
If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

Implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
bool find(int target) Returns true if the target value exists in the recovered binary tree.
 

Example 1:


Input
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
Output
[null,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True 
Example 2:


Input
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
Output
[null,true,true,false]
Explanation
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
Example 3:


Input
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
Output
[null,true,false,false,true]
Explanation
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
 

Constraints:

TreeNode.val == -1
The height of the binary tree is less than or equal to 20
The total number of nodes is between [1, 104]
Total calls of find() is between [1, 104]
0 <= target <= 106

class FindElements {
    unordered_set<int> recoveredValues;

    void recoverTree(TreeNode* root) {
        if (!root) return;
        recoveredValues.insert(root->val);
        if (root->left) {
            root->left->val = 2 * root->val + 1;
            recoverTree(root->left);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            recoverTree(root->right);
        }
    }
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        recoverTree(root);
    }
    
    bool find(int target) {
        return recoveredValues.count(target);
    }
};

