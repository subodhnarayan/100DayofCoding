-- -- -- -- -- -- -- -- -GFG - POTD - 09 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
Maximum path sum from any node
Difficulty: MediumAccuracy: 42.92%Submissions: 92K+Points: 4Average Time: 45m
Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

Examples:

Input: root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
Output: 42
Explanation: 

Max path sum is represented using green colour nodes in the above binary tree.
Input: root[] = [-17, 11, 4, 20, -2, 10]
Output: 31
Explanation: 

Max path sum is represented using green colour nodes in the above binary tree.
Constraints:
1 ≤ number of nodes ≤ 103
-104 ≤ node->data ≤ 104


class Solution {
    public:
      // Function to return maximum path sum from any node in a tree.
       pair<int,int> solve(Node *root)
     {
         if(root==NULL)
         return {INT_MIN,0};
         
         pair<int,int> sumleft= solve(root->left);
         pair<int,int> sumright=solve(root->right);
         
         int cursum=max(root->data, root->data + max(sumleft.second, sumright.second));
         
         int golmax=max({sumleft.first, sumright.first, cursum,root->data + sumleft.second + sumright.second});
         
         return {golmax,cursum};
         
         
     }
      int findMaxSum(Node *root) {
          return max(solve(root).first,solve(root).second);
      }
  };
-- -- -- -- -- -- -- -- -LeetCode - POTD - 09 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
