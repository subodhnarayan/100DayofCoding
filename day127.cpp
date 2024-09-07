- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 5 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --




Nth Natural Number
Difficulty: MediumAccuracy: 29.99%Submissions: 73K+Points: 4
Given a positive integer n. You have to find nth natural number after removing all the numbers containing the digit 9.

Examples :

Input: n = 8
Output: 8
Explanation: After removing natural numbers which contains digit 9, first 8 numbers are 1,2,3,4,5,6,7,8 and 8th number is 8.
Input: n = 9
Output: 10
Explanation: After removing natural numbers which contains digit 9, first 9 numbers are 1,2,3,4,5,6,7,8,10 and 9th number is 10.
Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)


Constraints:
1 ≤ n ≤ 109



class Solution {
  public:
    long long findNth(long long n) {
        // code here.
          long long r,res=0;
        int i=0;
        while (n>0){
            res+=pow(10,i++)*(n%9);
            n/=9;
        }
        return res;
    }
};

- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode- POTD -7 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --



1367. Linked List in Binary Tree
Medium
Topics
Companies
Hint
Given a binary tree root and a linked list with head as the first node. 

Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.

In this context downward path means a path that starts at some node and goes downwards.

 

Example 1:



Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.  
Example 2:



Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Example 3:

Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
 

Constraints:

The number of nodes in the tree will be in the range [1, 2500].
The number of nodes in the list will be in the range [1, 100].
1 <= Node.val <= 100 for each node in the linked list and binary tree.



class Solution {
public:
     bool dfs(ListNode* head, ListNode* cur, TreeNode* root) {
        if (cur == nullptr) return true;  // Successfully matched the list
        if (root == nullptr) return false; // Reached the end of the tree without matching
        
        if (cur->val == root->val) {
            cur = cur->next;  // Move to the next list node if value matches
        } else if (head->val == root->val) {
            head = head->next; // Start new matching attempt if the value matches head of list
        } else {
            cur = head;  // Reset the matching pointer
        }
        
        return dfs(head, cur, root->left) || dfs(head, cur, root->right); // Recursively check left and right subtrees
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
       return dfs(head, head, root);
    }
};