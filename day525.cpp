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
