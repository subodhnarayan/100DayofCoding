-- -- -- -- -- -- -- -- -GFG - POTD - 26 / 06 / 2025 ----------------------------------------

Game with String
Difficulty: MediumAccuracy: 53.96%Submissions: 66K+Points: 4Average Time: 15m
Given a string s consisting of lowercase alphabets and an integer k, your task is to find the minimum possible value of the string after removing exactly k characters.

The value of the string is defined as the sum of the squares of the frequencies of each distinct character present in the string.

Examples :

Input: s = "abbccc", k = 2
Output: 6
Explaination: We remove two 'c' to get the value as 12 + 22 + 12 = 6 or We remove one 'b' and one 'c' to get the value 12 + 12 + 22 = 6.
Input: s = "aaab", k = 2
Output: 2
Explaination: We remove two 'a'. Now we get the value as 12 + 12 = 2.
Constraints:
0 ≤ k ≤ s.length() ≤ 105 

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        priority_queue<int>pq;
        vector<int>v(26,0);
        for(auto &b: s){v[b-'a']++;}
        for(auto &b: v){
            if(b!=0){pq.push(b);}
        }
        while(k--){
            int x=pq.top(); pq.pop();
            x--;
            pq.push(x);
        }
        int ans=0;
        while(pq.size()){
            ans+=(pq.top()*pq.top()); pq.pop();
        }
        return ans;
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 26 / 06 / 2025 ----------------------------------------


2311. Longest Binary Subsequence Less Than or Equal to K
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a binary string s and a positive integer k.

Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.

Note:

The subsequence can contain leading zeroes.
The empty string is considered to be equal to 0.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
 

Example 1:

Input: s = "1001010", k = 5
Output: 5
Explanation: The longest subsequence of s that makes up a binary number less than or equal to 5 is "00010", as this number is equal to 2 in decimal.
Note that "00100" and "00101" are also possible, which are equal to 4 and 5 in decimal, respectively.
The length of this subsequence is 5, so 5 is returned.
Example 2:

Input: s = "00101001", k = 1
Output: 6
Explanation: "000001" is the longest subsequence of s that makes up a binary number less than or equal to 1, as this number is equal to 1 in decimal.
The length of this subsequence is 6, so 6 is returned.
 

Constraints:

1 <= s.length <= 1000
s[i] is either '0' or '1'.
1 <= k <= 109