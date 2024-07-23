// GFG PoTD 23/7/2024

// Given two BSTs, return elements of merged BSTs in sorted form.

// Examples :

// Input:
// BST1:
//        5
//      /   \
//     3     6
//    / \
//   2   4
// BST2:
//         2
//       /   \
//      1     3
//             \
//              7
//             /
//            6
// Output: 1 2 2 3 3 4 5 6 6 7
// Explanation: After merging and sorting the two BST we get 1 2 2 3 3 4 5 6 6 7.
// Input:
// BST1:
//        12
//      /
//     9
//    / \    
//   6   11
// BST2:
//       8
//     /  \
//    5    10
//   /
//  2
// Output: 2 5 6 8 9 10 11 12
// Explanation: After merging and sorting the two BST we get 2 5 6 8 9 10 11 12.
// Expected Time Complexity: O(m+n)
// Expected Auxiliary Space: O(Height of BST1 + Height of BST2 + m + n)

// Constraints:
// 1 ≤ Number of Nodes ≤ 105

class Solution
{
public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        // what we can do is traverse the tree and parallely we can compare if we find small
        // er then we will puss that in ans vector and make next pointer
        vector<int> ans1;
        vector<int> ans2;
        inorder(root1, ans1);
        inorder(root2, ans2);

        int n1 = ans1.size();
        int n2 = ans2.size();
        int i = 0, j = 0;

        vector<int> ans;
        while (i < n1 && j < n2)
        {
            if (ans1[i] >= ans2[j])
            {
                ans.push_back(ans2[j]);
                j++;
            }
            else
            {
                ans.push_back(ans1[i]);
                i++;
            }
        }

        while (i < n1)
        {
            ans.push_back(ans1[i]);
            i++;
        }
        while (j < n2)
        {
            ans.push_back(ans2[j]);
            j++;
        }
        return ans;
    }
};

// 1636. Sort Array by Increasing Frequency
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.

// Return the sorted array.

// Example 1:

// Input: nums = [1,1,2,2,2,3]
// Output: [3,1,1,2,2,2]
// Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
// Example 2:

// Input: nums = [2,3,1,3,2]
// Output: [1,3,3,2,2]
// Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
// Example 3:

// Input: nums = [-1,1,-6,4,5,-6,1,4,1]
// Output: [5,-1,4,4,-6,-6,1,1,1]

// Constraints:

// 1 <= nums.length <= 100
// -100 <= nums[i] <= 100

class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void inorder(Node* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    
    vector<int> merge(Node *root1, Node *root2) {
       //what we can do is traverse the tree and parallely we can compare if we find small
       //er then we will puss that in ans vector and make next pointer
       vector<int> ans1;
       vector<int> ans2;
       inorder(root1,ans1);
       inorder(root2,ans2);
       
       int n1=ans1.size();
       int n2=ans2.size();
       int i=0,j=0;
        
       vector<int> ans;
       while(i<n1 && j<n2){
           if(ans1[i]>=ans2[j]){
               ans.push_back(ans2[j]);
               j++;
           }
           else{
               ans.push_back(ans1[i]);
               i++;
           }
       }
       
       while(i<n1){
            ans.push_back(ans1[i]);
            i++;
       }
       while(j<n2){
           ans.push_back(ans2[j]);
           j++;
       }
       return ans;
    }
};