-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 18 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Single Number
Difficulty: EasyAccuracy: 41.64%Submissions: 43K+Points: 2
Given an array arr[] of positive integers where every element appears even times except for one. Find that number occurring an odd number of times.

Examples:

Input: arr[] = [1, 1, 2, 2, 2]
Output: 2
Explanation: In the given array all element appear two times except 2 which appears thrice.
Input: arr[] = [8, 8, 7, 7, 6, 6, 1]
Output: 1
Explanation: In the given array all element appear two times except 1 which appears once.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arri ≤ 105


class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // unordered_map<int,int> mp;
        // for(int i=0;i<arr.size();i++){
        //     mp[arr[i]]++;
        // }
        
        // for(auto a:mp){
        //     if(a.second%2==1){
        //         return a.first;
        //     }
        // }
        
        // return -1;
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            ans=ans^arr[i];
        }
        return ans;
    }
};



-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 18 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


2044. Count Number of Maximum Bitwise-OR Subsets
Solved
Medium
Topics
Companies
Hint
Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.

The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).

 

Example 1:

Input: nums = [3,1]
Output: 2
Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
- [3]
- [3,1]
Example 2:

Input: nums = [2,2,2]
Output: 7
Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.
Example 3:

Input: nums = [3,2,1,5]
Output: 6
Explanation: The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
- [3,5]
- [3,1,5]
- [3,2,5]
- [3,2,1,5]
- [2,5]
- [2,1,5]
 

Constraints:

1 <= nums.length <= 16
1 <= nums[i] <= 105

class Solution {
public:
      
    int solve(int ind,int n,int curr,int tar,vector<int> nums){
        if(ind==n){
            if(curr==tar){
                return 1;
            }
            else{
                return 0;
            }
        }

        int pick=solve(ind+1,n,curr | nums[ind],tar,nums);

        int notpick=solve(ind+1,n,curr,tar,nums);
        
        return pick+notpick;
    }
   
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int tar=0;
        for(int i=0;i<n;i++){
            tar |=nums[i];
        }

         return solve(0,n,0,tar,nums);
    }
};