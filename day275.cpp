-- -- -- -- -- -- -- -- -GFG - POTD - 28 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Permutations of a String
Difficulty: MediumAccuracy: 34.65%Submissions: 294K+Points: 4
Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order.

Examples:

Input: s = "ABC"
Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
Explanation: Given string ABC has 6 unique permutations.
Input: s = "ABSG"
Output: ["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", "GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]
Explanation: Given string ABSG has 24 unique permutations.
Input: s = "AAA"
Output: ["AAA"]
Explanation: No other unique permutations can be formed as all the characters are same.
Constraints:
1 <= s.size() <= 9
s contains only Uppercase english alphabets


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void getallperm(int ind,string &s,vector<string> &ans,unordered_set<string> &seen){
	          if (ind == s.size()) {
        if (seen.find(s) == seen.end()) {
            ans.push_back(s);
            seen.insert(s);
        }
        return;
    }
	 for (int i = ind; i < s.size(); i++) {
        // Ensure we don't swap duplicate characters in the same position
        bool shouldSwap = true;
        for (int j = ind; j < i; j++) {
            if (s[j] == s[i]) {
                shouldSwap = false;
                break;
            }
        }
        if (!shouldSwap) continue;

        std::swap(s[ind], s[i]);
        getallperm(ind + 1, s, ans, seen);
        std::swap(s[ind], s[i]); // Backtrack to original string
    }
	    }
    vector<string> findPermutation(string &S) {
         sort(S.begin(), S.end());
		    vector<string> ans;
		    unordered_set<std::string> seen;
		    getallperm(0,S,ans,seen);
		    return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends



-- -- -- -- -- -- -- -- -LeetCode - POTD - 28 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


