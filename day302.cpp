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

