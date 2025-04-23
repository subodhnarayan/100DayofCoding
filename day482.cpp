
-- -- -- -- -- -- -- -- -Leetcode - POTD - 23 / 04 / 2025 -----------------------------------
Unique Number II
Difficulty: MediumAccuracy: 36.9%Submissions: 165K+Points: 4Average Time: 15m
Given an array arr[] containing 2*n + 2 positive numbers, out of which 2*n numbers exist in pairs whereas only two number occur exactly once and are distinct. Find the other two numbers. Return the answer in increasing order.

Examples:

Input: arr[] = [1, 2, 3, 2, 1, 4]
Output: [3, 4] 
Explanation: 3 and 4 occur exactly once.
Input: arr[] = [2, 1, 3, 2]
Output: [1, 3]
Explanation: 1 and 3 occur exactly once.
Input: arr[] = [2, 1, 3, 3]
Output: [1, 2]
Explanation: 1 and 2 occur exactly once.
Constraints:
2 ≤ arr.size() ≤ 106 
1 ≤ arr[i] ≤ 5 * 106
arr.size() is even

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)


class Solution {
    public:
      vector<int> singleNum(vector<int>& arr) {
          // Code here.
           int n=arr.size();
          int exor=0;
          for(int i=0;i<arr.size();i++)
          {
               exor=arr[i]^exor;
               
          }
          int setbit=-1;
          for(int i=0;i<32;i++)
          {
              if(exor&(1<<i))
              {
                  setbit=i;
                  break;
              }
          }
          int first=0;
          for(int i=0;i<n;i++)
          {
              if(arr[i]&(1<<setbit))
              {
                  first=first^arr[i];
              }
             
          }
          int second=first^exor;
          return {min(first,second),max(first,second)};
      }
  };


-- -- -- -- -- -- -- -- -Leetcode - POTD - 23 / 04 / 2025 -----------------------------------


1399. Count Largest Group
Solved
Easy
Topics
Companies
Hint
You are given an integer n.

Each number from 1 to n is grouped according to the sum of its digits.

Return the number of groups that have the largest size.

 

Example 1:

Input: n = 13
Output: 4
Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
[1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
There are 4 groups with largest size.
Example 2:

Input: n = 2
Output: 2
Explanation: There are 2 groups [1], [2] of size 1.
 

Constraints:

1 <= n <= 104

class Solution {
    public:
        int digsum(int n) {
            int sum = 0;
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            return sum;
        }
        int countLargestGroup(int n) {
            int maxi=INT_MIN;
            unordered_map <int,int> mpp;
            int count=0;
            for (int i = 1 ; i <= n ; i++) {
                int x = digsum(i);
                maxi = max(maxi, ++mpp[x]);
            }
            for (auto& p : mpp) if (p.second == maxi) ++count;
            return count;
        }
};

