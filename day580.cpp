-- -- -- -- -- -- -- -- -GFG - POTD - 30/ 06 / 2025 ----------------------------------------

Max min Height
Difficulty: HardAccuracy: 62.86%Submissions: 24K+Points: 8
Given a garden with n flowers planted in a row, that is represented by an array arr[], where arr[i] denotes the height of the ith flower.You will water them for k days. In one day you can water w continuous flowers. Whenever you water a flower its height increases by 1 unit. You have to maximize the minimum height of all flowers after  k days of watering.

Examples:

Input: arr[] = [2, 3, 4, 5, 1], k = 2, w = 2
Output: 2
Explanation: The minimum height after watering is 2.
Day 1: Water the last two flowers -> arr becomes [2, 3, 4, 6, 2]
Day 2: Water the last two flowers -> arr becomes [2, 3, 4, 7, 3]
Input: arr[] = [5, 8], k = 5, w = 1
Output: 9
Explanation: The minimum height after watering is 9.
Day 1 - Day 4: Water the first flower -> arr becomes [9, 8]
Day 5: Water the second flower -> arr becomes [9, 9]
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ w ≤ arr.size()
1 ≤ k ≤ 105
1 ≤ arr[i] ≤ 109

Expected Complexities
Time Complexity: O(n log m)
Auxiliary Space: O(n)

class Solution {
  public:
  bool check(int t, int n, int k, int w, vector<int>&arr){
        int currWater=0;
        int dayUsed=0;
        vector<int>water(n+1, 0);
        
        for(int i=0; i<n; i++){
            currWater+=water[i];
            int currHeight=arr[i]+currWater;
            if(currHeight<t){
                int need=t-currHeight;
                dayUsed+=need;
                if(dayUsed>k) return false;
                currWater+=need;
                water[i]+=need;
                if(i+w<=n){
                    water[i+w]-=need;
                }
            }
        }
        
        return true;
    }
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
         int n=arr.size();
        int lo = *min_element(arr.begin(), arr.end());
        int hi=lo+k;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid, n, k, w, arr)){
                lo=mid+1;
            }else hi=mid-1;
        }
        return hi;
    }
};
-- -- -- -- -- -- -- -- -Leetcode - POTD - 30  / 06 / 2025 ----------------------------------------

