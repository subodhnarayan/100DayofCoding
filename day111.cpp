- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 22 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Alien Dictionary
Difficulty: HardAccuracy: 47.81%Submissions: 122K+Points: 8
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.

Examples :

Input:  n = 5, k = 4, dict = {"baa","abcd","abca","cab","cad"}
Output: 1
Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
Input: n = 3, k = 3, dict = {"caa","aaa","aab"}
Output: 1
Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.
Expected Time Complexity: O(n * |s| + k)
Expected Auxillary Space: O(k)

Constraints:
1 ≤ n≤ 104
1 ≤ k ≤ 26
1 ≤ Length of words ≤ 50



class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
      vector<int> adj[k],indeg(k);
      
      for(int i=0;i<n-1;i++){
          string s1=dict[i];
          string s2=dict[i+1];
          
          int len=min(s1.length(),s2.length());
          
          for(int j=0;j<len;j++){
             if(s1[j]!=s2[j]){
                adj[s1[j]-'a'].push_back(s2[j]-'a');
                indeg[s2[j]-'a']++;
                break;
             }
          }
      }
    

      queue<int> q;
        for(int i=0;i<k;i++) {
            if(indeg[i] == 0) q.push(i);
        }
        string ans;
        while(q.size()) {
            int node = q.front();
            q.pop();
            ans.push_back(char(node + 'a'));
            for(int i : adj[node]) {
                indeg[i]--;
                if(indeg[i] == 0) q.push(i);
            }
        }
        return ans;
    }
};