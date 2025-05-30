-- -- -- -- -- -- -- -- -GFG - POTD - 30 / 05 / 2025 ----------------------------------------
Closest Neighbour in BST
Difficulty: EasyAccuracy: 36.98%Submissions: 60K+Points: 2
Given the root of a binary search tree and a number k, find the greatest number in the binary search tree that is less than or equal to k.

Examples:

 

Input: root = [10, 7, 15, 2, 8, 11, 16], k = 14

Output: 11
Explanation: The greatest element in the tree which is less than or equal to 14, is 11.
Input: root = [5, 2, 12, 1, 3, 9, 21, N, N, N, N, N, N, 19, 25], k = 24

Output: 21
Explanation: The greatest element in the tree which is less than or equal to 24, is 21. 
Input: root = [5, 2, 12, 1, 3, 9, 21, N, N, N, N, N, N, 19, 25], k = 4

Output: 3
Explanation: The greatest element in the tree which is less than or equal to 4, is 3.
Constraints:
1 <= number of nodes <= 105
1 <= node->data, k <= 105
All nodes are unique in the BST

Expected Complexities
Time Complexity: O(h)
Auxiliary Space: O(h)

class Solution {
  public:
    int ans=-1;
  void Solve(Node* root,int k){
      if(root==NULL)
      return;
      if(root->data<=k){
          ans=root->data;
          Solve(root->right,k);
      }
      else
      Solve(root->left,k);
  }
    int findMaxFork(Node* root, int k) {
        // code here
          Solve(root,k);
        return ans;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 30 / 05 / 2025 ----------------------------------------


2359. Find Closest Node to Given Two Nodes
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.

The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.

You are also given two integers node1 and node2.

Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.

Note that edges may contain cycles.

 

Example 1:


Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
Output: 2
Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
Example 2:


Input: edges = [1,2,-1], node1 = 0, node2 = 2
Output: 2
Explanation: The distance from node 0 to node 2 is 2, and the distance from node 2 to itself is 0.
The maximum of those two distances is 2. It can be proven that we cannot get a node with a smaller maximum distance than 2, so we return node 2.
 

Constraints:

n == edges.length
2 <= n <= 105
-1 <= edges[i] < n
edges[i] != i
0 <= node1, node2 < n