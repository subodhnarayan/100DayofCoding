-- -- -- -- -- -- -- -- -GFG - POTD - 25 / 06 / 2025 ----------------------------------------

Check if frequencies can be equal
Difficulty: MediumAccuracy: 16.67%Submissions: 134K+Points: 4
Given a string s consisting only lowercase alphabetic characters, check whether it is possible to remove at most one character such that the  frequency of each distinct character in the string becomes same. Return true if it is possible; otherwise, return false.

Examples:

Input: s = "xyyz"
Output: true 
Explanation: Removing one 'y' will make frequency of each distinct character to be 1.
Input: s = "xyyzz"
Output: true
Explanation: Removing one 'x' will make frequency of each distinct character to be 2.
Input: s = "xxxxyyzz"
Output: false
Explanation: Frequency can not be made same by removing at most one character.
Constraints:
1 ≤ s.size() ≤ 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int> mp(26, 0);
        for(char ch : s) mp[ch - 'a']++;
        unordered_set<int> ss;
        int mx = 0, mn = 100000;
        unordered_map<int, int> freq;
        for(int i = 0 ; i < 26 ; i++) {
            if(mp[i] != 0) {
                ss.insert(mp[i]);
                freq[mp[i]]++;
                mx = max(mx, mp[i]);
                mn = min(mn, mp[i]);
            }
        }
        if(ss.size() > 2) return false;
        if((mx == mn) || (mn == 1 && freq[mn] == 1) || (freq[mx] == 1 && mx - mn == 1)) return true;
        return false;
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 25 / 06 / 2025 ----------------------------------------




