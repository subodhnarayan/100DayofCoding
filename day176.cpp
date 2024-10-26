-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 26 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Occurence of an integer in a Linked List
Difficulty: EasyAccuracy: 80.07%Submissions: 74K+Points: 2
Given a singly linked list and a key, count the number of occurrences of the given key in the linked list.

Examples:

Input: Linked List: 1->2->1->2->1->3->1, key = 1

Output: 4
Explanation: 1 appears 4 times. 
Input: Linked List: 1->2->1->2->1, key = 3

Output: 0
Explanation: 3 appears 0 times.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ number of nodes, key ≤ 105
1 ≤ data of node ≤ 105

class Solution {
  public:
    int count(struct Node* head, int key) {
        
        int count=0;
        Node* curr=head;
        while(curr){
            if(curr->data==key){
                count++;
            }
            curr=curr->next;
        }
        return count;
    }
};



-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -LeetCode - POTD - 26 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

2458. Height of Binary Tree After Subtree Removal Queries
Solved
Hard
Topics
Companies
Hint
You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.

You have to perform m independent queries on the tree where in the ith query you do the following:

Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.

Note:

The queries are independent, so the tree returns to its initial state after each query.
The height of a tree is the number of edges in the longest simple path from the root to some node in the tree.
 

Example 1:


Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
Output: [2]
Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
The height of the tree is 2 (The path 1 -> 3 -> 2).
Example 2:


Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
Output: [3,2,3,2]
Explanation: We have the following queries:
- Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 4).
- Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -> 8 -> 1).
- Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
- Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -> 9 -> 3).
 

Constraints:

The number of nodes in the tree is n.
2 <= n <= 105
1 <= Node.val <= n
All the values in the tree are unique.
m == queries.length
1 <= m <= min(n, 104)
1 <= queries[i] <= n
queries[i] != root.val

class Solution {
public:
     vector<int> depth, levelArr, max1, max2;
     int height(TreeNode* root, int level) {
        if (!root) return 0;
        levelArr[root->val] = level;
        depth[root->val] = 1 + max(height(root->left, level + 1), height(root->right, level + 1));

    
        if (max1[level] < depth[root->val]) {
            max2[level] = max1[level];
            max1[level] = depth[root->val];
        } else if (max2[level] < depth[root->val]) {
            max2[level] = depth[root->val];
        }

        return depth[root->val];
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        depth.resize(100001, 0);
        levelArr.resize(100001, 0);
        max1.resize(100001, 0);
        max2.resize(100001, 0);

        // Compute depths and max depths for each level
        height(root, 0);

        // Process each query
        for (int i = 0; i < queries.size(); i++) {
            int q = queries[i];
            int level = levelArr[q];
            queries[i] = (max1[level] == depth[q] ? max2[level] : max1[level]) + level - 1;
        }

        return queries;
    }
};