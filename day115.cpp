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


