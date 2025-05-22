-- -- -- -- -- -- -- -- -GFG - POTD - 22 / 05 / 2025 ----------------------------------------

Minimum Deletions
Difficulty: MediumAccuracy: 58.8%Submissions: 67K+Points: 4
Given a string s, write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome, while maintaining the order of characters.

Examples:

Input: s = "aebcbda"
Output: 2
Explanation: Remove characters 'e' and 'd'.
Input: s = "geeksforgeeks"
Output: 8
Explanation: To make "geeksforgeeks" a palindrome, the longest palindromic subsequence is "eefee" (length 5). The minimum deletions are:
13 (length of s) - 5 = 8.
Constraints:
1 ≤ s.size() ≤ 103

Expected Complexities
Time Complexity: O(n^2)
Auxiliary Space: O(n)

class Solution {
  public:
    int minDeletions(string s) {
        // code here
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        vector<int> dp1(n+1,0),dp2(n+1,0);
        string s2=s;
        reverse(s2.begin(),s2.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s2[j-1]){
                    dp2[j]=1+dp1[j-1];
                }else{
                    dp2[j]=max(dp2[j-1],dp1[j]);
                }
            }
            dp1=dp2;
        }
    return n-dp2[n];
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 22 / 05 / 2025 ----------------------------------------

