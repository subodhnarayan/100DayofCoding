-- -- -- -- -- -- -- -- -GFG - POTD - 29 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Add Binary Strings
Difficulty: MediumAccuracy: 23.25%Submissions: 76K+Points: 4
Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Input: s1 = "00100", s2 = "010"
Output: 110
Explanation: 
  100
+  10
  110
Constraints:
1 ≤s1.size(), s2.size()≤ 106



class Solution {
  public:
   string find(string &str1,string &str2){
      
       int n=str1.size(),m=str2.size();
      
      int i=n-1,j=m-1;
      int carry=0;
      string st="";
      while(i>=0&&j>=0){
          
          int sum=(str1[i]-'0')+(str2[j]-'0')+carry;
          
          if(sum==2){
              st+="0";
              carry=1;
          }
        else if(sum==3){
              st+="1";
              carry=1;
          }
         
          else {
              st+=to_string(sum);
              carry=0;
          }
          i--;j--;
      }
      
      while(i>=0){
            int sum=(str1[i]-'0')+carry;
          
            if(sum==2){
              st+="0";
              carry=1;
          }
             else if(sum==3){
              st+="1";
              carry=1;
          }
          else {
              st+=to_string(sum);
              carry=0;
          }
          i--;
      }
      if(carry)st+=to_string(carry);
      
      while(st.back()=='0'){
          st.pop_back();
      }
      reverse(st.begin(),st.end());
      return st;
      
  }
    string addBinary(string& s1, string& s2) {
        
        int n=s1.size(),m=s2.size();
        
        if(n>m)return find(s1,s2);
        else return find(s2,s1);
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 29 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


