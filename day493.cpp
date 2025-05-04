-- -- -- -- -- -- -- -- -GFG - POTD - 04 / 05 / 2025 -----------------------------------
Smallest distinct window
Difficulty: MediumAccuracy: 31.85%Submissions: 109K+Points: 4
Given a string str, your task is to find the length of the smallest window that contains all the characters of the given string at least once.

Example:

Input: str = "aabcbcdbca"
Output: 4
Explanation: Sub-String "dbca" has the smallest length that contains all the characters of str.
Input: str = "aaab"
Output: 2
Explanation: Sub-String "ab" has the smallest length that contains all the characters of str.
Input: str = "geeksforgeeks"
Output: 8
Explanation: There are multiple substring with smallest length that contains all characters of str, "geeksfor" and "forgeeks". 
Constraints:
1 ≤ str.size() ≤ 105
str contains only lower-case english alphabets.

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

class Solution {
    public:
      int findSubString(string& str) {
          // code here
         int first=0,second=0,diff=0,len=str.size();
          vector<int> count(256,0);
          while(first<str.size())
          {
              if(count[str[first]]==0)
              diff++;
              
              count[str[first]]++;
              first++;
          }
          
          for(int i=0;i<256;i++)
          {
              count[i]=0;
          }
          first=0;
          while(second<str.size())
          {
              while(diff && second<str.size())
          {
              if(count[str[second]]==0)
              diff--;
              
              count[str[second]]++;
              second++;
          }
              
              len=min(len,second-first);
              
              while(diff!=1)
              {
                   
              len=min(len,second-first);
              count[str[first]]--;
              
              if(count[str[first]]==0)
              diff++;
              
              first++;
              }
          }
          return len; 
      }
  };



-- -- -- -- -- -- -- -- -Leetcode - POTD - 04 / 05 / 2025 -----------------------------------



1128. Number of Equivalent Domino Pairs
Solved
Easy
Topics
Companies
Hint
Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

 

Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
Example 2:

Input: dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
Output: 3
 

Constraints:

1 <= dominoes.length <= 4 * 104
dominoes[i].length == 2
1 <= dominoes[i][j] <= 9

class Solution {
    public:
       struct hash_pair {
                size_t operator()(const pair<int,int>& p) const {
                    return p.first * 31 + p.second;
                }
        };
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
            unordered_map<pair<int,int>, int, hash_pair> mpp;
        
                for (auto& d : dominoes) {
                    if (d[0] > d[1]) swap(d[0], d[1]);
                    mpp[{d[0], d[1]}]++;
                }
        
                int count = 0;
                for (auto& [d, freq] : mpp)
                    count += freq * (freq - 1) / 2;
        
                return count;
        }
};