-- -- -- -- -- -- -- -- -GFG - POTD - 10 / 06 / 2025 ----------------------------------------

Exactly one swap
Difficulty: MediumAccuracy: 48.42%Submissions: 23K+Points: 4
Given a string s, return the number of distinct strings that can be obtained by exactly one swap of two different indices (i < j).

Examples:

Input: s = "geek"
Output: 6
Explanation: After one swap, There are only 6 distinct strings possible.(i.e "egek","eegk","geek","geke","gkee" and "keeg") 
Input: s = "aaaa"
Output: 1
Explanation: Only one distinct string is possible after one swap(i.e "aaaa")
Constraints:
2 ≤ s.size() ≤ 104

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

class Solution {
  public:
    int countStrings(string &s) {
        // code here
       vector<int> freq(26, 0);
        int n = s.size();
    
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }
    
        int count = 0;
        bool flag=false;
        for (int i = 0; i < n; i++) {
            if(freq[s[i]-'a']>0)
            {
                count+=(n-freq[s[i]-'a']);
            }
            if(freq[s[i]-'a']>1)
            {
                flag=true;
            }
        }
        count/=2;
        return flag?count+1:count; 
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 10 / 06 / 2025 ----------------------------------------



3442. Maximum Difference Between Even and Odd Frequency I
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

a1 has an odd frequency in the string.
a2 has an even frequency in the string.
Return this maximum difference.

 

Example 1:

Input: s = "aaaaabbc"

Output: 3

Explanation:

The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
The maximum difference is 5 - 2 = 3.
Example 2:

Input: s = "abcabcab"

Output: 1

Explanation:

The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
The maximum difference is 3 - 2 = 1.
 

Constraints:

3 <= s.length <= 100
s consists only of lowercase English letters.
s contains at least one character with an odd frequency and one with an even frequency.


class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> c;
        for (char ch : s) {
            ++c[ch];
        }
        int maxOdd = 1, minEven = s.size();
        for (const auto& [_, value] : c) {
            if (value % 2 == 1) {
                maxOdd = max(maxOdd, value);
            } else {
                minEven = min(minEven, value);
            }
        }
        return maxOdd - minEven;
    }
};