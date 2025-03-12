-- -- -- -- -- -- -- -- -GFG - POTD - 11 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
Ways to Reach the n'2th Stair
Difficulty: MediumAccuracy: 21.9%Submissions: 219K+Points: 4
There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. Your task is to count the number of ways, the person can reach the top (order does matter).

Examples:

Input: n = 1
Output: 1
Explanation: There is only one way to climb 1 stair. 
Input: n = 2
Output: 2
Explanation: There are 2 ways to reach 2th stair: {1, 1} and {2}.  
Input: n = 4
Output: 5
Explanation: There are five ways to reach 4th stair: {1, 1, 1, 1}, {1, 1, 2}, {2, 1, 1}, {1, 2, 1} and {2, 2}.
Constraints:
1 ≤ n ≤ 44

Time Complexity: O(n)Auxiliary Space: O(1)


class Solution {
  public:
    int countWays(int n) {
        // your code here
        if(n==1) return 1;
        int a = 1,b = 1;
        for(int i=2;i<=n;i++){
            int t = a+b;
            a = b;
            b = t;
        }
        return b;
    }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 11 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

1358. Number of Substrings Containing All Three Characters
Solved
Medium
Topics
Companies
Hint
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.

class Solution {
public:
    int numberOfSubstrings(string s) {
          int count = 0;
          int left = 0;
        unordered_map<char, int> char_count = {{'a', 0}, {'b', 0}, {'c', 0}};
        
        for (int right = 0; right < s.length(); ++right) {
            char_count[s[right]]++;
            
            while (char_count['a'] > 0 && char_count['b'] > 0 && char_count['c'] > 0) {
                count += s.length() - right;
                char_count[s[left]]--;
                left++;
            }
        }
        return count;
    }
};