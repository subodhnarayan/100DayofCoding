-- -- -- -- -- -- -- -- -GFG - POTD - 27 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Minimum Platforms
Difficulty: MediumAccuracy: 26.84%Submissions: 528K+Points: 4
You are given the arrival times arr[] and departure times dep[] of all trains that arrive at a railway station on the same day. Your task is to determine the minimum number of platforms required at the station to ensure that no train is kept waiting.

At any given time, the same platform cannot be used for both the arrival of one train and the departure of another. Therefore, when two trains arrive at the same time, or when one arrives before another departs, additional platforms are required to accommodate both trains.

Examples:

Input: arr[] = [900, 940, 950, 1100, 1500, 1800], dep[] = [910, 1200, 1120, 1130, 1900, 2000]
Output: 3
Explanation: There are three trains during the time 9:40 to 12:00. So we need a minimum of 3 platforms.
Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
Output: 1
Explanation: All train times are mutually exclusive. So we need only one platform
Input: arr[] = [1000, 935, 1100], dep[] = [1200, 1240, 1130]
Output: 3
Explanation: All 3 trains have to be there from 11:00 to 11:30
Constraints:
1≤ number of trains ≤ 50000
0000 ≤ arr[i] ≤ dep[i] ≤ 2359
Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this will be <= 59 and >= 0).


class Solution {
    public:
      // Function to find the minimum number of platforms required at the
      // railway station such that no train waits.
      int findPlatform(vector<int>& arr, vector<int>& dep) {
          // Your code here
          int n = arr.size();
          vector<int> time(2361, 0);
          for(int i = 0; i < n; i++){ 
             time[arr[i]]+=1;
             time[dep[i]+1]-=1;
          }
          
          int maxCnt = 0, cntsum = 0;
          for(int i = 0; i < 2361; i++){
              cntsum += time[i];
              maxCnt = max(maxCnt, cntsum);
          }
          
          return maxCnt; 
      }
  };
  


-- -- -- -- -- -- -- -- -LeetCode - POTD - 27 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

2780. Minimum Index of a Valid Split
Solved
Medium
Topics
Companies
Hint
An element x of an integer array arr of length m is dominant if more than half the elements of arr have a value of x.

You are given a 0-indexed integer array nums of length n with one dominant element.

You can split nums at an index i into two arrays nums[0, ..., i] and nums[i + 1, ..., n - 1], but the split is only valid if:

0 <= i < n - 1
nums[0, ..., i], and nums[i + 1, ..., n - 1] have the same dominant element.
Here, nums[i, ..., j] denotes the subarray of nums starting at index i and ending at index j, both ends being inclusive. Particularly, if j < i then nums[i, ..., j] denotes an empty subarray.

Return the minimum index of a valid split. If no valid split exists, return -1.

 

Example 1:

Input: nums = [1,2,2,2]
Output: 2
Explanation: We can split the array at index 2 to obtain arrays [1,2,2] and [2]. 
In array [1,2,2], element 2 is dominant since it occurs twice in the array and 2 * 2 > 3. 
In array [2], element 2 is dominant since it occurs once in the array and 1 * 2 > 1.
Both [1,2,2] and [2] have the same dominant element as nums, so this is a valid split. 
It can be shown that index 2 is the minimum index of a valid split. 
Example 2:

Input: nums = [2,1,3,1,1,1,7,1,2,1]
Output: 4
Explanation: We can split the array at index 4 to obtain arrays [2,1,3,1,1] and [1,7,1,2,1].
In array [2,1,3,1,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
In array [1,7,1,2,1], element 1 is dominant since it occurs thrice in the array and 3 * 2 > 5.
Both [2,1,3,1,1] and [1,7,1,2,1] have the same dominant element as nums, so this is a valid split.
It can be shown that index 4 is the minimum index of a valid split.
Example 3:

Input: nums = [3,3,3,3,7,2,2]
Output: -1
Explanation: It can be shown that there is no valid split.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
nums has exactly one dominant element.

class Solution {
    public:
        int minimumIndex(vector<int>& nums) {
           int x = nums[0], count = 0, xCount = 0, n = nums.size();
            for (auto& num : nums) {
                if (num == x) {
                    count++;
                } else {
                    count--;
                }
                if (count == 0) {
                    x = num;
                    count = 1;
                }
            }
    
            // Count frequency of majority element
            for (auto& num : nums) {
                if (num == x) {
                    xCount++;
                }
            }
    
            // Check if valid split is possible
            count = 0;
            for (int index = 0; index < n; index++) {
                if (nums[index] == x) {
                    count++;
                }
                int remainingCount = xCount - count;
                if (count * 2 > index + 1 && remainingCount * 2 > n - index - 1) {
                    return index;
                }
            }
            return -1; 
        }
    };
    