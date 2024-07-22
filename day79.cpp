GFG POTD 22/7/2024 
// Largest BST
// Difficulty: MediumAccuracy: 29.73%Submissions: 138K+Points: 4
// Given a binary tree. Find the size of its largest subtree which is a Binary Search Tree.
// Note: Here Size equals the number of nodes in the subtree.

// Examples :

// Input:   1
//         /  \
//         4   4              
//        / \ 
//       6   8
// Output: 1 
// Explanation: There's no sub-tree with size greater than 1 which forms a BST. All the leaf Nodes are the BSTs with size equal to 1.

// Input:    6
//         /   \
//       6      2              
//        \    / \
//         2  1   3
// Output: 3
// Explanation: The following sub-tree is a BST of size 3:  2
//                                                        /   \
//                                                       1     3
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(Height of the BST).

// Constraints:
// 1 ≤ Number of nodes ≤ 105
// 1 ≤ Data of a node ≤ 106


class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
 
    int res = 1;
    vector<int> rec( Node* root ){
        vector<int> l = {1,0,INT_MIN,INT_MAX}, r = {1,0,INT_MIN,INT_MAX};
        if ( root->left ) l = rec(root->left);
        if ( root->right ) r = rec(root->right);
        if ( l[0] != -1 && r[0] != -1 && l[2] < root->data && r[3] > root->data ){
            res = max(res, l[1]+r[1]+1);
            if ( l[2] == INT_MIN && l[3] == INT_MAX ){
                l[2] = root->data; l[3] = root->data;
            }
            if ( r[2] == INT_MIN && r[3] == INT_MAX ){
                r[2] = root->data; r[3] = root->data;
            }
            return {1, l[1]+r[1]+1, max({root->data,l[2],l[3],r[2],r[3]}), 
                                min({root->data,l[2],l[3],r[2],r[3]})};
        } else return {-1, l[1]+r[1]+1, max({root->data,l[2],l[3],r[2],r[3]}), 
                                min({root->data,l[2],l[3],r[2],r[3]})};
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	rec(root); return res;
    }
};


2418. Sort the People
Solved
Easy
Topics
Companies
Hint
You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.
Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
 

Constraints:

n == names.length == heights.length
1 <= n <= 103
1 <= names[i].length <= 20
1 <= heights[i] <= 105
names[i] consists of lower and upper case English letters.
All the values of heights are distinct.

