-- -- -- -- -- -- -- -- -GFG - POTD - 05 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Longest String Chain
Difficulty: MediumAccuracy: 50.0%Submissions: 19K+Points: 4Average Time: 20m
You are given an array of words where each word consists of lowercase English letters.
wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB. For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".

A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k = 1.

Return the length of the longest possible word chain with words chosen from the given list of words in any order.

Examples:

Input: words[] = ["ba", "b", "a", "bca", "bda", "bdca"]
Output: 4
Explanation: One of the longest word chains is ["a", "ba", "bda", "bdca"].
Input: words[] = ["abc", "a", "ab"]
Output: 3
Explanation: The longest chain is {"a", "ab" "abc"}
Input: words[] = ["abcd", "dbqca"]
Output: 1
Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
Constraint:
1 <= words.length <= 104
1 <= words[i].length <= 10
 words[i] only consists of lowercase English letters.


 class Solution {
    public:
      static bool comp(string &s1,string &s2){
          return s1.size()<s2.size();
      }
      int longestStringChain(vector<string>& words) {
          // Code here
          sort(words.begin(),words.end(),comp);
          unordered_map<string,int> mp;
          int ans=1;
          for(string &w:words){
              int length=1;
              for(int i=0;i<w.size();i++){
                  string pred=w.substr(0,i)+w.substr(i+1);
                  if(mp.find(pred)!=mp.end()){
                      length=max(length,mp[pred]+1);
                  }
              }
              mp[w]=length;
              ans=max(ans,length);
          }
          return ans;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 05 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


2579. Count Total Number of Colored Cells
Solved
Medium
Topics
Companies
Hint
There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:

At the first minute, color any arbitrary unit cell blue.
Every minute thereafter, color blue every uncolored cell that touches a blue cell.
Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.


Return the number of colored cells at the end of n minutes.

 

Example 1:

Input: n = 1
Output: 1
Explanation: After 1 minute, there is only 1 blue cell, so we return 1.
Example 2:

Input: n = 2
Output: 5
Explanation: After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5. 
 

Constraints:

1 <= n <= 105


class Solution {
    public:
        long long coloredCells(int n) {
            if(n==1) return 1;
            long long temp=4;
            long long ans=1;
            for(int i=2;i<=n;i++){
                ans=ans+temp;
                temp=temp+4;
            }
            return ans;
        }
};