-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 30 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Pairs with difference k
Difficulty: EasyAccuracy: 22.41%Submissions: 43K+Points: 2
Given an array arr[] of positive integers. Find the number of pairs of integers whose difference equals a given number k.
Note: (a, b) and (b, a) are considered the same. Also, the same numbers at different indices are considered different.

Examples:

Input: arr[] = [1, 5, 3, 4, 2], k = 3
Output: 2
Explanation: There are 2 pairs with difference 3,the pairs are {1, 4} and {5, 2} 
Input: arr[] = [8, 12, 16, 4, 0, 20], k = 4
Output: 5
Explanation: There are 5 pairs with difference 4, the pairs are {0, 4}, {4, 8}, {8, 12}, {12, 16} and {16, 20}.
Constraints:
1 <= arr.size() <= 106
1 <= k <= 106
0 <= arr[i] <= 106

class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        map<int,int> m;
        int count=0;
        for(int i=0;i<arr.size();i++){
         
            if(m.find(arr[i]-k)!=m.end()){
                count+=m[arr[i]-k];
            }
            if(m.find(k+arr[i])!=m.end()){
                 count+=m[arr[i]+k];
            }
               m[arr[i]]++;
        }
        return count;
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 31 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

1671. Minimum Number of Removals to Make Mountain Array
Hard
Topics
Companies
Hint
You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

 

Example 1:

Input: nums = [1,3,1]
Output: 0
Explanation: The array itself is a mountain array so we do not need to remove any elements.
Example 2:

Input: nums = [2,1,1,5,6,2,3,1]
Output: 3
Explanation: One solution is to remove the elements at indices 0, 1, and 5, making the array nums = [1,5,6,3,1].
 

Constraints:

3 <= nums.length <= 1000
1 <= nums[i] <= 109
It is guaranteed that you can make a mountain array out of nums.

class Solution {
public:
 vector<int> lisLength(vector<int>& v){
        vector<int> lis = {v[0]};
        vector<int> lisLen(v.size(), 1);

        for(int i = 1 ; i < v.size() ; i++){
            if(v[i] > lis.back()){
                lis.push_back(v[i]);
            } else {
                int index = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
                lis[index] = v[i];
            }
            lisLen[i] = lis.size();
        }
        return lisLen;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis = lisLength(nums);

        reverse(nums.begin(), nums.end());
        vector<int> lds = lisLength(nums);
        reverse(lds.begin(), lds.end());

        int removals = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            if(lis[i] > 1 && lds[i] > 1){
                removals = min(removals, n + 1 - lis[i] - lds[i]);
            }
        }

        return removals;
    }
};
