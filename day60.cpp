// GFG POTD 1/7/2024
//  Make Binary Tree From Linked List
//  Difficulty: MediumAccuracy: 65.65%Submissions: 49K+Points: 4
//  Given a Linked List Representation of Complete Binary Tree. Your task is to construct the Binary tree from the given linkedlist and return the root of the tree.
//  The result will be judged by printing the level order traversal of the Binary tree.
//  Note: The complete binary tree is represented as a linked list in a way where if the root node is stored at position i, its left, and right children are stored at position 2*i+1, and 2*i+2 respectively. H is the height of the tree and this space is used implicitly for the recursion stack.

// Examples:

// Input: list = 1->2->3->4->5
// Output: 1 2 3 4 5
// Explanation: The tree would look like
//       1
//     /   \
//    2     3
//  /  \
// 4   5
// Now, the level order traversal of
// the above tree is 1 2 3 4 5.
// Input: list = 5->4->3->2->1
// Output: 5 4 3 2 1
// Explanation: The tree would look like
//      5
//    /  \
//   4    3
//  / \
// 2   1
// Now, the level order traversal of
// the above tree is 5 4 3 2 1.
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(n).
// Constraints:
// 1 <= size(list) <= 105
// 1 <= node.data <= 105

class Solution
{
public:
    TreeNode *newtree(vector<int> &dat, int n, int idx)
    {
        if (idx >= n)
        {
            return NULL;
        }
        TreeNode *node = new TreeNode(dat[idx]);
        node->left = newtree(dat, n, 2 * idx + 1);
        node->right = newtree(dat, n, 2 * idx + 2);
        return node;
    }
    void convert(Node *head, TreeNode *&root)
    {
        Node *curr = head;
        vector<int> dat;
        while (curr != NULL)
        {
            dat.push_back(curr->data);
            curr = curr->next;
        }
        int n = dat.size();
        root = newtree(dat, n, 0);
    }
};

// //Leetcode POTD 1/7/2024

// Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.

// Example 1:

// Input: arr = [2,6,4,1]
// Output: false
// Explanation: There are no three consecutive odds.
// Example 2:

// Input: arr = [1,2,34,3,4,5,7,23,12]
// Output: true
// Explanation: [5,7,23] are three consecutive odds.

// Constraints:

// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        // int n=arr.size();
        // for(int i=2;i<n;i++){
        //     if(arr[i-2]%2==1 && arr[i-1]%2==1 && arr[i]%2==1){
        //         return true;
        //         break;
        //     }
        // }
        // return false;

        if (arr.size() == 1 || arr.size() == 2)
            return false;
        for (int i = 0; i < arr.size() - 2; i++)
        {
            if (arr[i] % 2 != 0)
            {
                if (arr[i + 1] % 2 != 0 && arr[i + 2] % 2 != 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};