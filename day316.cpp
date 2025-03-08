-- -- -- -- -- -- -- -- -GFG - POTD - 08 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
Longest Palindrome in a String
Difficulty: MediumAccuracy: 23.2%Submissions: 322K+Points: 4
Given a string s, your task is to find the longest palindromic substring within s.

A substring is a contiguous sequence of characters within a string, defined as s[i...j] where 0 ≤ i ≤ j < len(s).

A palindrome is a string that reads the same forward and backward. More formally, s is a palindrome if reverse(s) == s.

Note: If there are multiple palindromic substrings with the same length, return the first occurrence of the longest palindromic substring from left to right.

Examples :

Input: s = “forgeeksskeegfor” 
Output: “geeksskeeg”
Explanation: There are several possible palindromic substrings like “kssk”, “ss”, “eeksskee” etc. But the substring “geeksskeeg” is the longest among all.
Input: s = “Geeks” 
Output: “ee”
Explanation: "ee" is the longest palindromic substring of "Geeks". 
Input: s = “abc” 
Output: “a”
Explanation: "a", "b" and "c" are longest palindromic substrings of same length. So, the first occurrence is returned.
Constraints:
1 ≤ s.size() ≤ 103
s consist of only lowercase English letters.

Expected Complexities
Time Complexity: O(n^2)Auxiliary Space: O(1)


class Solution {
  public:
    bool check(int i, int j, string& s) {
        
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string &s) {
        // code here
        int n = s.length();
        string ans =  "";
        string t = "";
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(i,j,s)){
                    t = s.substr(i,j-i+1);
                    if(t.length() > ans.length()){
                        ans = t;
                        t = "";
                    }
                }
            }
        }
        return ans;
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 08 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- ------
2379. Minimum Recolors to Get K Consecutive Black Blocks
Solved
Easy
Topics
Companies
Hint
You are given a 0-indexed string blocks of length n, where blocks[i] is either 'W' or 'B', representing the color of the ith block. The characters 'W' and 'B' denote the colors white and black, respectively.

You are also given an integer k, which is the desired number of consecutive black blocks.

In one operation, you can recolor a white block such that it becomes a black block.

Return the minimum number of operations needed such that there is at least one occurrence of k consecutive black blocks.

 

Example 1:

Input: blocks = "WBBWWBBWBW", k = 7
Output: 3
Explanation:
One way to achieve 7 consecutive black blocks is to recolor the 0th, 3rd, and 4th blocks
so that blocks = "BBBBBBBWBW". 
It can be shown that there is no way to achieve 7 consecutive black blocks in less than 3 operations.
Therefore, we return 3.
Example 2:

Input: blocks = "WBWBBBW", k = 2
Output: 0
Explanation:
No changes need to be made, since 2 consecutive black blocks already exist.
Therefore, we return 0.
 

Constraints:

n == blocks.length
1 <= n <= 100
blocks[i] is either 'W' or 'B'.
1 <= k <= n

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0, numWhites = 0, numRecolors = INT_MAX;

        // Move right pointer
        for (int right = 0; right < blocks.size(); right++) {
            // Increment numWhites if block at right pointer is white
            if (blocks[right] == 'W') {
                numWhites++;
            }

            // k consecutive elements are found
            if (right - left + 1 == k) {
                // Update minimum
                numRecolors = min(numRecolors, numWhites);

                // Decrement numWhites if block at left pointer is white
                if (blocks[left] == 'W') numWhites--;

                // Move left pointer
                left++;
            }
        }
        return numRecolors;
    }
};
