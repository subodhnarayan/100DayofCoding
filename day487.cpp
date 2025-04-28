-- -- -- -- -- -- -- -- -GFG - POTD - 29 / 04 / 2025 -----------------------------------

Maximum sum of Non-adjacent nodes
Difficulty: MediumAccuracy: 55.35%Submissions: 85K+Points: 4Average Time: 45m
Given a binary tree with a value associated with each node. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

Examples:

Input: root[] = [11, 1, 2]

Output: 11
Explanation: The maximum sum is obtained by selecting the node 11.

Input: root[] = [1, 2, 3, 4, N, 5, 6]

Output: 16
Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6, which are not directly connected to each other. Their total sum is 16.  

Constraints:
1 ≤ no. of nodes in the tree ≤ 104
1 ≤ Node.val ≤ 105
Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)


class Solution {
    public:
      // Function to return the maximum sum of non-adjacent nodes.
      int solve(Node* root,unordered_map<Node*,int>&mp){
          if(root == nullptr)return 0;
          if(mp.find(root) !=mp.end())return mp[root];
          int nontake = solve(root->left,mp)+solve(root->right,mp);
          int take = root->data;
          if(root->left){
              take += solve(root->left->left,mp);
              take += solve(root->left->right,mp);
          }
          if(root->right){
              take += solve(root->right->left,mp);
              take += solve(root->right->right,mp);
          }
          return mp[root] = max(take,nontake);
      }
      int getMaxSum(Node *root) {
          // code here
         unordered_map<Node*,int>mp;
          return solve(root,mp); 
      }
  };


-- -- -- -- -- -- -- -- -Leetcode - POTD - 29 / 04 / 2025 -----------------------------------


2302. Count Subarrays With Score Less Than K
Solved
Hard
Topics
Companies
Hint
The score of an array is defined as the product of its sum and its length.

For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [2,1,4,3,5], k = 10
Output: 6
Explanation:
The 6 subarrays having scores less than 10 are:
- [2] with score 2 * 1 = 2.
- [1] with score 1 * 1 = 1.
- [4] with score 4 * 1 = 4.
- [3] with score 3 * 1 = 3. 
- [5] with score 5 * 1 = 5.
- [2,1] with score (2 + 1) * 2 = 6.
Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.
Example 2:

Input: nums = [1,1,1], k = 5
Output: 5
Explanation:
Every subarray except [1,1,1] has a score less than 5.
[1,1,1] has a score (1 + 1 + 1) * 3 = 9, which is greater than 5.
Thus, there are 5 subarrays having scores less than 5.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= k <= 1015


