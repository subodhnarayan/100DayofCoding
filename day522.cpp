-- -- -- -- -- -- -- -- -GFG - POTD - 03 / 06 / 2025 ----------------------------------------
Substrings with K Distinct
Difficulty: MediumAccuracy: 20.46%Submissions: 164K+Points: 4Average Time: 20m
Given a string consisting of lowercase characters and an integer k, the task is to count all possible substrings (not necessarily distinct) that have exactly k distinct characters. 

Examples :

Input: s = "abc", k = 2
Output: 2
Explanation: Possible substrings are ["ab", "bc"]
Input: s = "aba", k = 2
Output: 3
Explanation: Possible substrings are ["ab", "ba", "aba"]
Input: s = "aa", k = 1
Output: 3
Explanation: Possible substrings are ["a", "a", "aa"]
Constraints:
1 ≤ s.size() ≤ 106
1 ≤ k ≤ 26

class Solution {
  public:
    long long int solve(string s, int k) {
    int n = s.size();
        
        long long int c = 0;
        int j = 0, sz = 0;
        vector<int>mp(26, 0);
        
        for(int i=0; i<n; i++)
        {
            int ind = s[i]-'a';
            if(mp[ind] == 0) sz++;
            mp[ind]++;
            
            while(j <= i && sz > k)
            {
                mp[s[j]-'a']--;
                if(!mp[s[j]-'a']) sz--;
                j++;
            }
            if(j <= i) c += (i-j+1);
        }
        return c;
    }
    int countSubstr(string& s, int k) {
        // code here.
          return solve(s, k) -solve(s, k - 1);
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 03 / 06 / 2025 ----------------------------------------

