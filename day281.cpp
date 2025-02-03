-- -- -- -- -- -- -- -- -GFG - POTD - 03 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Height of Binary Tree
Difficulty: EasyAccuracy: 78.58%Submissions: 306K+Points: 2Average Time: 15m
Given a binary tree, find its height.

The height of a tree is defined as the number of edges on the longest path from the root to a leaf node. A leaf node is a node that does not have any children.

Examples:

Input: root[] = [12, 8, 18, 5, 11] 
 
Output: 2
Explanation: One of the longest path from the root (node 12) goes through node 8 to node 5, which has 2 edges.
Input: root[] = [1, 2, 3, 4, N, N, 5, N, N, 6, 7]  

Output: 3
Explanation: The longest path from the root (node 1) to a leaf node 6 with 3 edge.
Constraints:
1 <= number of nodes <= 105
0 <= node->data <= 105

class Solution {
  public:
    // Function to find the height of a binary tree.
    
    int height(Node* node) {
        
        if(node==NULL) return -1;
        int left=0,right=0;
        if(node->left!=NULL) left=1+height(node->left);
        if(node->right!=NULL) right=1+height(node->right);
        return max(left,right);
    }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 03 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


3105. Longest Strictly Increasing or Strictly Decreasing Subarray
Solved
Easy
Topics
Companies
You are given an array of integers nums. Return the length of the longest 
subarray
 of nums which is either 
strictly increasing
 or 
strictly decreasing
.

 

Example 1:

Input: nums = [1,4,3,3,2]

Output: 2

Explanation:

The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].

The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].

Hence, we return 2.

Example 2:

Input: nums = [3,3,3,3]

Output: 1

Explanation:

The strictly increasing subarrays of nums are [3], [3], [3], and [3].

The strictly decreasing subarrays of nums are [3], [3], [3], and [3].

Hence, we return 1.

Example 3:

Input: nums = [3,2,1]

Output: 3

Explanation:

The strictly increasing subarrays of nums are [3], [2], and [1].

The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].

Hence, we return 3.

 

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 50