GFG POTD 26/7/2024
K-Pangrams
Difficulty: EasyAccuracy: 20.91%Submissions: 55K+Points: 2
Given a string str and an integer k, return true if the string can be changed into a pangram after at most k operations, else return false.

A single operation consists of swapping an existing alphabetic character with any other lowercase alphabetic character.

Note - A pangram is a sentence containing every letter in the english alphabet.

Examples :

Input: str = "the quick brown fox jumps over the lazy dog", k = 0
Output: true
Explanation: the sentence contains all 26 characters and is already a pangram.
Input: str = "aaaaaaaaaaaaaaaaaaaaaaaaaa", k = 25 
Output: true
Explanation: The word contains 26 instances of 'a'. Since only 25 operations are allowed. We can keep 1 instance and change all others to make str a pangram.
Input: str = "a b c d e f g h i j k l m", k = 20
Output: false
Explanation: Since there are only 13 alphabetic characters in this case, no amount of swapping can produce a panagram here.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)  

Constraints:
1<= str.size() <= 105
0<= k <= 50
str may contain duplicate characters
str contains only lowercase alphabets or spaces.

class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
          string s = "";
        for(auto i :str)
        {
            if(i== ' ')continue;
            else s+=i;
        }
        
        if(s.length()<26)return 0;
        set<char>st;
        for(int i=0;i<s.length();i++)
        {
            st.insert(s[i]);
        }
        if(st.size()+k >=26 || st.size()>=26)return 1;
        return 0;
    
    }
};