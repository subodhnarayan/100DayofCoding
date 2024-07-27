---------------------------------------------GFg-POTD-27/07/2024---------------------------------------------
Form a palindrome
Difficulty: MediumAccuracy: 45.4%Submissions: 106K+Points: 4
Given a string, find the minimum number of characters to be inserted to convert it to a palindrome.

Examples :

Input: str = "abcd"
Output: 3
Explanation: Inserted character marked with bold characters in dcbabcd, here we need minimum three characters to make it palindrome.
Input: str = "aa"
Output: 0
Explanation: "aa" is already a palindrome.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 ≤ |str| ≤ 500
str contains only lowercase alphabets.


class Solution{
  public:
    int countMin(string str){
     string s = str;
    reverse(s.begin(),s.end());
    int n = str.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(str[i-1]==s[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return n-dp[n][n];
    }
};