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


1545. Find Kth Bit in Nth Binary String
Solved
Medium
Topics
Companies
Hint
Given two positive integers n and k, the binary string Sn is formed as follows:

S1 = "0"
Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

For example, the first four strings in the above sequence are:

S1 = "0"
S2 = "011"
S3 = "0111001"
S4 = "011100110110001"
Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

 

Example 1:

Input: n = 3, k = 1
Output: "0"
Explanation: S3 is "0111001".
The 1st bit is "0".
Example 2:

Input: n = 4, k = 11
Output: "1"
Explanation: S4 is "011100110110001".
The 11th bit is "1".
 

Constraints:

1 <= n <= 20
1 <= k <= 2n - 1

class Solution {
public:
    char findKthBit(int n, int k) {
        // Base case: When n = 1, the binary string is "0"
        if (n == 1) return '0';
        
        // Find the length of the current string Sn, which is 2^n - 1
        int length = (1 << n) - 1;
        
        // Find the middle position
        int mid = length / 2 + 1;
        
        // If k is the middle position, return '1'
        if (k == mid) return '1';
        
        // If k is in the first half, find the bit in Sn-1
        if (k < mid) return findKthBit(n - 1, k);
        
        // If k is in the second half, find the bit in Sn-1 and invert it
        return findKthBit(n - 1, length - k + 1) == '0' ? '1' : '0';
    }
};