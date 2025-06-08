-- -- -- -- -- -- -- -- -GFG - POTD - 08 / 06 / 2025 ----------------------------------------
Sum-string
Difficulty: HardAccuracy: 50.56%Submissions: 40K+Points: 8
Given a string s consisting of digits, determine whether it can be classified as a sum-string.

A sum-string is a string that can be split into more than two non-empty substrings such that:


The rightmost substring is equal to the sum of the two substrings immediately before it (interpreted as integers).

This condition must apply recursively to the substrings before it.

The rightmost substring (and any number in the sum) must not contain leading zeroes, unless the number is exactly '0'.

Examples:

Input: s = "12243660"
Output: true
Explanation: The string can be split as {"12", "24", "36", "60"} where each number is the sum of the two before it:
36 = 12 + 24, and 60 = 24 + 36. Hence, it is a sum-string.
Input: s = "1111112223"
Output: true
Explanation: Split the string as {"1", "111", "112", "223"}, where:
112 = 1 + 111 and 223 = 111 + 112. Hence, it follows the sum-string rule.
Input: s = "123456"
Output: false
Explanation: There is no valid split of the string such that each part satisfies the sum-string property recursively.
Constraints:
1 ≤ s.size() ≤ 100
String consists of characters from '0' to '9'.

Expected Complexities
Time Complexity: O(n^3)
Auxiliary Space: O(n)


-- -- -- -- -- -- -- -- -Leetcode - POTD - 08 / 06 / 2025 ----------------------------------------

3170. Lexicographically Minimum String After Removing Stars
Solved
Medium
Topics
premium lock icon
Companies
You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.

 

Example 1:

Input: s = "aaba*"

Output: "aab"

Explanation:

We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

Example 2:

Input: s = "abc"

Output: "abc"

Explanation:

There is no '*' in the string.

 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters and '*'.
The input is generated such that it is possible to delete all '*' characters.


class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> cnt(26);
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                cnt[s[i]-'a'].push(i);
            }
            else{
                for(int j=0;j<26;j++){
                    if(!cnt[j].empty()){
                        s[cnt[j].top()]='*';
                        cnt[j].pop();
                        break;
                    }
                }
            }
        }

        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};


