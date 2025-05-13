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

3335. Total Characters in String After Transformations I
Solved
Medium
Topics
Companies
Hint
You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

If the character is 'z', replace it with the string "ab".
Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
Return the length of the resulting string after exactly t transformations.

Since the answer may be very large, return it modulo 109 + 7.

 

Example 1:

Input: s = "abcyy", t = 2

Output: 7

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'b' becomes 'c'
'c' becomes 'd'
'y' becomes 'z'
'y' becomes 'z'
String after the first transformation: "bcdzz"
Second Transformation (t = 2):
'b' becomes 'c'
'c' becomes 'd'
'd' becomes 'e'
'z' becomes "ab"
'z' becomes "ab"
String after the second transformation: "cdeabab"
Final Length of the string: The string is "cdeabab", which has 7 characters.
Example 2:

Input: s = "azbk", t = 1

Output: 5

Explanation:

First Transformation (t = 1):
'a' becomes 'b'
'z' becomes "ab"
'b' becomes 'c'
'k' becomes 'l'
String after the first transformation: "babcl"
Final Length of the string: The string is "babcl", which has 5 characters.
 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters.
1 <= t <= 105

class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);
        for (char ch : s) {
            ++cnt[ch - 'a'];
        }
        for (int round = 0; round < t; ++round) {
            vector<int> nxt(26);
            nxt[0] = cnt[25];
            nxt[1] = (cnt[25] + cnt[0]) % mod;
            for (int i = 2; i < 26; ++i) {
                nxt[i] = cnt[i - 1];
            }
            cnt = move(nxt);
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans = (ans + cnt[i]) % mod;
        }
        return ans;
    }

private:
    static constexpr int mod = 1000000007;
};