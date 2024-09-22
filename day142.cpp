-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 22 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Longest Prefix Suffix
Difficulty: HardAccuracy: 27.91%Submissions: 129K+Points: 8
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Examples :

Input: str = "abab"
Output: 2
Explanation: "ab" is the longest proper prefix and suffix. 
Input: str = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper prefix and suffix. 
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 106
str contains lower case English alphabets


class Solution {
  public:
    int lps(string str) {
        // Your code goes here
           int p=0;
        int s=1;
        int cnt=0;
        int pos=1;
        int n=str.size();
        while(p<n && s<n)
        {
            if(str[p]==str[s])
            {
                cnt++;
                p++;
                s++;
            }
            else
            {
                cnt=0;
                pos++;
                s=pos;
                p=0;
                
            }
        }
        return cnt;
    }
};

-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 22 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


386. Lexicographical Numbers
Solved
Medium
Topics
Companies
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]
 

Constraints:

1 <= n <= 5 * 104

