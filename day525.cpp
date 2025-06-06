-- -- -- -- -- -- -- -- -GFG - POTD - 06 / 06 / 2025 ----------------------------------------
Search Pattern (Rabin-Karp Algorithm)
Difficulty: MediumAccuracy: 34.53%Submissions: 81K+Points: 4Average Time: 20m
Given two strings:

A text string in which you want to search.

A pattern string that you are looking for within the text.

Return all positions (1-based indexing) where the pattern occurs as a substring in the text. If the pattern does not occur, return an empty list.

All characters in both strings are lowercase English letters (a to z).

Examples:

Input: text = "birthdayboy", pattern = "birth"
Output: [1]
Explanation: The string "birth" occurs at index 1 in text.
Input: text = "geeksforgeeks", pattern = "geek"
Output: [1, 9]
Explanation: The string "geek" occurs twice in text, one starts are index 1 and the other at index 9.
Constraints:
1<= text.size() <=5*105
1<= pattern.size() <= text.size()

Expected Complexities
Time Complexity: O(n + m)
Auxiliary Space: O(1)

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here.
         int n = txt.length();
        int m = pat.length();
        
        vector <int> ans;
        vector <int> freqPt(26, 0);
        vector <int> freqTxt(26, 0);
        
        for(int i = 0; i < m; i++){
            freqPt[pat[i] - 'a']++;
            freqTxt[txt[i] - 'a']++;
        }
        
        for(int i = 0; i <= n-m; i++){
            if(freqPt == freqTxt){
                bool match = true;
                for(int j = 0; j < m; j++){
                    if(pat[j] != txt[i + j]){
                        match = false;
                        break;
                    }
                }
                
                if(match) ans.push_back(i+1);
            }
            
             if (i + m < n) {
                freqTxt[txt[i] - 'a']--;
                freqTxt[txt[i + m] - 'a']++;
            }
        }
        
        return ans;
    }
};
-- -- -- -- -- -- -- -- -Leetcode - POTD - 06 / 06 / 2025 ----------------------------------------

2434. Using a Robot to Print the Lexicographically Smallest String
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a string s and a robot that currently holds an empty string t. Apply one of the following operations until s and t are both empty:

Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
Remove the last character of a string t and give it to the robot. The robot will write this character on paper.
Return the lexicographically smallest string that can be written on the paper.

 

Example 1:

Input: s = "zza"
Output: "azz"
Explanation: Let p denote the written string.
Initially p="", s="zza", t="".
Perform first operation three times p="", s="", t="zza".
Perform second operation three times p="azz", s="", t="".
Example 2:

Input: s = "bac"
Output: "abc"
Explanation: Let p denote the written string.
Perform first operation twice p="", s="c", t="ba". 
Perform second operation twice p="ab", s="c", t="". 
Perform first operation p="ab", s="", t="c". 
Perform second operation p="abc", s="", t="".
Example 3:

Input: s = "bdda"
Output: "addb"
Explanation: Let p denote the written string.
Initially p="", s="bdda", t="".
Perform first operation four times p="", s="", t="bdda".
Perform second operation four times p="addb", s="", t="".
 

Constraints:

1 <= s.length <= 105
s consists of only English lowercase letters.

