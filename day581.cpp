-- -- -- -- -- -- -- -- -GFG - POTD - 01/ 07 / 2025 ----------------------------------------


Substrings of length k with k-1 distinct elements
Difficulty: MediumAccuracy: 57.85%Submissions: 36K+Points: 4Average Time: 15m
Given a string s consisting only lowercase alphabets and an integer k. Find the count of all substrings of length k which have exactly k-1 distinct characters.

Examples:

Input: s = "abcc", k = 2
Output: 1
Explaination: Possible substring of length k = 2 are,
ab : 2 distinct characters
bc : 2 distinct characters
cc : 1 distinct characters
Only one valid substring so, count is equal to 1.
Input: "aabab", k = 3
Output: 3
Explaination: Possible substring of length k = 3 are, 
aab : 2 distinct charcters
aba : 2 distinct characters
bab : 2 distinct characters
All these substring are valid so, the total count is equal to 3.
Constrains:
1 ≤ s.size() ≤ 105
2 ≤ k ≤ 27

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)


class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
       unordered_map<char, int>mp;
        int ans=0;
        for(int i=0; i<k; i++){mp[s[i]]++;}
        if(mp.size()==k-1){ans++;}
        for(int i=k, j=0;i<s.size(); i++, j++){
           if(mp[s[j]]==1){mp.erase(s[j]);}
           else{mp[s[j]]--;}
           mp[s[i]]++;
           if(mp.size()==k-1){ans++;}
        }
        return ans;
    }


-- -- -- -- -- -- -- -- -Leetcode - POTD - 01/ 07 / 2025 ----------------------------------------


Code
Testcase
Testcase
Test Result
3330. Find the Original Typed String I
Solved
Easy
Topics
premium lock icon
Companies
Hint
Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.

You are given a string word, which represents the final output displayed on Alice's screen.

Return the total number of possible original strings that Alice might have intended to type.

 

Example 1:

Input: word = "abbcccc"

Output: 5

Explanation:

The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".

Example 2:

Input: word = "abcd"

Output: 1

Explanation:

The only possible string is "abcd".

Example 3:

Input: word = "aaaa"

Output: 4

 

Constraints:

1 <= word.length <= 100
word consists only of lowercase English letters.

class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size(), ans = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i - 1] == word[i]) {
                ++ans;
            }
        }
        return ans;
    }
};