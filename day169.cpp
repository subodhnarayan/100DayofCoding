-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 19 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

fficulty: EasyAccuracy: 19.32%Submissions: 84K+Points: 2
A string str is given to represent a positive number. The task is to round str to the nearest multiple of 10.  If you have two multiples equally apart from str, choose the smallest element among them.

Examples:

Input: str = 29 
Output: 30
Explanation: Close multiples are 20 and 30, and 30 is the nearest to 29. 
Input: str = 15
Output: 10
Explanation: 10 and 20 are equally distant multiples from 20. The smallest of the two is 10.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:

class Solution {
  public:
    string roundToNearest(string str) {
      
     
    //   int n=str.size();
    //   int rem=n%10;
    //   if(rem<=5){
    //       return to_string(n-rem);
    //   }
    //   else{
    //       return to_string(n+(10-rem));
    //   }
    
     int n=str.size();
     
     if((str[n-1]-'0')<=5){
         str[n-1]='0';
     }
      else{
          str[n-1]='0';
          int carry=1;
          for(int i=n-2;i>=0;i--){
              int num=str[i]-'0';
              int sum=num+carry;
              
              str[i]='0'+sum%10;
              carry=sum/10;
              if(carry==0){
                  break;
              }
          }
              
              if(carry==1){
          return "1"+str;
            }
      }
      
    return str;
      
    }
};