-- -- -- -- -- -- -- -- -GFG - POTD - 02 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Level order traversal
Difficulty: EasyAccuracy: 70.31%Submissions: 224K+Points: 2
Given a root of a binary tree with n nodes, the task is to find its level order traversal. Level order traversal of a tree is breadth-first traversal for the tree.

Examples:

Input: root[] = [1, 2, 3]

Output: [[1], [2, 3]]
Input: root[] = [10, 20, 30, 40, 50]

Output: [[10], [20, 30], [40, 50]]
Input: root[] = [1, 3, 2, N, N, N, 4, 6, 5]

Output: [[1], [3, 2], [4], [6, 5]]
Constraints:

1 ≤ number of nodes ≤ 105
0 ≤ node->data ≤ 109

class Solution {
  public:
  
    vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>> ans;
            queue<Node*>pq;
            pq.push(root);
            vector<int> init;
            
        init.push_back (root->data);
        ans.push_back(init);
        
        while (!pq.empty()) {
            
                vector <int> temp;
                Node * curr = pq.front();
                pq.pop ();
            
            if (curr->left){
                
                temp.push_back(curr->left->data);
                pq.push(curr->left);
            }
            if(curr->right){
                
                temp.push_back(curr->right->data);
                pq.push(curr->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


-- -- -- -- -- -- -- -- -LeetCode - POTD - 02 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


1752. Check if Array Is Sorted and Rotated
Solved
Easy
Topics
Companies
Hint
Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

There may be duplicates in the original array.

Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] is the original sorted array.
You can rotate the array by x = 3 positions to begin on the the element of value 3: [3,4,5,1,2].
Example 2:

Input: nums = [2,1,3,4]
Output: false
Explanation: There is no sorted array once rotated that can make nums.
Example 3:

Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is the original sorted array.
You can rotate the array by x = 0 positions (i.e. no rotation) to make nums.
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100


class Solution {
public:
    bool check(vector<int>& nums) {
         int count = 0, n = nums.size();
        for (int i = 0; i < n; i++) 
            if (nums[i] > nums[(i+1)%n] && ++count > 1) return false;
        return true;
    }
};

