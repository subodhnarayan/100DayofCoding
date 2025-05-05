
-- -- -- -- -- -- -- -- -GFG - POTD - 05 / 05 / 2025 -----------------------------------
Search in an almost Sorted Array
Difficulty: MediumAccuracy: 55.44%Submissions: 17K+Points: 4Average Time: 20m
Given a sorted integer array arr[] consisting of distinct elements, where some elements of the array are moved to either of the adjacent positions, i.e. arr[i] may be present at arr[i-1] or arr[i+1].
Given an integer target.  You have to return the index ( 0-based ) of the target in the array. If target is not present return -1.

Examples:

Input: arr[] = [10, 3, 40, 20, 50, 80, 70], target = 40
Output: 2
Explanation: Index of 40 in the given array is 2.
Input: arr[] = [10, 3, 40, 20, 50, 80, 70], target = 90
Output: -1
Explanation: 90 is not present in the array.
Input: arr[] = [-20], target = -20
Output: 0
Explanation: -20 is the only element present in the array.
Constraints:
1 <= arr.size() <= 105
-109 <= arr[i] <= 109

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)


class Solution {
    public:
      int fun(vector<int>& arr, int low, int high, int key) 
      {
      
          while (low <= high) 
          {
              int mid = low + (high - low) / 2;
      
              if (arr[mid] == key) 
              {
                  return mid;
              }
              // Check left neighbor
              if (mid > low && arr[mid - 1] == key) 
              {
                  return mid - 1;
              }
              // Check right neighbor
              if (mid < high && arr[mid + 1] == key) 
              {
                  return mid + 1;
              }
      
              if (arr[mid] > key) 
              {
                  high = mid - 2;  
              } 
              else 
              {
                  low = mid + 2;   
              }
          }
      return -1;
      }
      int findTarget(vector<int>& arr, int target) {
          // code here
           return fun(arr, 0, arr.size() - 1, target);
      }
  };


-- -- -- -- -- -- -- -- -Leetcode - POTD - 05 / 05 / 2025 -----------------------------------



790. Domino and Tromino Tiling
Solved
Medium
Topics
Companies
You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.


Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 109 + 7.

In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

 

Example 1:


Input: n = 3
Output: 5
Explanation: The five different ways are show above.
Example 2:

Input: n = 1
Output: 1
 

Constraints:

1 <= n <= 1000

class Solution {
    public:
        int numTilings(int n) {
            const int MOD = 1e9 + 7;
            if (n <= 1) return 1;
            if (n == 2) return 2;
            if (n == 3) return 5;
    
            vector<long long> dp(n + 1);
            dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 5;
    
            for (int i = 4; i <= n; ++i) {
                dp[i] = (2 * dp[i - 1] % MOD + dp[i - 3]) % MOD;
            }
    
            return dp[n]; 
        }
    };