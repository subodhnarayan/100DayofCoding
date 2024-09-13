

Mirror Tree
Difficulty: EasyAccuracy: 72.67%Submissions: 202K+Points: 2
Given a Binary Tree, convert it into its mirror.
MirrorTree1            

Examples:

Input:
      1
    /  \
   2    3
Output: 3 1 2
Explanation: The tree is
  1    (mirror)     1
 /  \    =>        /  \
2    3           3   2
The inorder of mirror is 3 1 2
Input:
      10
     /  \
    20   30
   /  \
  40  60
Output: 30 10 60 20 40
Explanation: The tree is
      10               10
    /    \  (mirror)    /    \
   20    30    =>   30    20
  /  \                     /   \
 40  60                 60   40
The inroder traversal of mirror is: 30 10 60 20 40.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(height of the tree)

Constraints:
1 ≤ Number of nodes ≤ 105
1 ≤ Data of a node ≤ 105



class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(node==NULL) return ;
        Node *temp=node->right;
        node->right=node->left;
        node->left=temp;
        mirror(node->left);
        mirror(node->right);
    }
};



1310. XOR Queries of a Subarray
Solved
Medium
Topics
Companies
Hint
You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].

For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).

Return an array answer where answer[i] is the answer to the ith query.

 

Example 1:

Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
Example 2:

Input: arr = [4,8,2,10], queries = [[2,3],[1,3],[0,0],[0,3]]
Output: [8,0,4,4]
 

Constraints:

1 <= arr.length, queries.length <= 3 * 104
1 <= arr[i] <= 109
queries[i].length == 2
0 <= lefti <= righti < arr.length


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
          int n = arr.size();
        vector<int> pre(n);
        pre[0] = arr[0];
        
        // Compute prefix XOR array
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] ^ arr[i];
        }
        
        std::vector<int> res(queries.size());
        
        // Answer each query
        for (int k = 0; k < queries.size(); ++k) {
            int i = queries[k][0];
            int j = queries[k][1];
            if (i == 0) {
                res[k] = pre[j];
            } else {
                res[k] = pre[j] ^ pre[i - 1];
            }
        }
        
        return res;
    }
};
