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


476. Number Complement
Solved
Easy
Topics
Companies
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
Given an integer num, return its complement.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
 

Constraints:

1 <= num < 231



class Solution {
public:
    int findComplement(int num) {
        // if(num==0) return 1;
        // int len=(int)(log2(num))+1;
        // int mask=(1<<len)-1;
        // return mask^num;
         if (num==1) return 0;
        int ans=0;
        for(int b=0; num; b++, num>>=1){// num/=2
            ans+=(1-(num&1))<<b;// (num%2==0?1:0)*(1<<b)
        }
        return ans;
    }
};