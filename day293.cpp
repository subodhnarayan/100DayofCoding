-- -- -- -- -- -- -- -- -GFG - POTD - 13 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Pair Sum in BST
Difficulty: MediumAccuracy: 44.02%Submissions: 72K+Points: 4Average Time: 40m
Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target. 

Examples:

Input: root = [7, 3, 8, 2, 4, N, 9], target = 12
       bst
Output: True
Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.
Input: root = [9, 5, 10, 2, 6, N, 12], target = 23
          bst-3
Output: False
Explanation: In the binary tree above, there are no such two nodes exists that add up to 23.
Constraints:

1 ≤ Number of Nodes ≤ 105
1 ≤ target ≤ 106


class Solution {
    public:
     unordered_map<int,int> map;
  
   bool preorder(Node* root, int target) {
          
          if(root == nullptr){
              return false;
          }
          if(map.find(target - root->data) != map.end()){
              return true;
          }
          map[root->data] = 1;
          if(preorder(root->left,target)) return true;;
          if(preorder(root->right,target)) return true;
          
          return false;
      }
      bool findTarget(Node *root, int target) {
          // your code here.
          if(preorder(root,target)){
              return true;
          }
          return false;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 13 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Threshold Value II
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums, and an integer k.

In one operation, you will:

Take the two smallest integers x and y in nums.
Remove x and y from nums.
Add min(x, y) * 2 + max(x, y) anywhere in the array.
Note that you can only apply the described operation if nums contains at least two elements.

Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

 

Example 1:

Input: nums = [2,11,10,1,3], k = 10
Output: 2
Explanation: In the first operation, we remove elements 1 and 2, then add 1 * 2 + 2 to nums. nums becomes equal to [4, 11, 10, 3].
In the second operation, we remove elements 3 and 4, then add 3 * 2 + 4 to nums. nums becomes equal to [10, 11, 10].
At this stage, all the elements of nums are greater than or equal to 10 so we can stop.
It can be shown that 2 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.
Example 2:

Input: nums = [1,1,2,4,9], k = 20
Output: 4
Explanation: After one operation, nums becomes equal to [2, 4, 9, 3].
After two operations, nums becomes equal to [7, 4, 9].
After three operations, nums becomes equal to [15, 9].
After four operations, nums becomes equal to [33].
At this stage, all the elements of nums are greater than 20 so we can stop.
It can be shown that 4 is the minimum number of operations needed so that all elements of the array are greater than or equal to 20.
 

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long, vector<long>, greater<long>> min_heap(nums.begin(),
                                                                       nums.end());
            int num_operations = 0;
    
            while (min_heap.top() < k) {
                long x = min_heap.top();
                min_heap.pop();
                long y = min_heap.top();
                min_heap.pop();
                min_heap.push(min(x, y) * 2 + max(x, y));
    
                num_operations++;
            }
            return num_operations;
        }
    };