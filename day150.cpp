-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 30 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Merge two BST 's
Difficulty: MediumAccuracy: 64.95%Submissions: 86K+Points: 4
Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input:
BST1:
       5
     /   \
    3     6
   / \
  2   4  
BST2:
        2
      /   \
     1     3
            \
             7
            /
           6
Output: 1 2 2 3 3 4 5 6 6 7
Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
Input:
BST1:
       12
     /   
    9
   / \    
  6   11
BST2:
      8
    /  \
   5    10
  /
 2
Output: 2 5 6 8 9 10 11 12
Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
Expected Time Complexity: O((m+n)*log(m+n))
Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

Constraints:
1 ≤ Number of Nodes, value of nodes ≤ 105




/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void preorder(Node* root,vector<int> &an){
        if(root==NULL){
            return;
        }
        
            an.push_back(root->data);
        preorder(root->left,an);
        preorder(root->right,an);
    }
    vector<int> merge(Node *root1, Node *root2) {
      vector<int> an1;
      vector<int> an2;
      preorder(root1,an1);
      preorder(root2,an2);
      for(int i=0;i<an2.size();i++){
          an1.push_back(an2[i]);
      }
      sort(an1.begin(),an1.end());
      return an1;
    }
};




