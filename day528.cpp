-- -- -- -- -- -- -- -- -GFG - POTD - 09 / 06 / 2025 ----------------------------------------

BST with Dead End
Difficulty: MediumAccuracy: 35.99%Submissions: 91K+Points: 4
You are given a Binary Search Tree (BST) containing unique positive integers greater than 0.

Your task is to determine whether the BST contains a dead end.

Note: A dead end is a leaf node in the BST such that no new node can be inserted in the BST at or below this node while maintaining the BST property and the constraint that all node values must be > 0.

Examples:

Input: root[] = [8, 5, 9, 2, 7, N, N, 1]

Output: true
Explanation: Node 1 is a Dead End in the given BST.
Input: root[] = [8, 7, 10, 2, N, 9, 13]

Output: true
Explanation: Node 9 is a Dead End in the given BST.
Constraints:
1 ≤ number of nodes ≤ 3000
1 ≤ node->data ≤ 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(h)

/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
   vector<int> arr, leaf;
   
   void inorder(Node* node){
        if(!node)
            return;
        
        inorder(node->left);
        arr.push_back(node->data);
        if(!node->left && !node->right)
            leaf.push_back(node->data);
        inorder(node->right);
    }
    
    bool isDeadEnd(Node *root) {
        // Code here
        arr = {0}; 
        leaf = {};
        inorder(root);
        
        int j = 0;
        for(int i = 1; i < arr.size() && j < leaf.size(); ++i){
            if(arr[i] == leaf[j]){
                if(arr[i-1] == leaf[j] - 1 && arr[i+1] == leaf[j] + 1)
                    return true;
                ++j;
            }
        }
        
        return false;
        
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 09 / 06 / 2025 ----------------------------------------

440. K-th Smallest in Lexicographical Order
Solved
Hard
Topics
premium lock icon
Companies
Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

 

Example 1:

Input: n = 13, k = 2
Output: 10
Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
Example 2:

Input: n = 1, k = 1
Output: 1
 

Constraints:

1 <= k <= n <= 109