-- -- -- -- -- -- -- -- -GFG - POTD - 26 / 04 / 2025 -----------------------------------

Is Binary Tree Heap
Difficulty: MediumAccuracy: 34.41%Submissions: 126K+Points: 4
You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.
Examples:

Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]
 
Output: true
Explanation: The tree is complete and satisfies the max-heap property.
Input: root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4] 
 
Output: false
Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.
Constraints:
1 ≤ number of nodes ≤ 103
1 ≤ node->data ≤ 103

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)


class Solution {
    public:
      bool isHeap(Node* tree) {
          // code here
          if(tree==nullptr) return true;
          queue<Node*> q;
          Node *root = tree;
          q.push(root);
          bool nullflag = false;
          while(!q.empty()){
              Node *node = q.front();
              q.pop();
              if(node==nullptr) nullflag = true;
              else{
                  if(nullflag==true) return false;
                  if(node->left && node->left->data > node->data ||
                  node->right && node->right->data > node->data) return false;
              
                  q.push(node->left);
                  q.push(node->right);
              }
          }
          return true;
      }
  };

-- -- -- -- -- -- -- -- -Leetcode - POTD - 26 / 04 / 2025 -----------------------------------


2444. Count Subarrays With Fixed Bounds
Solved
Hard
Topics
Companies
Hint
You are given an integer array nums and two integers minK and maxK.

A fixed-bound subarray of nums is a subarray that satisfies the following conditions:

The minimum value in the subarray is equal to minK.
The maximum value in the subarray is equal to maxK.
Return the number of fixed-bound subarrays.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
Output: 2
Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
Example 2:

Input: nums = [1,1,1,1], minK = 1, maxK = 1
Output: 10
Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
 

Constraints:

2 <= nums.length <= 105
1 <= nums[i], minK, maxK <= 106

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int minK, int maxK) {
            long count = 0, start = -1, mini = -1, maxi = -1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < minK || nums[i] > maxK) start = i;
                if (nums[i] == maxK) maxi = i;
                if (nums[i] == minK) mini = i;
                int valid = max(0L, min(mini, maxi) - start);
                count += valid;
            }
            return count;
        }
 };



