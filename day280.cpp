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
