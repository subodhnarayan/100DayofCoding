- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 25 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Number of pairs
Difficulty: MediumAccuracy: 21.82%Submissions: 82K+Points: 4
Given two positive integer arrays arr and brr, find the number of pairs such that xy > yx (raised to power of) where x is an element from arr and y is an element from brr.

Examples :

Input: arr[] = [2, 1, 6], brr[] = [1, 5]
Output: 3
Explanation: The pairs which follow xy > yx are: 21 > 12,  25 > 52 and 61 > 16 .
Input: arr[] = [2 3 4 5], brr[] = [1 2 3]
Output: 5
Explanation: The pairs which follow xy > yx are: 21 > 12 , 31 > 13 , 32 > 23 , 41 > 14 , 51 > 15 .
Expected Time Complexity: O((N + M)log(N)).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ arr.size(), brr.size() ≤ 105
1 ≤ brr[i], arr[i] ≤ 103



class Solution {
  public:
    int binarysearch(vector<int> brr,int key){
      int low=0;
      int high=brr.size()-1;
      int idx=-1;
      while(low<=high){
          int mid=(low+high)/2;
          if(brr[mid]<=key){
              idx=mid;
              low=mid+1;
          }
          else{
          high=mid-1;
      }
      }
      return idx;
    }
    long long countPairs(vector<int> &arr, vector<int> &brr) {
    //   int n=arr.size();
    //   int  m=brr.size();
    //   long long count=0;
    //   for(int i=0;i<n;i++){
    //       for(int j=0;j<m;j++){
    //           if(pow(arr[i],brr[j])>pow(brr[j],arr[i]))
    //           {
    //               count++;
    //           }
    //       }
    //   }
    //   return count;  brute force o(n2)
    
    
       long long ans=0;
        long long one=0;
        long long two=0;
        long long threefour=0;
        sort(brr.begin(),brr.end());
        
        for(auto x:brr){
            if(x==1) one++;
            else if(x==2) two++;
            else if(x==3 || x==4) threefour++;
        }
        
        for(auto x:arr){
            if(x!=1) {
                ans=ans+one;
            
            if(x==2){
                ans=ans-threefour;
            }
            if(x==3){
                ans=ans+two;
            }
            int index=binarysearch(brr,x);
            ans=ans+(brr.size()-index-1);
        }
        
     }
        return ans;
    }
};


- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 25 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

145. Binary Tree Postorder Traversal
Solved
Easy
Topics
Companies
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:


Input: root = [1,null,2,3]
Output: [3,2,1]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]
 

Constraints:

The number of the nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?

class Solution {
public:
    void postorder(vector<int> &ans,TreeNode* root){
        if(root==NULL){
            return;
        }
        postorder(ans,root->left);
        postorder(ans,root->right);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(ans,root);
        return ans;
    }
};