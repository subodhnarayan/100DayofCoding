-- -- -- -- -- -- -- -- -GFG - POTD - 13 / 05 / 2025 ----------------------------------------
nCr
Difficulty: MediumAccuracy: 14.82%Submissions: 335K+Points: 4
Given two integer values n and r, the task is to find the value of Binomial Coefficient nCr

A binomial coefficient nCr can be defined as the coefficient of xr in the expansion of (1 + x)n that gives the number of ways to choose r objects from a set of n objects without considering the order.
The binomial coefficient nCr is calculated as : C(n,r) = n! / r! * (n-r) !
Note: If r is greater than n, return 0.
It is guaranteed that the value of nCr will fit within a 32-bit integer.

Examples:

Input: n = 5, r = 2
Output: 10
Explaination: The value of 5C2 is calculated as 5!/(5−2)!*2! = 5!/3!*2! = 10.
Input: n = 2, r = 4
Output: 0
Explaination: Since r is greater than n, thus 2C4 = 0
Input: n = 5, r = 0
Output: 1
Explaination: The value of 5C0 is calculated as 5!/(5−0)!*0! = 5!/5!*0! = 1.
Constraints:
1 ≤ n ≤ 100
0 ≤ r ≤ 100

class Solution {
  public:
  const int mod = 1e9+7;
  int binaryexp(int x, int n) {
        if(n == 0) return 1;
        int temp = binaryexp(x, n/2);
        if(n%2 == 0) return (1LL *temp * temp)%mod;
        else return (((1LL*temp*temp)%mod)*x)%mod;
    }
    int nCr(int n, int r) {
        // code here
        if(r > n) return 0;
        if(r == n) return 1;
        long long ans = 1;
        //first calculating the numerator
        for(int i = 1; i<=r; i++) {
            ans = (ans*1LL*(i+(n-r)))%mod;
        }
        //now calculating the final ans by dividing the ans with the terms in denominator 
        for(int i = 1; i<=r; i++) {
            int inv = binaryexp(i, mod-2);
            ans = ((ans%mod) * (inv%mod))%mod;
        }
        return ans;
        
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 13 / 05 / 2025 ----------------------------------------

