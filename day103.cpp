-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 12 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Square root of a number
Difficulty: EasyAccuracy: 54.03%Submissions: 244K+Points: 2
Given an integer n, find the square root of n. If n is not a perfect square, then return the floor value.

Floor value of any number is the greatest Integer which is less than or equal to that number

Examples:

Input: n = 5
Output: 2
Explanation: Since, 5 is not a perfect square, floor of square_root of 5 is 2.
Input: n = 4
Output: 2
Explanation: Since, 4 is a perfect square, so its square root is 2.
Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ n ≤ 107

class Solution {
  public:
    long long int floorSqrt(long long int n) {
           long long int fs=floor(sqrt(n));
        return fs;
    }
};







40. Combination Sum II
Solved
Medium
Topics
Companies
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
 

Constraints:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30


class Solution {
public:
   void findcombination(int ind,int target,vector<int> &cand,vector<int> &ds,vector<vector<int>> &ans){
     if(target==0){
        ans.push_back(ds);
        return;
    }
    for(int i=ind;i<cand.size();i++){
        if(i>ind && cand[i]==cand[i-1]) continue;
        if(cand[i]>target) break;
        ds.push_back(cand[i]);
        findcombination(i+1,target-cand[i],cand,ds,ans);
        ds.pop_back();
    }
   }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        sort(cand.begin(),cand.end());
        vector<int> ds;
        findcombination(0,target,cand,ds,ans);
        return ans;
    }
};