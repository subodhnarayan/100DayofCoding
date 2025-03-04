-- -- -- -- -- -- -- -- -GFG - POTD - 04 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Longest Increasing Subsequence
Difficulty: MediumAccuracy: 32.8%Submissions: 333K+Points: 4
Given an array arr[] of non-negative integers, the task is to find the length of the Longest Strictly Increasing Subsequence (LIS).

A subsequence is strictly increasing if each element in the subsequence is strictly less than the next element.

Examples:

Input: arr[] = [5, 8, 3, 7, 9, 1]
Output: 3
Explanation: The longest strictly increasing subsequence could be [5, 7, 9], which has a length of 3.
Input: arr[] = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]
Output: 6
Explanation: One of the possible longest strictly increasing subsequences is [0, 2, 6, 9, 13, 15], which has a length of 6.
Input: arr[] = [3, 10, 2, 1, 20]
Output: 3
Explanation: The longest strictly increasing subsequence could be [3, 10, 20], which has a length of 3.
Constraints:
1 ≤ arr.size() ≤ 103
0 ≤ arr[i] ≤ 106

Time Complexity: O(n log n)Auxiliary Space: O(n)

class Solution {
    public:
      int lis(vector<int>& arr) {
          // code here
          vector<int> ans;
          ans.push_back(arr[0]);
          for(int i=1;i<arr.size();i++){
              if(arr[i]>ans.back())ans.push_back(arr[i]);
              else ans[lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin()]=arr[i];
          }
          return ans.size();
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 04 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


1780. Check if Number is a Sum of Powers of Three
Medium
Topics
Hint
Given an integer n, return true if it is possible to represent n as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.

 

Example 1:

Input: n = 12
Output: true
Explanation: 12 = 31 + 32
Example 2:

Input: n = 91
Output: true
Explanation: 91 = 30 + 32 + 34
Example 3:

Input: n = 21
Output: false
 

Constraints:

1 <= n <= 107



class Solution {
    public:
        bool checkPowersOfThree(int n) {
             while (n > 0) {
                if (n % 3 == 2) {
                    return false;
                }
                n /= 3;
            }
            return true;
        }
};