// Gfg POTD 4/7/2024
//  Duplicate Subtrees
//  Difficulty: MediumAccuracy: 23.98%Submissions: 56K+Points: 4
//  Given a binary tree, your task is to find all duplicate subtrees from the given binary tree.

// Duplicate Subtree : Two trees are duplicates if they have the same structure with the same node values.

// Note:  Return the root of each tree in the form of a list array & the driver code will print the tree in pre-order tree traversal in lexicographically increasing order.

// Examples:

// Input :

// Output: 2 4
//         4
// Explanation: The above tree have two duplicate subtrees.i.e
//   2
//  /
// 4  and 4. Therefore, you need to return the above tree root in the form of a list.
// Input:     5
//           / \
//          4   6
//         / \
//        3   4
//           / \
//          3   6
// Output:
// 3
// 6
// Explanation: In the above tree, there are two duplicate subtrees.i.e
// 3 and 6. Therefore, you need to return the above subtrees root in the form of a list. Here, 4 3  is not considered because for a subtree to be equal, it should have the same values as well as structure. If we consider the first subtree on the left, it has
// two children, 3 on the left and 4 3 6   on the right. And for the second subtree it has 3 on the left and 6 on the right.
// Since the structures are not same for the subtrees hence they are not equal
// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)

// Constraints:
// 1<= height of binary tree <=103

// class Solution {
//   public:
//     vector<Node*> ans;
//     unordered_map<string,int> mp;
//     string solu(Node* root){
//         if(root==NULL){
//             return "";
//         }
//         string l=solu(root->left);
//         string r=solu(root->right);

//         string str=to_string(root->data)+l+r;

//         if(mp.find(str)!=mp.end() && mp[str]==1){
//             ans.push_back(root);
//         }
//         mp[str]++;
//         return str;
//     }

//     vector<Node*> printAllDups(Node* root) {

//         solu(root);
//         return ans;

//     }
// };

// 2181. Merge Nodes in Between Zeros
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

// For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

// Return the head of the modified linked list.

// Example 1:

// Input: head = [0,3,1,0,4,5,2,0]
// Output: [4,11]
// Explanation:
// The above figure represents the given linked list. The modified list contains
// - The sum of the nodes marked in green: 3 + 1 = 4.
// - The sum of the nodes marked in red: 4 + 5 + 2 = 11.
// Example 2:

// Input: head = [0,1,0,3,0,2,2,0]
// Output: [1,3,4]
// Explanation:
// The above figure represents the given linked list. The modified list contains
// - The sum of the nodes marked in green: 1 = 1.
// - The sum of the nodes marked in red: 3 = 3.
// - The sum of the nodes marked in yellow: 2 + 2 = 4.

// Constraints:

// The number of nodes in the list is in the range [3, 2 * 105].
// 0 <= Node.val <= 1000
// There are no two consecutive nodes with Node.val == 0.
// The beginning and end of the linked list have Node.val == 0.

// class Solution {
// public:
//     ListNode* mergeNodes(ListNode* head) {
//          ListNode* modify = head->next; // Start from the node after the initial 0
//         ListNode* nextSum = modify;

//         while (nextSum != nullptr) {
//             int sum = 0;
//             // Find the sum of all nodes until you encounter a 0.
//             while (nextSum->val != 0) {
//                 sum += nextSum->val;
//                 nextSum = nextSum->next;
//             }

//             // Assign the sum to the current node's value.
//             modify->val = sum;
//             // Move nextSum to the first non-zero value of the next block.
//             nextSum = nextSum->next;
//             // Move modify also to this node.
//             modify->next = nextSum;
//             modify = modify->next;
//         }
//         return head->next; // Skip the initial 0 node.
//     }
// };