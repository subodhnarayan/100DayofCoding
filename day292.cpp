-- -- -- -- -- -- -- -- -GFG - POTD - 12 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

k-th Smallest in BST
Difficulty: MediumAccuracy: 43.53%Submissions: 134K+Points: 4Average Time: 40m
Given a BST and an integer k, the task is to find the kth smallest element in the BST. If there is no kth smallest element present then return -1.

Examples:

Input: root = [2, 1, 3], k = 2
    
Output: 2
Explanation: 2 is the 2nd smallest element in the BST.
Input: root = [2, 1, 3], k = 5
    
Output: -1
Explanation: There is no 5th smallest element in the BST as the size of BST is 3.
Input: root = [20, 8, 22, 4, 12, N, N, N, N, 10, 14], k = 3
     
Output: 10
Explanation: 10 is the 3rd smallest element in the BST.
Constraints:

1 <= number of nodes, k <= 105
1 <= node->data <= 105

class Solution {
    public:
      // Return the Kth smallest element in the given BST
      void inorder(Node* root,vector<int> &ans){
          if(root==NULL) return;
          inorder(root->left,ans);
          ans.push_back(root->data);
          inorder(root->right,ans);
          return;
      }
      
      int kthMinEle = -1;
      void solve(Node *root, int& k){
          if(root == NULL){
              return;
          }
           
          if(k == 0){
              return;
          }
          
          solve(root->left, k);
         
          if(root->data > kthMinEle && k > 0){
              kthMinEle = root->data;
              --k;
          }
          
          solve(root->right, k);
          return;
      }
      
      int kthSmallest(Node *root, int k) {
          // vector<int> ans;
          // inorder(root,ans);
          // if(k>ans.size()) return -1;
          // return ans[k-1];
          solve(root, k);
          if(k > 0){
              return -1;
          }
          return kthMinEle;
      }
  };

-- -- -- -- -- -- -- -- -LeetCode - POTD - 12 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

2342. Max Sum of a Pair With Equal Sum of Digits
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

 

Example 1:

Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.
Example 2:

Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109



class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            int max[82] = {0};
            int ans = -1;
            for (int x : nums) {
                int sum = 0, temp = x;
                while (temp != 0) {
                    sum += temp % 10;
                    temp /= 10;
                }
                if (max[sum] != 0) ans = std::max(ans, x + max[sum]);
                max[sum] = std::max(max[sum], x);
            }
            return ans;
        }
    };