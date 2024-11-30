-- -- -- -- -- -- -- -- -GFG - POTD - 30 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Anagram
Difficulty: EasyAccuracy: 44.93%Submissions: 357K+Points: 2
Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other. Strings s1 and s2 can only contain lowercase alphabets.

Note: You can assume both the strings s1 & s2 are non-empty.

Examples :

Input: s1 = "geeks", s2 = "kseeg"
Output: true
Explanation: Both the string have same characters with same frequency. So, they are anagrams.
Input: s1 = "allergy", s2 = "allergic"
Output: false
Explanation: Characters in both the strings are not same, so they are not anagrams.
Input: s1 = "g", s2 = "g"
Output: true
Explanation: Character in both the strings are same, so they are anagrams.
Constraints:
1 ≤ s1.size(), s2.size() ≤ 105


class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        map<char,int> mp1,mp2;
        int n1=s1.size();
        int n2=s2.size();
        if(n1!=n2) return false;
        for(char c:s1){
            mp1[c]++;
        }
        for(char c:s2){
            mp2[c]++;
        }
        return mp1==mp2;
        
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 30 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


