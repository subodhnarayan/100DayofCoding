-- -- -- -- -- -- -- -- -GFG - POTD - 07 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Tree Boundary Traversal
Difficulty: MediumAccuracy: 23.33%Submissions: 432K+Points: 4Average Time: 35m
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Examples:

Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:

Input: root[] = [1, 2, N, 4, 9, 6, 5, N, 3, N, N, N, N 7, 8]
Output: [1, 2, 4, 6, 5, 7, 8]
Explanation:












As the root doesn't have a right subtree, the right boundary is not included in the traversal.
Input: root[] = [1, N, 2, N, 3, N, 4, N, N] 
    1
     \
      2
       \
        3
         \
          4

Output: [1, 4, 3, 2]
Explanation:
Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105


class Solution {
    public:
    void helper(Node* root,vector<int>&v){
          if(root==NULL) return;
          if(root->left==NULL && root->right==NULL){
              if(root->data!=-1) v.push_back(root->data);
              root->data=-1;
              return;
          }
          helper(root->left,v);
          helper(root->right,v);
      }
      vector<int> boundaryTraversal(Node *root) {
          // code here
          
          vector<int>ans;
          Node* temp=root;
          while(temp){
              ans.push_back(temp->data);
              temp->data=-1;
              if(temp->left==NULL && temp!=root) temp=temp->right;
              else temp=temp->left;
          }
          helper(root,ans);
          int l=ans.size();
          temp=root;
          temp=temp->right;
          while(temp && temp->data!=-1){
              ans.push_back(temp->data);
              temp->data=-1;
              if(temp->right==NULL) temp=temp->left;
              else temp=temp->right;
          }
          if(l>=ans.size()) return ans;
          int r=ans.size()-1;
          while(l<r){
              swap(ans[l],ans[r]);
              l++;
              r--;
          }
          return ans;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 07 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

2349. Design a Number Container System
Solved
Medium
Topics
Companies
Hint
Design a number container system that can do the following:

Insert or Replace a number at the given index in the system.
Return the smallest index for the given number in the system.
Implement the NumberContainers class:

NumberContainers() Initializes the number container system.
void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.
 

Example 1:

Input
["NumberContainers", "find", "change", "change", "change", "change", "find", "change", "find"]
[[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
Output
[null, -1, null, null, null, null, 1, null, 2]

Explanation
NumberContainers nc = new NumberContainers();
nc.find(10); // There is no index that is filled with number 10. Therefore, we return -1.
nc.change(2, 10); // Your container at index 2 will be filled with number 10.
nc.change(1, 10); // Your container at index 1 will be filled with number 10.
nc.change(3, 10); // Your container at index 3 will be filled with number 10.
nc.change(5, 10); // Your container at index 5 will be filled with number 10.
nc.find(10); // Number 10 is at the indices 1, 2, 3, and 5. Since the smallest index that is filled with 10 is 1, we return 1.
nc.change(1, 20); // Your container at index 1 will be filled with number 20. Note that index 1 was filled with 10 and then replaced with 20. 
nc.find(10); // Number 10 is at the indices 2, 3, and 5. The smallest index that is filled with 10 is 2. Therefore, we return 2.
 

Constraints:

1 <= index, number <= 109
At most 105 calls will be made in total to change and find.


class NumberContainers {
    std::map<int, int> indexToNum;
    std::map<int, std::set<int>> numToIndices;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
         if (indexToNum.count(index)) {
            int oldNum = indexToNum[index];
            numToIndices[oldNum].erase(index);

            // Remove the key if the set becomes empty
            if (numToIndices[oldNum].empty()) {
                numToIndices.erase(oldNum);
            }
        }

        indexToNum[index] = number;
        numToIndices[number].insert(index);
    }
    
    int find(int number) {
        return numToIndices.count(number) ? *numToIndices[number].begin() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */