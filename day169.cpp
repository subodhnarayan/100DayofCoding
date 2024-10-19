-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 19 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
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