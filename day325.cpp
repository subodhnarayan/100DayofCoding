
-- -- -- -- -- -- -- -- -GFG - POTD - 17 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Subset Sum Problem
Difficulty: MediumAccuracy: 32.0%Submissions: 329K+Points: 4
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
Constraints:
1 <= arr.size() <= 200
1<= arr[i] <= 200
1<= sum <= 104

class Solution {
    public:
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here
         int n=arr.size();
          vector<bool> prev(sum+1,false);
          vector<bool> curr(sum+1,false);
          prev[0]=true;
          for(int ind=1;ind<=n;ind++){
              for(int s=0;s<=sum;s++){
                  if(s==0){
                      curr[s]=true;
                      continue;
                  }
                  bool notTake=prev[s];
                  bool take=false;
                  if(s>=arr[ind-1]) take=prev[s-arr[ind-1]];
                  bool ans=take|notTake;
                  curr[s]=ans;
              }
              prev=curr;
          }
          return prev[sum];
          
      }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 17 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


2206. Divide Array Into Equal Pairs
Solved
Easy
Topics
Companies
Hint
You are given an integer array nums consisting of 2 * n integers.

You need to divide nums into n pairs such that:

Each element belongs to exactly one pair.
The elements present in a pair are equal.
Return true if nums can be divided into n pairs, otherwise return false.

 

Example 1:

Input: nums = [3,2,3,2,2,2]
Output: true
Explanation: 
There are 6 elements in nums, so they should be divided into 6 / 2 = 3 pairs.
If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will satisfy all the conditions.
Example 2:

Input: nums = [1,2,3,4]
Output: false
Explanation: 
There is no way to divide nums into 4 / 2 = 2 pairs such that the pairs satisfy every condition.
 

Constraints:

nums.length == 2 * n
1 <= n <= 500
1 <= nums[i] <= 500
