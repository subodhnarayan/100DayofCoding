
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



