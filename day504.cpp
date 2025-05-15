-- -- -- -- -- -- -- -- -GFG - POTD - 15 / 05 / 2025 ----------------------------------------

Substrings with same first and last characters
Difficulty: EasyAccuracy: 50.0%Submissions: 26K+Points: 2
Given a string s consisting of lowercase characters, the task is to find the count of all substrings that start and end with the same character.

Examples:

Input: s = "abcab"
Output: 7
Explanation: There are 7 substrings where the first and last characters are the same: "a", "abca", "b", "bcab", "c", "a", and "b"
Input: s = "aba"
Output: 4
Explanation: There are 4 substrings where the first and last characters are the same: "a", "aba", "b", "a"
Constraints:
1 <= |s| <= 104
s contains lower case english alphabets

class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        unordered_map<char,int> mp;
        int sum = 0;
        
        for(auto &it : s)
        {
            mp[it]++;
        }
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++)
        {
            int n = itr->second;
            sum += n*(n+1)/2;
        }
        return sum;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 15 / 05 / 2025 ----------------------------------------
