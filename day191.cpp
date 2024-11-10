-- -- -- -- -- -- -- -- -GFG - POTD - 10 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Union of Two Sorted Arrays with Distinct Elements
Difficulty: EasyAccuracy: 55.4%Submissions: 22K+Points: 2
Given two sorted arrays a[] and b[], where each array contains distinct elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 3, 4, 5], b[] = [1, 2, 3, 4]
Output: 1 2 3 4 5
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1], b[] = [2]
Output: 1 2
Explanation: Distinct elements including both the arrays are: 1 2.
Constraints:
1  <=  a.size(), b.size()  <=  105
-109  <=  a[i] , b[i]  <=  109

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> ans;
    int i = 0, j = 0;
    
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            if (ans.empty() || ans.back() != a[i]) {  // Avoid duplicates
                ans.push_back(a[i]);
            }
            i++;
        }
        else if (a[i] > b[j]) {
            if (ans.empty() || ans.back() != b[j]) {  // Avoid duplicates
                ans.push_back(b[j]);
            }
            j++;
        }
        else { // a[i] == b[j]
            if (ans.empty() || ans.back() != a[i]) {  // Avoid duplicates
                ans.push_back(a[i]);
            }
            i++;
            j++;
        }
    }
    
    // Add remaining elements from array a, if any
    while (i < a.size()) {
        if (ans.empty() || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }
        i++;
    }

    // Add remaining elements from array b, if any
    while (j < b.size()) {
        if (ans.empty() || ans.back() != b[j]) {
            ans.push_back(b[j]);
        }
        j++;
    }
    
    return ans;
    }
};





3097. Shortest Subarray With OR at Least K II
Solved
Medium
Topics
Companies
Hint
You are given an array nums of non-negative integers and an integer k.

An array is called special if the bitwise OR of all of its elements is at least k.

Return the length of the shortest special non-empty 
subarray
 of nums, or return -1 if no special subarray exists.

 

Example 1:

Input: nums = [1,2,3], k = 2

Output: 1

Explanation:

The subarray [3] has OR value of 3. Hence, we return 1.

Example 2:

Input: nums = [2,1,8], k = 10

Output: 3

Explanation:

The subarray [2,1,8] has OR value of 11. Hence, we return 3.

Example 3:

Input: nums = [1,2], k = 0

Output: 1

Explanation:

The subarray [1] has OR value of 1. Hence, we return 1.

 

Constraints:

1 <= nums.length <= 2 * 105
0 <= nums[i] <= 109
0 <= k <= 109