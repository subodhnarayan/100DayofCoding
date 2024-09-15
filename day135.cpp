- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 15 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Binary Tree to DLL
Difficulty: HardAccuracy: 53.36%Submissions: 152K+Points: 8
Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes will be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as the order of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Note: h is the tree's height, and this space is used implicitly for the recursion stack.

TreeToList

Examples:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3

Explanation: DLL would be 3<=>1<=>2
Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40

Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.
Expected Time Complexity: O(no. of nodes)
Expected Space Complexity: O(height of the tree)

Constraints:
1 ≤ Number of nodes ≤ 105
0 ≤ Data of a node ≤ 105


class Solution {
  public:
    void inorder(Node* root,vector<int> &ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
        
    }
    Node* bToDLL(Node* root) {
       vector<int> ans;
       inorder(root,ans);
       Node* head=new Node(ans[0]);
       Node* curr=head;
       int n=ans.size();
       for(int i=1;i<n;i++){
          Node* newnode=new Node(ans[i]);
          curr->right=newnode;
          newnode->left=curr;
          curr=newnode;
       }
       return head;
    }
};



- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 15 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
