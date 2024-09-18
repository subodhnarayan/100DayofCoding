-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 18 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Parenthesis Checker
Difficulty: EasyAccuracy: 28.56%Submissions: 596K+Points: 2
Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

Note: The driver code prints "balanced" if function return true, otherwise it prints "not balanced".

Examples :

Input: {([])}
Output: true
Explanation: { ( [ ] ) }. Same colored brackets can form balanced pairs, with 0 number of unbalanced bracket.
Input: ()
Output: true
Explanation: (). Same bracket can form balanced pairs,and here only 1 type of bracket is present and in balanced way.
Input: ([]
Output: false
Explanation: ([]. Here square bracket is balanced but the small bracket is not balanced and Hence , the output will be unbalanced.
Expected Time Complexity: O(|x|)
Expected Auixilliary Space: O(|x|)

Constraints:
1 ≤ |x| ≤ 105

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
          stack<char>s;
     for(auto &i:x){
         if(i=='(' || i=='[' || i=='{'){
             s.push(i);
         }
         else{
             if(s.empty()) return false;
             char ch=s.top();
             s.pop();
             if(ch=='(' && i!=')' || ch=='{' && i!='}' || ch=='[' && i!=']'){
                 return false;
             }
             
         }
     }
     if(!s.empty()) return false;
     return true;
    }

};