-- -- -- -- -- -- -- -- -GFG - POTD - 06 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Construct Tree from Inorder & Preorder
Difficulty: MediumAccuracy: 34.59%Submissions: 192K+Points: 4Average Time: 20m
Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.

Note: The output is written in postorder traversal.

Examples:

Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
Output: [8, 7, 6, 1]
Explanation: The tree will look like

Input: inorder[] = [3, 1, 4, 0, 2, 5], preorder[] = [0, 1, 3, 4, 2, 5]
Output: [3, 4, 1, 5, 2, 0]
Explanation: The tree will look like

Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
Output: [2, 5, 4, 3, 1]
Explanation: The tree will look like

Constraints:
1 ≤ number of nodes ≤ 103
0 ≤ nodes -> data ≤ 103
Both the inorder and preorder arrays contain unique values.




-- -- -- -- -- -- -- -- -LeetCode - POTD - 06 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


1726. Tuple with Same Product
Solved
Medium
Topics
Companies
Hint
Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.

 

Example 1:

Input: nums = [2,3,4,6]
Output: 8
Explanation: There are 8 valid tuples:
(2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
(3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
Example 2:

Input: nums = [1,2,4,5,10]
Output: 16
Explanation: There are 16 valid tuples:
(1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
(2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
(2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
(4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
 

Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 104
All elements in nums are distinct.

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int product = nums[i] * nums[j];
                ans += 8 * mp[product];
                mp[product]++;
            }
        return ans;
    }
};