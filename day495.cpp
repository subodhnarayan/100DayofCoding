-- -- -- -- -- -- -- -- -GFG - POTD - 06 / 05 / 2025 -----------------------------------
Left View of Binary Tree
Difficulty: EasyAccuracy: 33.74%Submissions: 556K+Points: 2Average Time: 20m
You are given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

If the tree is empty, return an empty list.

Examples :

Input: root[] = [1, 2, 3, 4, 5, N, N]

Output: [1, 2, 4]
Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

Input: root[] = [1, 2, 3, N, N, 4, N, N, 5, N, N]

Output: [1, 2, 4, 5]
Explanation: From the left side of the tree, the nodes 1, 2, 4, and 5 are visible.

Input: root[] = [N]
Output: []
Constraints:
0 <= number of nodes <= 106
0 <= node -> data <= 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)


class Solution {
    public:
      vector<int> leftView(Node *root) {
          // code here
           vector<int> result;
          if (!root) return result;
          
          queue<Node*>q;
          q.push(root);
          
          while(!q.empty()){
              
              int n=q.size();
              Node* curr = q.front();
              result.push_back(curr->data);
              
              while(n--){
                  Node* x = q.front();
                  q.pop();
                  if(x->left)
                  q.push(x->left);
                  if(x->right)
                  q.push(x->right);
              }
          }
          return result;
      }
  };

-- -- -- -- -- -- -- -- -Leetcode - POTD - 06 / 05 / 2025 -----------------------------------



Code
Testcase
Testcase
Test Result
1920. Build Array from Permutation
Solved
Easy
Topics
Companies
Hint
Given a zero-based permutation nums (0-indexed), build an array ans of the same length where ans[i] = nums[nums[i]] for each 0 <= i < nums.length and return it.

A zero-based permutation nums is an array of distinct integers from 0 to nums.length - 1 (inclusive).

 

Example 1:

Input: nums = [0,2,1,5,3,4]
Output: [0,1,2,4,5,3]
Explanation: The array ans is built as follows: 
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[0], nums[2], nums[1], nums[5], nums[3], nums[4]]
    = [0,1,2,4,5,3]
Example 2:

Input: nums = [5,0,1,2,3,4]
Output: [4,5,0,1,2,3]
Explanation: The array ans is built as follows:
ans = [nums[nums[0]], nums[nums[1]], nums[nums[2]], nums[nums[3]], nums[nums[4]], nums[nums[5]]]
    = [nums[5], nums[0], nums[1], nums[2], nums[3], nums[4]]
    = [4,5,0,1,2,3]
 

Constraints:

1 <= nums.length <= 1000
0 <= nums[i] < nums.length
The elements in nums are distinct.
 

Follow-up: Can you solve it without using an extra space (i.e., O(1) memory)?



class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
              for (int i = 0; i < nums.size(); i++) 
                nums[i] += (1024 * (nums[nums[i]] % 1024));
            
            for (int i = 0; i < nums.size(); i++) 
                nums[i] /= 1024;
            
            return nums;
        }
};