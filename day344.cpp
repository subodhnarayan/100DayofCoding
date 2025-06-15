
Smallest Divisor
Difficulty: MediumAccuracy: 50.74%Submissions: 23K+Points: 4Average Time: 25m
Given an integer array arr[] and an integer k (where k ≥ arr.length), find the smallest positive integer divisor such that the sum of the ceiling values of each element in arr[] divided by this divisor is less than or equal to k.

Examples:

Input: arr[] = [1, 2, 5, 9], k = 6
Output: 5
Explanation: 5 is the smallest divisor having sum of quotients (1 + 1 + 1 + 2 = 5) less than or equal to 6.
Input: arr[] = [1, 1, 1, 1], k = 4
Output: 1
Explanation: 1 is the smallest divisor having sum of quotients (1 + 1 + 1 + 1 = 4) less than or equal to 4.
Constraints:
1  ≤  arr.size()  ≤ 105
1  ≤  arr[i]  ≤ 106
arr.size()  ≤ k  ≤ 106

Expected Complexities
Time Complexity: O(n * log(max(arr[i])))
Auxiliary Space: O(1)

class Solution {
  public:
      int fun(int l, int r, vector<int> &arr, int k){
        if(l==r)
            return l;
        int m = l + (r-l)/2;
        int sum = 0;
        for(auto z : arr){
            sum += (z/m);
            if(z%m)    
                sum++;
        }
        
        if(sum <= k)
            return fun(l, m, arr, k);
        return  fun(m+1, r, arr, k);
    }
  
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
         int maxi = arr[0];
        for(auto z : arr){
            maxi = max(maxi, z);
        }
        
        return fun(1, maxi, arr, k);
    }
};
