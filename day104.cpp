-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 14 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Longest Common Substring
Difficulty: MediumAccuracy: 42.69%Submissions: 232K+Points: 4
You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: str1 = "ABCDGH", str2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.
Input: str1 = "ABC", str2 = "ACB"
Output: 1
Explanation: The longest common substrings are "A", "B", "C" all having length 1.
Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1<= str1.size(), str2.size()<=1000
Both strings may contain upper and lower case alphabets.

class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
    int n=str1.length(), m=str2.length();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        int maxi=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(str1[i]==str2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                    maxi=max(maxi, dp[i+1][j+1]);
                }
            }
        }
        return maxi;

    }
};

