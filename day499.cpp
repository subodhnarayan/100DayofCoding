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

