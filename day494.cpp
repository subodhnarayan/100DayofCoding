
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


