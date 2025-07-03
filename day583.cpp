-- -- -- -- -- -- -- -- -GFG - POTD - 03/ 07 / 2025 ----------------------------------------


Longest Substring with K Uniques
Difficulty: MediumAccuracy: 34.65%Submissions: 208K+Points: 4
You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
Constraints:
1 ≤ s.size() ≤ 105
1 ≤ k ≤ 26

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
           unordered_map<char,int> mp;
        int maxAns=-1;
        // traverse on the string
        int j=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        // calculate max value if we have excatly k distinct character
            if(mp.size()==k){
                int len=i-j+1;
                maxAns=max(maxAns,len);
            }
            // shrink window only if size of map is greater than k
            if(mp.size()>k){
                // remove value at jth pos
                mp[s[j]]--;
                if(mp[s[j]]==0) mp.erase(s[j]);
                j++;
                
            }
        }
        return maxAns;
    }
};



-- -- -- -- -- -- -- -- -Leetcode - POTD - 03/ 07 / 2025 ----------------------------------------

3304. Find the K-th Character in String Game I
Solved
Easy
Topics
premium lock icon
Companies
Hint
Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k.

Now Bob will ask Alice to perform the following operation forever:

Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

Note that the character 'z' can be changed to 'a' in the operation.

 

Example 1:

Input: k = 5

Output: "b"

Explanation:

Initially, word = "a". We need to do the operation three times:

Generated string is "b", word becomes "ab".
Generated string is "bc", word becomes "abbc".
Generated string is "bccd", word becomes "abbcbccd".
Example 2:

Input: k = 10

Output: "c"

 

Constraints:

1 <= k <= 500

class Solution {
public:
    char kthCharacter(int k) {
        int ans = 0;
        int t;
        while (k != 1) {
            t = __lg(k);
            if ((1 << t) == k) {
                t--;
            }
            k = k - (1 << t);
            ans++;
        }
        return 'a' + ans;
    }
};