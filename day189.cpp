-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 8 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Minimum repeat to make substring
Difficulty: MediumAccuracy: 51.22%Submissions: 56K+Points: 4
Given two strings s1 and s2. Return a minimum number of times s1 has to be repeated such that s2 is a substring of it. If s2 can never be a substring then return -1.

Note: Both the strings contain only lowercase letters.

Examples:

Input: s1 = "ww", s2 = "www"
Output: 2
Explanation: Repeating s1 two times (wwww), s2 is a substring of it.
Input: s1 = "abcd", s2 = "cdabcdab" 
Output: 3 
Explanation: Repeating s1 three times (abcdabcdabcd), s2 is a substring of it. s2 is not a substring of s2 when it is repeated less than 3 times.
Input: s1 = "ab", s2 = "cab"
Output: -1
Explanation: No matter how many times we repeat s1, we can't get a string such that s2 is a substring of it.
Constraints:
1 ≤ |s1|, |s2| ≤ 105

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
          int ans = 1 , n1 = s1.size() ;string s = s1;
        while(n1<s2.size()){
            ans++;
            n1+=s1.size();
            s+=s1;
        }
        if(s.find(s2)!=string::npos)return ans;
        ans++;
        s+=s1;
        if(s.find(s2)!=string::npos)return ans;
        return -1;
    }
};



