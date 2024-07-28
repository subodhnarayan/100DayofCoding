-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFg - POTD - 28 / 07 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Given a string str without spaces, the task is to remove all duplicate characters from it, keeping only the first occurrence.

Note: The original order of characters must be kept the same. 

Examples :

Input: str = "zvvo"
Output: "zvo"
Explanation: Only keep the first occurrence
Input: str = "gfg"
Output: "gf"
Explanation: Only keep the first occurrence
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= |str| <= 105
str contains lowercase English alphabets

class Solution {
  public:

    string removeDups(string str) {
           set<char>s;
        string ans="";
        for(int i=0;i<str.size();i++){
            if(s.find(str[i])==s.end()){
                ans+=str[i];
                s.insert(str[i]);
               
            }
        }
        return ans;
    }
};