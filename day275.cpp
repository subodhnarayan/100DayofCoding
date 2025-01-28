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


Time Complexity: O(n! * n)Auxiliary Space: O(n)

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


2658. Maximum Number of Fish in a Grid
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

A land cell if grid[r][c] = 0, or
A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of times:

Catch all the fish at cell (r, c), or
Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.

An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

 

Example 1:


Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.
Example 2:


Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
0 <= grid[i][j] <= 10


class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int Max = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] > 0) {
                    int C = 0;
                    queue<pair<int, int>> T;
                    T.push({i, j});
                    while (!T.empty()) {
                        auto [x, y] = T.front();
                        T.pop();
                        if (grid[x][y] > 0) {
                            C += grid[x][y];
                            grid[x][y] = 0; // Mark as visited
                            if (x > 0 && grid[x - 1][y] > 0) T.push({x - 1, y});
                            if (x + 1 < grid.size() && grid[x + 1][y] > 0) T.push({x + 1, y});
                            if (y > 0 && grid[x][y - 1] > 0) T.push({x, y - 1});
                            if (y + 1 < grid[0].size() && grid[x][y + 1] > 0) T.push({x, y + 1});
                        }
                    }
                    Max = max(Max, C);
                }
            }
        }
        return Max;
    }
};