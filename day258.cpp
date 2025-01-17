-- -- -- -- -- -- -- -- -GFG - POTD - 11 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Longest substring with distinct characters
Difficulty: EasyAccuracy: 31.32%Submissions: 152K+Points: 2
Given a string s, find the length of the longest substring with all distinct characters. 

Examples:

Input: s = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest substring with all distinct characters.
Input: s = "aaa"
Output: 1
Explanation: "a" is the longest substring with all distinct characters.
Input: s = "abcdefabcbb"
Output: 6
Explanation: The longest substring with all distinct characters is "abcdef", which has a length of 6.
Constraints:
1<= s.size()<=3*104
All the characters are in lowercase.

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        bool freq[26] = {false};
        int maxLen = INT_MIN;
        int left = 0, right = 0;
        
        while(right < s.size()){
            //If there is repeated character 
            while(freq[s[right]-'a'] == true){
                freq[s[left]-'a'] = false;
                left++;
            }
            
            freq[s[right]-'a'] = true;
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        
        return maxLen;
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 11 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
1400. Construct K Palindrome Strings
Solved
Medium
Topics
Companies
Hint
Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

 

Example 1:

Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:

Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
Example 3:

Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters.
1 <= k <= 105

class Solution {
public:
    bool canConstruct(string s, int k) {
        // Handle edge cases
        if (s.length() < k) return false;
        if (s.length() == k) return true;

        // Initialize frequency array and oddCount integer
        vector<int> freq(26);
        int oddCount = 0;

        // Increment the value of the index corresponding to the current
        // character
        for (auto& chr : s) freq[chr - 'a']++;

        // Count the number of characters that appear an odd number of times in
        // s
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                oddCount++;
            }
        }

        // Return if the number of odd frequencies is less than or equal to k
        return (oddCount <= k);
    }
};
