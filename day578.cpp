-- -- -- -- -- -- -- -- -GFG - POTD - 28/ 06 / 2025 ----------------------------------------

Counting elements in two arrays
Difficulty: MediumAccuracy: 37.12%Submissions: 91K+Points: 4Average Time: 20m
You are given two unsorted arrays a[] and b[]. Both arrays may contain duplicate elements. For each element in a[], your task is to count how many elements in b[] are less than or equal to that element.

Examples:

Input: a[] = [4, 8, 7, 5, 1], b[] = [4, 48, 3, 0, 1, 1, 5]
Output: [5, 6, 6, 6, 3]
Explanation: 
For a[0] = 4, there are 5 elements in b (4, 3, 0, 1, 1) that are ≤ 4.
For a[1] = 8 and a[2] = 7, there are 6 elements in b that are ≤ 8 and ≤ 7.
For a[3] = 5, there are 6 elements in b that are ≤ 5.
For a[4] = 1, there are 3 elements in b (0, 1, 1) that are ≤ 1.
Input: a[] = [10, 20], b[] = [30, 40, 50]
Output: [0, 0]
Explanation: 
For a[0] = 10 and a[1] = 20, there are no elements in b that are less than or equal to 10 or 20. Hence, the output is [0, 0].
Constraints:
1 ≤ a.size(), b.size() ≤ 105
0 ≤ a[i], b[j] ≤ 105

Expected Complexities
Time Complexity: O(n + m + max(b[i]))
Auxiliary Space: O(max(b[i]))

class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        sort(b.begin(), b.end());
        vector<int> ans;
        for(auto &e : a){
            ans.push_back(upper_bound(b.begin(), b.end(), e) - b.begin());
        }
        return ans;
    }
};



-- -- -- -- -- -- -- -- -Leetcode - POTD - 28 / 06 / 2025 ----------------------------------------

2099. Find Subsequence of Length K With the Largest Sum
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

Return any such subsequence as an integer array of length k.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [2,1,3,3], k = 2
Output: [3,3]
Explanation:
The subsequence has the largest sum of 3 + 3 = 6.
Example 2:

Input: nums = [-1,-2,3,4], k = 3
Output: [-1,3,4]
Explanation: 
The subsequence has the largest sum of -1 + 3 + 4 = 6.
Example 3:

Input: nums = [3,4,3,3], k = 2
Output: [3,4]
Explanation:
The subsequence has the largest sum of 3 + 4 = 7. 
Another possible subsequence is [4, 3].
 

Constraints:

1 <= nums.length <= 1000
-105 <= nums[i] <= 105
1 <= k <= nums.length

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numsWithIndices;
        for (int i = 0; i < nums.size(); i++) {
            numsWithIndices.push_back({nums[i], i});
        }

        // Sort by value descending
        sort(numsWithIndices.begin(), numsWithIndices.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        // Take top k and sort by original index
        vector<pair<int, int>> topK(numsWithIndices.begin(), numsWithIndices.begin() + k);
        sort(topK.begin(), topK.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        // Extract values
        vector<int> result;
        for (auto& p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};