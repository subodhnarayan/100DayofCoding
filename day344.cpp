
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


1432. Max Difference You Can Get From Changing an Integer
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an integer num. You will apply the following steps to num two separate times:

Pick a digit x (0 <= x <= 9).
Pick another digit y (0 <= y <= 9). Note y can be equal to x.
Replace all the occurrences of x in the decimal representation of num by y.
Let a and b be the two results from applying the operation to num independently.

Return the max difference between a and b.

Note that neither a nor b may have any leading zeros, and must not be 0.

 

Example 1:

Input: num = 555
Output: 888
Explanation: The first time pick x = 5 and y = 9 and store the new integer in a.
The second time pick x = 5 and y = 1 and store the new integer in b.
We have now a = 999 and b = 111 and max difference = 888
Example 2:

Input: num = 9
Output: 8
Explanation: The first time pick x = 9 and y = 9 and store the new integer in a.
The second time pick x = 9 and y = 1 and store the new integer in b.
We have now a = 9 and b = 1 and max difference = 8
 

Constraints:

1 <= num <= 108
