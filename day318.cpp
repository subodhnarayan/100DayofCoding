-- -- -- -- -- -- -- -- -GFG - POTD - 10 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
Edit Distance
Difficulty: HardAccuracy: 35.14%Submissions: 232K+Points: 8
Given two strings s1 and s2. Return the minimum number of operations required to convert s1 to s2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
Examples:

Input: s1 = "geek", s2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e' in s1.
Input: s1 = "gfg", s2 = "gfg"
Output: 0
Explanation: Both strings are same.
Input: s1 = "abcd", s2 = "bcfe"
Output: 3
Explanation: We can convert s1 into s2 by removing ‘a’, replacing ‘d’ with ‘f’ and inserting ‘e’ at the end. 
Constraints:
1 ≤ s1.length(), s2.length() ≤ 103
Both the strings are in lowercase.


class Solution {
    public:
      // Function to compute the edit distance between two strings
       int dp[1005][1005];
      int fn(string& s1, string& s2, int i , int j){
          if(j==s2.size())return s1.size()-i;
          if(i==s1.size())return s2.size()-j;
          if(dp[i][j]!=-1)return dp[i][j];
          int ans=1e5;
          if(s1[i]==s2[j])ans=min(ans,fn(s1,s2,i+1,j+1));
          ans=min(ans,fn(s1,s2,i+1,j)+1);
          ans=min(ans,fn(s1,s2,i,j+1)+1);
          ans=min(ans,fn(s1,s2,i+1,j+1)+1);
          return dp[i][j]=ans;
      }
      int editDistance(string& s1, string& s2) {
          // code here
          memset(dp,-1,sizeof(dp));
         return fn(s1,s2,0,0);
      }
  };

-- -- -- -- -- -- -- -- -LeetCode - POTD - 10 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

3306. Count of Substrings Containing Every Vowel and K Consonants II
Solved
Medium
Topics
Companies
Hint
You are given a string word and a non-negative integer k.

Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

 

Example 1:

Input: word = "aeioqq", k = 1

Output: 0

Explanation:

There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0

Output: 1

Explanation:

The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1

Output: 3

Explanation:

The substrings with every vowel and one consonant are:

word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".
 

Constraints:

5 <= word.length <= 2 * 105
word consists only of lowercase English letters.
0 <= k <= word.length - 5

