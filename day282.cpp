-- -- -- -- -- -- -- -- -GFG - POTD - 04 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Diameter of a Binary Tree
Difficulty: MediumAccuracy: 47.37%Submissions: 324K+Points: 4Average Time: 20m
Given a binary tree, the diameter (also known as the width) is defined as the number of edges on the longest path between two leaf nodes in the tree. This path may or may not pass through the root. Your task is to find the diameter of the tree.

Examples:

Input: root[] = [1, 2, 3]

Output: 2
Explanation: The longest path has 2 edges (node 2 -> node 1 -> node 3).

Input: root[] = [5, 8, 6, 3, 7, 9]

Output: 4
Explanation: The longest path has 4 edges (node 3 -> node 8 -> node 5 -> node 6 -> node 9).

Constraints:
1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 105


class Solution {
  public:
       int dfs(Node* root, int& d) {
        if (!root) return 0;
        int l = dfs(root->left, d), r = dfs(root->right, d);
        d = std::max(d, l + r + 1);
        return 1 + std::max(l, r);
    }
    int diameter(Node* root) {
        // Your code here
          int d = 0;
        dfs(root, d);
        return d-1;
    }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 04 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

1800. Maximum Ascending Subarray Sum
Solved
Easy
Topics
Companies
Hint
Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.

 

Example 1:

Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
Example 2:

Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.
Example 3:

Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100



class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
       int curr = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            curr = nums[i] > nums[i - 1] ? curr + nums[i] : nums[i];
            ans = max(ans, curr);
        }
        return ans; 
    }
};