-- -- -- -- -- -- -- -- -GFG - POTD - 10 / 05 / 2025 -----------------------------------

Longest Subarray with Majority Greater than K
Difficulty: MediumAccuracy: 52.63%Submissions: 12K+Points: 4
Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.

Examples:

Input: arr[] = [1, 2, 3, 4, 1], k = 2
Output: 3
Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.
Input: arr[] = [6, 5, 3, 4], k = 2
Output: 4
Explanation: In the subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements <= 2, so it is the longest subarray.
Constraints:
1 <= arr.size() <= 106
1 <= arr[i] <= 106
0 <= k <= 106

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
         int n=arr.size();
        vector<int>diff(n);
        for(int i=0;i<n;i++){
            if(arr[i]>k){
                diff[i]=1;
            }
            else{
                diff[i]=-1;
            }
        }
        unordered_map<int,int>mp;
        int prefix=0;
        int maxlen=0;
        for(int i=0;i<n;i++){
            prefix+=diff[i];
            if(prefix>0){
                maxlen=i+1;
            }
            else{
                if(mp.find(prefix-1)!=mp.end()){
                    maxlen=max(maxlen,i-mp[prefix-1]);
                }
            }
            if(mp.find(prefix)==mp.end()){
                mp[prefix]=i;
            }
        }
        return maxlen;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 10 / 05 / 2025 -----------------------------------

2918. Minimum Equal Sum of Two Arrays After Replacing Zeros
Solved
Medium
Topics
Companies
Hint
You are given two arrays nums1 and nums2 consisting of positive integers.

You have to replace all the 0's in both arrays with strictly positive integers such that the sum of elements of both arrays becomes equal.

Return the minimum equal sum you can obtain, or -1 if it is impossible.

 

Example 1:

Input: nums1 = [3,2,0,1,0], nums2 = [6,5,0]
Output: 12
Explanation: We can replace 0's in the following way:
- Replace the two 0's in nums1 with the values 2 and 4. The resulting array is nums1 = [3,2,2,1,4].
- Replace the 0 in nums2 with the value 1. The resulting array is nums2 = [6,5,1].
Both arrays have an equal sum of 12. It can be shown that it is the minimum sum we can obtain.
Example 2:

Input: nums1 = [2,0,2,0], nums2 = [1,4]
Output: -1
Explanation: It is impossible to make the sum of both arrays equal.
 

Constraints:

1 <= nums1.length, nums2.length <= 105
0 <= nums1[i], nums2[i] <= 106


class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;
        for (int i : nums1) {
            sum1 += i;
            if (i == 0) {
                sum1++;
                zero1++;
            }
        }
        for (int i : nums2) {
            sum2 += i;
            if (i == 0) {
                sum2++;
                zero2++;
            }
        }
        if (!zero1 && sum2 > sum1 || !zero2 && sum1 > sum2) {
            return -1;
        }
        return max(sum1, sum2);
    }
};