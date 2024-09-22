-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 22 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Longest Prefix Suffix
Difficulty: HardAccuracy: 27.91%Submissions: 129K+Points: 8
Given a string of characters, find the length of the longest proper prefix which is also a proper suffix.

NOTE: Prefix and suffix can be overlapping but they should not be equal to the entire string.

Examples :

Input: str = "abab"
Output: 2
Explanation: "ab" is the longest proper prefix and suffix. 
Input: str = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper prefix and suffix. 
Expected Time Complexity: O(|str|)
Expected Auxiliary Space: O(|str|)

Constraints:
1 ≤ |str| ≤ 106
str contains lower case English alphabets


class Solution {
  public:
    int lps(string str) {
        // Your code goes here
           int p=0;
        int s=1;
        int cnt=0;
        int pos=1;
        int n=str.size();
        while(p<n && s<n)
        {
            if(str[p]==str[s])
            {
                cnt++;
                p++;
                s++;
            }
            else
            {
                cnt=0;
                pos++;
                s=pos;
                p=0;
                
            }
        }
        return cnt;
    }
};

-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 22 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


440. K-th Smallest in Lexicographical Order
Solved
Hard
Topics
Companies
Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
Example 2:

Input: n = 1, k = 1
Output: 1
 

Constraints:

1 <= k <= n <= 109

class Solution {
public:
   
      int getReqNum(long a,long b,long &n){
        int gap=0; 
        while(a <= n){
            gap += min(n+1,b)-a;
            a*=10;
            b*=10;
        }
        return gap;
    }
    int findKthNumber(long n, int k) {
        long num = 1;
        for(int i=1; i<k;){
            int req = getReqNum(num,num+1,n);
            if(i+req <= k){
                i+=req;
                num++;
            }else{
                i++;
                num *= 10;
            }
        }
        return num;
    }
};