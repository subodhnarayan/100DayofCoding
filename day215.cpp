-- -- -- -- -- -- -- -- -GFG - POTD - 03 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Min Chars to Add for Palindrome
Difficulty: HardAccuracy: 46.79%Submissions: 65K+Points: 8
Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.

Examples:

Input: s = "abc"
Output: 2
Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"
Input: s = "aacecaaaa"
Output: 2
Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"
Constraints:
1 <= s.size() <= 106


class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        string rev = s; 
        reverse(rev.begin(), rev.end()); 
        string complete = s + '$' + rev; 

        int n = complete.length();
        int i = 0, j = 1;
        vector<int> helperArr(n, 0); 

      
        while (j < n) {
            if (complete[i] == complete[j]) {
                helperArr[j++] = ++i; 
            } else if (i != 0) {
                i = helperArr[i - 1]; 
            } else {
                j++; 
            }
        }

        // The LPS value at the end tells us the length of the longest palindrome suffix
        int longest_palindrome_suffix = helperArr[n - 1];

        // The result is the number of characters to be added at the beginning
        return s.length() - longest_palindrome_suffix;


    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 03 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

