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

