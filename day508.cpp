-- -- -- -- -- -- -- -- -GFG - POTD - 19 / 05 / 2025 ----------------------------------------

Predecessor and Successor
Difficulty: MediumAccuracy: 47.36%Submissions: 147K+Points: 4
You are given root node of the BST and an integer key. You need to find the in-order successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor. 

Examples :

Input: root[] = [8, 1, 9, N, 4, N, 10, 3, N, N, N], key = 8

Output: 4 9
Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
Input: root[] = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N], key = 11

Output: 10 -1
Explanation: In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
Input: root[] = [2, 1, 3], key = 3

Output: 2 -1
Explanation: In given BST, the inorder predecessor of 3 is 2 whereas it does not have any inorder successor.
Constraints: 
1 <= no. of nodes <= 105
1 <= node->data <= 106
1 <= key <= 106

Expected Complexities
Time Complexity: O(Height of the BST)
Auxiliary Space: O(1)

class Solution {
  public:
   //lets look for a better solution
  Node* l = nullptr;
  Node* r = nullptr;
  
   void solve(Node* node, int key){
       if(!node) return;
       if(node->data<key){
           if(!l) l = node;
           else if(l && l->data<node->data) l = node;
       }
       
       else if(node->data>key){
           if(!r) r = node;
           else if(r && r->data>node->data) r = node;
       }
       
       solve(node->left,key);
       solve(node->right,key);
   }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        solve(root,key);
      
      while(root){
          if(root->data==key){
              if(root->left){
                  Node* temp = root->left;
                  while(temp->right) temp = temp->right;
                  l = temp;
              }
              
              if(root->right){
                  Node* temp = root->right;
                  while(temp->left) temp = temp->left;
                  r = temp;
              }
              
              break;
          }
          
          else if(root->data<key){
              l = root;
              root = root->right;
          }
          
          else{
              r = root;
              root = root->left;
          }
      }
        
         return {l,r};
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 19 / 05 / 2025 ----------------------------------------
3024. Type of Triangle
Solved
Easy
Topics
Companies
Hint
You are given a 0-indexed integer array nums of size 3 which can form the sides of a triangle.

A triangle is called equilateral if it has all sides of equal length.
A triangle is called isosceles if it has exactly two sides of equal length.
A triangle is called scalene if all its sides are of different lengths.
Return a string representing the type of triangle that can be formed or "none" if it cannot form a triangle.

 

Example 1:

Input: nums = [3,3,3]
Output: "equilateral"
Explanation: Since all the sides are of equal length, therefore, it will form an equilateral triangle.
Example 2:

Input: nums = [3,4,5]
Output: "scalene"
Explanation: 
nums[0] + nums[1] = 3 + 4 = 7, which is greater than nums[2] = 5.
nums[0] + nums[2] = 3 + 5 = 8, which is greater than nums[1] = 4.
nums[1] + nums[2] = 4 + 5 = 9, which is greater than nums[0] = 3. 
Since the sum of the two sides is greater than the third side for all three cases, therefore, it can form a triangle.
As all the sides are of different lengths, it will form a scalene triangle.
 

Constraints:

nums.length == 3
1 <= nums[i] <= 100

class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[0] + nums[1] <= nums[2]) {
            return "none";
        } else if (nums[0] == nums[2]) {
            return "equilateral";
        } else if (nums[0] == nums[1] || nums[1] == nums[2]) {
            return "isosceles";
        } else {
            return "scalene";
        }
    }
};