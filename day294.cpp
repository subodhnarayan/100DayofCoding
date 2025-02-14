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

1352. Product of the Last K Numbers
Solved
Medium
Topics
Companies
Hint
Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

 

Example:

Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]

Output
[null,null,null,null,null,null,20,40,0,null,32]

Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
 

Constraints:

0 <= num <= 100
1 <= k <= 4 * 104
At most 4 * 104 calls will be made to add and getProduct.
The product of the stream at any point in time will fit in a 32-bit integer.
 

Follow-up: Can you implement both GetProduct and Add to work in O(1) time complexity instead of O(k) time complexity?


class ProductOfNumbers {
    public:
        vector<int> list;
        int prod = 1;
        ProductOfNumbers() {
            
        }
        
        void add(int num) {
             if (num == 0) {
                list.clear();
                prod = 1;
            } else {
                prod *= num;
                list.push_back(prod);
            }
        }
        
        int getProduct(int k) {
            if (list.size() < k) return 0;
            if (list.size() == k) return list.back();
            return list.back() / list[list.size() - k - 1];
        }
    };