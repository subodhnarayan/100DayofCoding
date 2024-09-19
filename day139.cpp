-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 19 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Reverse Words
Difficulty: EasyAccuracy: 56.08%Submissions: 337K+Points: 2
Given a String str, reverse the string without reversing its individual words. Words are separated by dots.

Note: The last character has not been '.'. 

Examples :

Input: str = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i
Input: str = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole string , the input string becomes mno.pqr
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 <= |str| <= 105




class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string S) {
       string ans;
        int n=S.size();
        string str="";
        for(int i=0;i<n;i++){
            if(S[i]!='.'){
                str=str+S[i];
            }
            else{
                ans=str+"."+ans;
                str="";
            }
        }
        ans=str+"."+ans;
        ans.pop_back();
        return ans;
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 19 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
