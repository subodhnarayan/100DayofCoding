-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 26 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 

Wildcard Pattern Matching
Difficulty: HardAccuracy: 31.13%Submissions: 74K+Points: 8
Given two strings pattern and str which may be of different size, You have to return 1 if the wildcard pattern i.e. pattern, matches with str else return 0. All characters of the string str and pattern always belong to the Alphanumeric characters.

The wildcard pattern can include the characters ? and *
‘?’ – matches any single character.
‘*’ – Matches any sequence of characters (including the empty sequence).

Note: The matching should cover the entire str (not partial str).

Examples:

Input: pattern = "ba*a?", str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and 
'?' with 'b'.
Input: pattern = "a*ab", str = "baaabab"
Output: 0
Explanation: Because in string pattern character 'a' at first position,
pattern and str can't be matched. 
Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 <= length of(str, pattern) <= 200


class Solution {
  public:
    /*You are required to complete this method*/
    int solve(string pat,string str,int i,int j,vector<vector<int>> &dp){
        if(i==pat.length() and j==str.length()) return 1;
        if(i==pat.length()) return 0;
        if(j==str.length() and pat[i]=='*') return solve(pat,str,i+1,j,dp);
        if(j==str.length()) return 0;
        if(pat[i]!='*' and pat[i]!='?' and pat[i]!=str[j]) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int a=0,b=0,c=0;
        if(pat[i]=='*'){
            a=solve(pat,str,i+1,j,dp);
            b=solve(pat,str,i,j+1,dp);
        }
        c=solve(pat,str,i+1,j+1,dp);
        return dp[i][j]=a|b|c;
    }
    int wildCard(string pat, string str) {
        vector<vector<int>> dp(pat.length(),vector<int>(str.length(),-1)); 
       return solve(pat,str,0,0,dp);
    }
};



-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 26 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- 

590. N-ary Tree Postorder Traversal
Solved
Easy
Topics
Companies
Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

Example 1:


Input: root = [1,null,3,2,4,null,5,6]
Output: [5,6,3,2,4,1]
Example 2:


Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 

Constraints:

The number of nodes in the tree is in the range [0, 104].
0 <= Node.val <= 104
The height of the n-ary tree is less than or equal to 1000.
 

Follow up: Recursive solution is trivial, could you do it iteratively?