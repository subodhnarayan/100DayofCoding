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


2900. Longest Unequal Adjacent Groups Subsequence I
Solved
Easy
Topics
Companies
Hint
You are given a string array words and a binary array groups both of length n.

A subsequence of words is alternating if for any two consecutive strings in the sequence, their corresponding elements at the same indices in groups are different (that is, there cannot be consecutive 0 or 1).

Your task is to select the longest alternating subsequence from words.

Return the selected subsequence. If there are multiple answers, return any of them.

Note: The elements in words are distinct.

 

Example 1:

Input: words = ["e","a","b"], groups = [0,0,1]

Output: ["e","b"]

Explanation: A subsequence that can be selected is ["e","b"] because groups[0] != groups[2]. Another subsequence that can be selected is ["a","b"] because groups[1] != groups[2]. It can be demonstrated that the length of the longest subsequence of indices that satisfies the condition is 2.

Example 2:

Input: words = ["a","b","c","d"], groups = [1,0,1,1]

Output: ["a","b","c"]

Explanation: A subsequence that can be selected is ["a","b","c"] because groups[0] != groups[1] and groups[1] != groups[2]. Another subsequence that can be selected is ["a","b","d"] because groups[0] != groups[1] and groups[1] != groups[3]. It can be shown that the length of the longest subsequence of indices that satisfies the condition is 3.

 

Constraints:

1 <= n == words.length == groups.length <= 100
1 <= words[i].length <= 10
groups[i] is either 0 or 1.
words consists of distinct strings.
words[i] consists of lowercase English letters.