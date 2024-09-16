- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 16 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Longest valid Parentheses
Difficulty: HardAccuracy: 26.13%Submissions: 123K+Points: 8
Given a string str consisting of opening and closing parenthesis '(' and ')'. Find length of the longest valid parenthesis substring.

A parenthesis string is valid if:

For every opening parenthesis, there is a closing parenthesis.
Opening parenthesis must be closed in the correct order.
Examples :

Input: str = ((()
Output: 2
Explaination: The longest valid parenthesis substring is "()".
Input: str = )()())
Output: 4
Explaination: The longest valid parenthesis substring is "()()".
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 105  

class Solution {
  public:
    int maxLength(string& str) {
        // stack<char> st;
        // int count=0;
        // for(int i=0;i<str.size();i++){
        //     if(st.empty()){
        //         st.push(str[i]);
        //     }
        //     else if(str[i]==')'){
        //         if(st.top()=='('){
        //             count+=2;
        //             st.pop();
        //         }
        //         else{
        //             st.push(str[i]);
        //         }
        //     }
        //     else{
        //         st.push(str[i]);
        //     }
        // }
        // return count;
        
        int max1=0,max2=0,op=0,cl=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                op++;
            }
            else{
                cl++;
            }
            if(op<cl){
                op=cl=0;
            }
            if(op==cl){
                max1=max(max1,2*op);
            }
        }
        op=cl=0;
        
        for(int i=str.size()-1;i>=0;i--){
            if(str[i]=='('){
                op++;
            }
            else{
                cl++;
            }
            if(op>cl){
                op=cl=0;
            }
            if(op==cl){
                max2=max(max2,2*op);
            }
            
        }
        return max(max1,max2);
    }
};



 -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 16 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
 
