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

2109. Adding Spaces to a String
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed string s and a 0-indexed integer array spaces that describes the indices in the original string where spaces will be added. Each space should be inserted before the character at the given index.

For example, given s = "EnjoyYourCoffee" and spaces = [5, 9], we place spaces before 'Y' and 'C', which are at indices 5 and 9 respectively. Thus, we obtain "Enjoy Your Coffee".
Return the modified string after the spaces have been added.

 

Example 1:

Input: s = "LeetcodeHelpsMeLearn", spaces = [8,13,15]
Output: "Leetcode Helps Me Learn"
Explanation: 
The indices 8, 13, and 15 correspond to the underlined characters in "LeetcodeHelpsMeLearn".
We then place spaces before those characters.
Example 2:

Input: s = "icodeinpython", spaces = [1,5,7,9]
Output: "i code in py thon"
Explanation:
The indices 1, 5, 7, and 9 correspond to the underlined characters in "icodeinpython".
We then place spaces before those characters.
Example 3:

Input: s = "spacing", spaces = [0,1,2,3,4,5,6]
Output: " s p a c i n g"
Explanation:
We are also able to place spaces before the first character of the string.
 

Constraints:

1 <= s.length <= 3 * 105
s consists only of lowercase and uppercase English letters.
1 <= spaces.length <= 3 * 105
0 <= spaces[i] <= s.length - 1
All the values of spaces are strictly increasing.


class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        sort(spaces.begin(), spaces.end());

        int n = s.length(), m = spaces.size();
        string ans = "";
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (j < m && i == spaces[j])
            {
                ans.push_back(' ');
                j++;
            }

            ans.push_back(s[i]);
        }

        return ans;
    }
};