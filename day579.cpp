-- -- -- -- -- -- -- -- -GFG - POTD - 29/ 06 / 2025 ----------------------------------------

Split Array Largest Sum
Difficulty: HardAccuracy: 58.9%Submissions: 57K+Points: 8
Given an array arr[] and an integer k, divide the array into k contiguous subarrays such that the maximum sum among these subarrays is minimized. Find this minimum possible maximum sum.

Examples:

Input: arr[] = [1, 2, 3, 4], k = 3
Output: 4
Exaplanation: Optimal Split is [1, 2], [3], [4]. Maximum sum of all subarrays is 4, which is minimum possible for 3 splits.
Input: arr[] = [1, 1, 2], k = 2
Output: 2
Exaplanation: Splitting the array as [1, 1] and [2] is optimal. This results in a maximum sum subarray of 2.
Constraints:
1 ≤ k ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104

class Solution {
  public:
   bool canSplit(vector<int>& arr, int k, int mid){
        int subarray=0, currsum=0;
        for(int n:arr){
            currsum+=n;
            if(currsum>mid){
                currsum=n;
                subarray+=1;
            }
        }
        return subarray+1<=k;
    }
    int splitArray(vector<int>& arr, int k) {
        // code here
         int l=*max_element(arr.begin(), arr.end());
        int r=accumulate(arr.begin(), arr.end(), 0);
        int result=r;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(canSplit(arr, k, mid)){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return result;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 29 / 06 / 2025 ----------------------------------------

1498. Number of Subsequences That Satisfy the Given Sum Condition
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [3,5,6,7], target = 9
Output: 4
Explanation: There are 4 subsequences that satisfy the condition.
[3] -> Min value + max value <= target (3 + 3 <= 9)
[3,5] -> (3 + 5 <= 9)
[3,5,6] -> (3 + 6 <= 9)
[3,6] -> (3 + 6 <= 9)
Example 2:

Input: nums = [3,3,6,8], target = 10
Output: 6
Explanation: There are 6 subsequences that satisfy the condition. (nums can have repeated numbers).
[3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]
Example 3:

Input: nums = [2,3,3,4,6,7], target = 12
Output: 61
Explanation: There are 63 non-empty subsequences, two of them do not satisfy the condition ([6,7], [7]).
Number of valid subsequences (63 - 2 = 61).
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= target <= 106


class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int mod = 1e9 + 7, n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> power(n, 1);
        for (int i = 1; i < n; ++i) {
            power[i] = (power[i - 1] * 2) % mod;
        }

        int left = 0, right = n - 1, result = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + power[right - left]) % mod;
                ++left;
            } else {
                --right;
            }
        }
        return result;
    }
};