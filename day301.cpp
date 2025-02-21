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

