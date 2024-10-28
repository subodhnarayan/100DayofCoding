-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 28 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Remove duplicates in array
Difficulty: EasyAccuracy: 35.86%Submissions: 53K+Points: 2
Given an array arr consisting of positive integer numbers, remove all duplicate numbers.

Example:

Input: arr[] = [2, 2, 3, 3, 7, 5] 
Output: [2, 3, 7, 5]
Explanation: After removing the duplicates 2 and 3 we get 2 3 7 5.
Input: arr[] = [2, 2, 5, 5, 7, 7] 
Output: [2, 5, 7]
Input: arr[] = [8, 7] 
Output: [8, 7]
Constraints:
1<= arr.size() <=106
2<= arr[i] <=100

class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        unordered_set<int> st;
        int n=arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(st.find(arr[i])==st.end())
             ans.push_back(arr[i]);
            st.insert(arr[i]);
           
        }
        // for(int &it:arr){
        //     if(st.find(it)==st.end())
        //     st.insert(it);
        //     ans.push_back(it);
        // }

        return ans;
    }
};



2501. Longest Square Streak in an Array
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums. A subsequence of nums is called a square streak if:

The length of the subsequence is at least 2, and
after sorting the subsequence, each element (except the first element) is the square of the previous number.
Return the length of the longest square streak in nums, or return -1 if there is no square streak.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [4,3,6,16,8,2]
Output: 3
Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
- 4 = 2 * 2.
- 16 = 4 * 4.
Therefore, [4,16,2] is a square streak.
It can be shown that every subsequence of length 4 is not a square streak.
Example 2:

Input: nums = [2,3,5,6,7]
Output: -1
Explanation: There is no square streak in nums so return -1.
 

Constraints:

2 <= nums.length <= 105
2 <= nums[i] <= 105