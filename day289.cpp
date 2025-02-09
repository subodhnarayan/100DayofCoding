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

2364. Count Number of Bad Pairs
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

Return the total number of bad pairs in nums.

 

Example 1:

Input: nums = [4,1,3,3]
Output: 5
Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
There are a total of 5 bad pairs, so we return 5.
Example 2:

Input: nums = [1,2,3,4,5]
Output: 0
Explanation: There are no bad pairs.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109


class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            unordered_map<int, int> freq;
            long long goodPairs = 0, n = nums.size();
            
            for (int i = 0; i < n; i++) {
                int key = nums[i] - i;
                goodPairs += freq[key];
                freq[key]++;
            }
            
            return (n * (n - 1)) / 2 - goodPairs;
        }
    };