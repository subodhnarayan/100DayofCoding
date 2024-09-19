-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 19 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Reverse Words
Difficulty: EasyAccuracy: 56.08%Submissions: 337K+Points: 2
Given a String str, reverse the string without reversing its individual words. Words are separated by dots.

Note: The last character has not been '.'. 

Examples :

Input: str = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i
Input: str = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole string , the input string becomes mno.pqr
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 <= |str| <= 105




class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string S) {
       string ans;
        int n=S.size();
        string str="";
        for(int i=0;i<n;i++){
            if(S[i]!='.'){
                str=str+S[i];
            }
            else{
                ans=str+"."+ans;
                str="";
            }
        }
        ans=str+"."+ans;
        ans.pop_back();
        return ans;
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 19 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

241. Different Ways to Add Parentheses
Solved
Medium
Topics
Companies
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.

The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.

 

Example 1:

Input: expression = "2-1-1"
Output: [0,2]
Explanation:
((2-1)-1) = 0 
(2-(1-1)) = 2
Example 2:

Input: expression = "2*3-4*5"
Output: [-34,-14,-10,-10,10]
Explanation:
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
 

Constraints:

1 <= expression.length <= 20
expression consists of digits and the operator '+', '-', and '*'.
All the integer values in the input expression are in the range [0, 99].
The integer values in the input expression do not have a leading '-' or '+' denoting the sign.



class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
         vector<int> res;
        for (int i = 0; i < expression.size(); ++i) {
            char oper = expression[i];
            if (oper == '+' || oper == '-' || oper == '*') {
                vector<int> s1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> s2 = diffWaysToCompute(expression.substr(i + 1));
                for (int a : s1) {
                    for (int b : s2) {
                        if (oper == '+') res.push_back(a + b);
                        else if (oper == '-') res.push_back(a - b);
                        else if (oper == '*') res.push_back(a * b);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(expression));
        return res;
    }
};