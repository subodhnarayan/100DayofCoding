-- -- -- -- -- -- -- -- -GFG - POTD - 14 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Fixing Two nodes of a BST
Difficulty: HardAccuracy: 53.68%Submissions: 59K+Points: 8Average Time: 45m
Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original Binary search tree(BST).
 
Examples :
Input: root = [10, 5, 8, 2, 20]
     
Output: 1
       

Explanation: The nodes 20 and 8 were swapped. 
Input: root = [5, 10, 20, 2, 8]
     
Output: 1 
     
Explanation: The nodes 10 and 5 were swapped.
Constraints:
1 ≤ Number of nodes ≤ 103


class Solution {
    public:
    void inorder(Node* root, vector<Node*> &v){
          if(root==NULL){
              return;
          }
          inorder(root->left,v);
          v.push_back(root);
          inorder(root->right,v);
      }
      void correctBST(Node* root) {
          vector<Node*> in;
          inorder(root,in);
          Node* a=NULL;
          Node* b=NULL;
          Node* c=NULL;
          bool s1=false,s2=false;
          for(int i=0;i<in.size()-1;i++){
              if(in[i]->data > in[i+1]->data && s1==false){
                  a=in[i];
                  b=in[i+1];
                  s1=true;
                  continue;
              }
              else if(in[i]->data > in[i+1]->data && s2==false ){
                  c=in[i+1];
                  s2=true;
                  break;
              }
          }
          if(a && b && c){
              swap(a->data,c->data);
          }
          else{
              swap(a->data,b->data);
          }
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 14 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

