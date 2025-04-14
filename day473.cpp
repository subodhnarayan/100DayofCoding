-- -- -- -- -- -- -- -- -GFG - POTD - 14 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


Alien Dictionary
Difficulty: HardAccuracy: 47.81%Submissions: 160K+Points: 8
A new alien language uses the English alphabet, but the order of letters is unknown. You are given a list of words[] from the alien language’s dictionary, where the words are claimed to be sorted lexicographically according to the language’s rules.

Your task is to determine the correct order of letters in this alien language based on the given words. If the order is valid, return a string containing the unique letters in lexicographically increasing order as per the new language's rules. If there are multiple valid orders, return any one of them.

However, if the given arrangement of words is inconsistent with any possible letter ordering, return an empty string ("").

A string a is lexicographically smaller than a string b if, at the first position where they differ, the character in a appears earlier in the alien language than the corresponding character in b. If all characters in the shorter word match the beginning of the longer word, the shorter word is considered smaller.

Note: Your implementation will be tested using a driver code. It will print true if your returned order correctly follows the alien language’s lexicographic rules; otherwise, it will print false.

Examples:

Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' → 'd' → 'a' → 'c' is a valid ordering.
Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible corrct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary. 
So, 'c' → 'a' → 'b' is a valid ordering.
Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.
Constraints:
1 ≤ words.length ≤ 500
1 ≤ words[i].length ≤ 100
words[i] consists only of lowercase English letters.

Expected Complexities
Time Complexity: O(n * m)
Auxiliary Space: O(n * m)



class Solution {
    public:
    bool iscycle(int node, vector<bool>& vis, vector<bool>& dfsvis, vector<vector<int>>& adj) {
      vis[node] = true;
      dfsvis[node] = true;
  
      for (auto it : adj[node]) {
          if (!vis[it]) {
              if (iscycle(it, vis, dfsvis, adj)) return true;
          } else if (dfsvis[it]) {
              return true;
          }
      }
  
      dfsvis[node] = false;
      return false;
  }
  
  // DFS function for topological sorting
  void DFS(int node, stack<int>& st, vector<bool>& vis, vector<vector<int>>& adj) {
      vis[node] = true;
      for (auto it : adj[node]) {
          if (!vis[it]) {
              DFS(it, st, vis, adj);
          }
      }
      st.push(node);
  }
      string findOrder(vector<string> &words) {
          // code here
          unordered_map<char, int> char_to_index;
      unordered_map<int, char> index_to_char;
      int index = 0;
  
      // Step 1: Assign unique indices to all characters
      for (auto& word : words) {
          for (char ch : word) {
              if (char_to_index.find(ch) == char_to_index.end()) {
                  char_to_index[ch] = index;
                  index_to_char[index] = ch;
                  index++;
              }
          }
      }
  
      int k = index;  // Total unique characters
      vector<vector<int>> adj(k);
  
      // Step 2: Build graph with prefix check
      for (int i = 0; i < words.size() - 1; i++) {
          string& s1 = words[i];
          string& s2 = words[i + 1];
          int len = min(s1.size(), s2.size());
  
          bool found = false;
          for (int j = 0; j < len; j++) {
              if (s1[j] != s2[j]) {
                  int u = char_to_index[s1[j]];
                  int v = char_to_index[s2[j]];
                  adj[u].push_back(v);
                  found = true;
                  break;
              }
          }
  
          // ❗ Invalid order if s1 is longer and s2 is prefix of s1
          if (!found && s1.size() > s2.size()) {
              return "";  // Invalid lexicographical order
          }
      }
  
      // Step 3: Cycle detection
      vector<bool> vis(k, false), dfsvis(k, false);
      for (int i = 0; i < k; i++) {
          if (!vis[i]) {
              if (iscycle(i, vis, dfsvis, adj)) return "";
          }
      }
  
      // Step 4: Topological sort
      stack<int> st;
      vector<bool> vis2(k, false);
      for (int i = 0; i < k; i++) {
          if (!vis2[i]) {
              DFS(i, st, vis2, adj);
          }
      }
  
      // Step 5: Create result from topological order
      string res = "";
      while (!st.empty()) {
          res += index_to_char[st.top()];
          st.pop();
      }
  
      return res;
      }
  };

-- -- -- -- -- -- -- -- -LeetCode - POTD - 14 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
