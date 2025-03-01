//---------------------------------------GFG-- 02/28/2025 -------------------------------//
Evaluation of Postfix Expression
Difficulty: MediumAccuracy: 63.04%Submissions: 92K+Points: 4
You are given an array of strings arr that represents a valid arithmetic expression written in Reverse Polish Notation (Postfix Notation). Your task is to evaluate the expression and return an integer representing its value.

Key Details:

The valid operators are '+', '-', '*', and '/'.
Each operand is guaranteed to be a valid integer or another expression.
The division operation between two integers always rounds the result towards zero, discarding any fractional part.
No division by zero will occur in the input.
The input is a valid arithmetic expression in Reverse Polish Notation.
The result of the expression and all intermediate calculations will fit in a 32-bit signed integer.
Examples:

Input: arr = ["2", "3", "1", "*", "+", "9", "-"]
Output: -4
Explanation: If the expression is converted into an infix expression, it will be 2 + (3 * 1) – 9 = 5 – 9 = -4.
Input: arr = ["100", "200", "+", "2", "/", "5", "*", "7", "+"]
Output: 757
Explanation: If the expression is converted into an infix expression, it will be ((100 + 200) / 2) * 5 + 7  = 150 * 5 + 7 = 757.
Constraints:

1 <= arr.size() <= 105
arr[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-104, 104]

class Solution {
  public:
    int evaluate(vector<string>& arr) {
        // code here
        stack<int> st;
        
        int n = arr.size();
        
        for(int i = 0;i<n;i++){
            if((arr[i] != "+") && (arr[i] != "-") && (arr[i] != "*") && (arr[i] != "/")){
                st.push(stoi(arr[i]));
            }else{
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                
                if(arr[i] == "+"){
                    st.push(y+x);
                }else if(arr[i] == "-"){
                    st.push(y-x);
                }else if(arr[i] == "*"){
                    st.push(y*x);
                }else{
                    st.push(y/x);
                }
            }
        }
        
        return st.top();
    }
};
//---------------------------------------LeetCode-- 02/28/2025 -------------------------------//
1092. Shortest Common Supersequence 
Solved
Hard
Topics
Companies
Hint
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.


class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int str1Length = str1.length();
        int str2Length = str2.length();

        vector<vector<int>> dp(str1Length + 1, vector<int>(str2Length + 1, 0));

        // Initialize the base cases
        // When str2 is empty, the supersequence is str1 itself
        // (length = row index)
        for (int row = 0; row <= str1Length; row++) {
            dp[row][0] = row;
        }
        // When str1 is empty, the supersequence is str2 itself
        // (length = col index)
        for (int col = 0; col <= str2Length; col++) {
            dp[0][col] = col;
        }

        // Fill the DP table
        for (int row = 1; row <= str1Length; row++) {
            for (int col = 1; col <= str2Length; col++) {
                if (str1[row - 1] == str2[col - 1]) {
                    // If characters match,
                    // inherit the length from the diagonal + 1
                    dp[row][col] = dp[row - 1][col - 1] + 1;
                } else {
                    // If characters do not match,
                    // take the minimum length option + 1
                    dp[row][col] = min(dp[row - 1][col], dp[row][col - 1]) + 1;
                }
            }
        }

        string supersequence = "";
        int row = str1Length, col = str2Length;

        while (row > 0 && col > 0) {
            if (str1[row - 1] == str2[col - 1]) {
                // If characters match, take it from diagonal
                supersequence += str1[row - 1];
                row--;
                col--;
            } else if (dp[row - 1][col] < dp[row][col - 1]) {
                // If str1’s character is part of the supersequence, move up
                supersequence += str1[row - 1];
                row--;
            } else {
                // If str2’s character is part of the supersequence, move left
                supersequence += str2[col - 1];
                col--;
            }
        }

        // Append any remaining characters
        // If there are leftover characters in str1
        while (row > 0) {
            supersequence += str1[row - 1];
            row--;
        }
        // If there are leftover characters in str2
        while (col > 0) {
            supersequence += str2[col - 1];
            col--;
        }

        // Reverse the built sequence to get the correct order
        reverse(supersequence.begin(), supersequence.end());
        return supersequence;
    }
};
