-- -- -- -- -- -- -- -- -GFG - POTD - 03 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Strings Rotations of Each Other
Difficulty: EasyAccuracy: 43.83%Submissions: 216K+Points: 2
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Examples :

Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: After 2 right rotations, s1 will become equal to s2.
Input: s1 = "aab", s2 = "aba"
Output: true
Explanation: After 1 left rotation, s1 will become equal to s2.
Input: s1 = "abcd", s2 = "acbd"
Output: false
Explanation: Strings are not rotations of each other.
Constraints:
1 <= s1.size(), s2.size() <= 105


class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    vector<int> compute(string &pat)
    {
        
        int n=pat.size();
        vector<int> lps(n,0);
        int i=0;
        int j=1;
        
        while(j<n)
        {
            if(pat[i]==pat[j])
            {
                lps[j++]=++i;
            }
            else
            {
             if(i!=0)
             {
                 i=lps[i-1];
             }
             else
             {
                 lps[j++]=0;
             }
                
            }
        }
        return lps;
        
    }
    bool areRotations(string &s1, string &s2) {
        
          if(s1.length()!=s2.length())
       return false;
       
        string txt=s1+s1;
        string pat=s2;
        
        int m=txt.length();
        int n=pat.length();
        int i=0;
        int j=0;
        vector<int> lps = compute(pat); 
        while(i<m)
        {
            if(txt[i]==pat[j])
            {
                i++;
                j++;
            }
             if(j==n)
            {
                return true;
            }
           else if(i<m && pat[j]!=txt[i])
           {
               if(j!=0)
               {
                   j=lps[j-1];
               }
               else
               i++;
           }
        }
        return false;
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 03 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

