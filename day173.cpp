-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 23 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Find the Sum of Last N nodes of the Linked List
Difficulty: EasyAccuracy: 61.47%Submissions: 56K+Points: 2
Given a single linked list, calculate the sum of the last n nodes.

Note: It is guaranteed that n <= number of nodes.

Examples:

Input: Linked List: 5->9->6->3->4->10, n = 3

Output: 17
Explanation: The sum of the last three nodes in the linked list is 3 + 4 + 10 = 17.
Input: Linked List: 1->2, n = 2

Output: 3
Explanation: The sum of the last two nodes in the linked list is 2 + 1 = 3.
Constraints:
1 <= number of nodes, n <= 105
1 <= node->data <= 103

int sumOfLastN_Nodes(struct Node* head, int n) {
        // Code here
          Node* temp = head;
         vector<int> ans;
         int res =0;
         
         
         while(temp != NULL){
             int d = temp -> data;
             ans.push_back(d);
             temp = temp -> next;
         }
         
         int len = ans.size();
         
         for(int i= len-n; i<len; i++ ){
             res += ans[i];
         }
         
         return res;
    }




Code



2641. Cousins in Binary Tree II
Solved
Medium
Topics
Companies
Hint
Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.

 

Example 1:


Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
Example 2:


Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 104