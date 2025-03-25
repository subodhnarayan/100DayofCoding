-- -- -- -- -- -- -- -- -GFG - POTD - 25 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Boolean Parenthesization
Difficulty: HardAccuracy: 20.15%Submissions: 131K+Points: 8Average Time: 30m
You are given a boolean expression s containing
    'T' ---> true
    'F' ---> false 
and following operators between symbols
   &   ---> boolean AND
    |   ---> boolean OR
   ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Note: The answer is guaranteed to fit within a 32-bit integer.

Examples:

Input: s = "T|T&F^T"
Output: 4
Explaination: The expression evaluates to true in 4 ways: ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Input: s = "T^F|F"
Output: 2
Explaination: The expression evaluates to true in 2 ways: ((T^F)|F) and (T^(F|F)).
Constraints:
1 ≤ |s| ≤ 100 

Time Complexity: O(n^3)Auxiliary Space: O(n^2)

class Solution {
    public:
       bool evaluate(int b1,int b2,char &op)
      {
          if(op=='&')
              return b1&b2;
          if(op=='|')
              return b1|b2;
          if(op=='^')
              return b1^b2;
          
      }
        int helper(int start,int end,int req,string &s,  vector<vector<vector<int>>>&dp)
      {
          if(start==end)
              return (req==(s[start]=='T'))?1:0;
          if(dp[start][end][req]!=-1)
              return dp[start][end][req];
          int ans=0;
          for(int k=start+1;k<end;k++)
          {
              int leftTrue=helper(start,k-1,1,s,dp);
              int leftFalse=helper(start,k-1,0,s,dp);
              
              int rightTrue=helper(k+1,end,1,s,dp);
              int rightFalse=helper(k+1,end,0,s,dp);
              
              if(evaluate(1,1,s[k])==req)
                  ans+=leftTrue*rightTrue;
              if(evaluate(1,0,s[k])==req)
                  ans+=leftTrue*rightFalse;
              if(evaluate(0,1,s[k])==req)
                  ans+=leftFalse*rightTrue;
              if(evaluate(0,0,s[k])==req)
                  ans+=leftFalse*rightFalse;
              
          }
          return dp[start][end][req]=ans;
      }
      int countWays(string &s) {
          // code here
         int n=s.length();
         vector<vector<vector<int>>>dp(n,vector<vector<int>>
         (n,vector<int>(2,-1)));
         return helper(0,n-1,1,s,dp);
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 25 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


