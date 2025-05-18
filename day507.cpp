-- -- -- -- -- -- -- -- -GFG - POTD - 18 / 05 / 2025 ----------------------------------------

Level Order in spiral form
Difficulty: EasyAccuracy: 36.43%Submissions: 227K+Points: 2Average Time: 20m
Given a binary tree and the task is to find the spiral order traversal of the tree and return the list containing the elements.
Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right.
For below tree, function should return [1, 2, 3, 4, 5, 6, 7]

 

Examples:

Input: root = [1, 3, 2]
 
Output: [1, 3, 2]
Explanation: Start with root (1), print level 0 (right to left), then level 1 (left to right).
Input: root = [10, 20, 30, 40, 60]

Output: [10, 20, 30, 60, 40]
Explanation: Start with root (10), print level 0 (right to left), level 1 (left to right), and continue alternating.
Input: root = [1, 2, N, 4]
  
Output: [1, 2, 4]
Explanation: Start with root (1), then level 1 (left to right), then level 2 (right to left).
Constraints:
1 <= number of nodes <= 105
0 <= node->data <= 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

class Solution {
  public:
    vector<int> findSpiral(Node* root) {
        // code here
        bool can_sort = true;
        vector<int>v;
        queue<Node*>q;
        q.push(root);
        while(q.size())
        {
            int cur_q_size = q.size();
            int prev = v.size();
            while(cur_q_size --> 0)
            {
                auto node = q.front();
                v.push_back(node -> data);
                q.pop();
                if(node -> left)q.push(node -> left);
                if(node -> right)q.push(node -> right);
            }
            if(can_sort)
            {
                // cout<<"prev "<<prev<<endl;
                // for(auto &it : v)cout<<it<<" "; cout<<endl;
                reverse(v.begin() + prev, v.end());
                // for(auto &it : v)cout<<it<<" "; cout<<endl;
            }
            can_sort = !can_sort;
        }
        return v;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 18 / 05 / 2025 ----------------------------------------

1931. Painting a Grid With Three Different Colors
Solved
Hard
Topics
Companies
Hint
You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.

Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:


Input: m = 1, n = 1
Output: 3
Explanation: The three possible colorings are shown in the image above.
Example 2:


Input: m = 1, n = 2
Output: 6
Explanation: The six possible colorings are shown in the image above.
Example 3:

Input: m = 5, n = 5
Output: 580986
 

Constraints:

1 <= m <= 5
1 <= n <= 1000
