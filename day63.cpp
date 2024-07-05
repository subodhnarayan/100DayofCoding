// GFG POTD 5/7/2024
//  Vertical Width of a Binary Tree
//  Difficulty: MediumAccuracy: 43.48%Submissions: 52K+Points: 4
//  Given a Binary Tree. You need to find and return the vertical width of the tree.

// Examples :

// Input:
//          1
//        /    \
//       2      3
//      / \    /  \
//     4   5  6   7
//             \   \
//              8   9
// Output: 6
// Explanation: The width of a binary tree is
// the number of vertical paths in that tree.

// The above tree contains 6 vertical lines.
// Input:
//      1
//     /  \
//    2    3
// Output: 3
// Explanation: The above tree has 3 vertical lines, hence the answer is 3.
// Expected Time Complexity: O(nlogn)
// Expected Auxiliary Space: O(height of the tree).

// Constraints:
// 0 <= number of nodes <= 104

// class Solution {
//   public:
//     // Function to find the vertical width of a Binary Tree.
//    void f(Node *root,int curr,int &leftMax,int &rightMax){
//         if(!root)
//             return;
//         leftMax=max(curr,leftMax);
//         rightMax=min(curr,rightMax);
//         f(root->left,curr+1,leftMax,rightMax);
//         f(root->right,curr-1,leftMax,rightMax);
//     }
//     int verticalWidth(Node* root) {
//          if(!root)
//             return 0;
//         int leftMax=0,rightMax=0,curr=0;
//         f(root,curr,leftMax,rightMax);

//         return leftMax+abs(rightMax)+1;
//     }
// };

// Leetcode POTD 5/7/2024

// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// Solved
// Medium
// Topics
// Companies
// Hint
// A critical point in a linked list is defined as either a local maxima or a local minima.

// A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

// A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

// Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

// Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].

// Example 1:

// Input: head = [3,1]
// Output: [-1,-1]
// Explanation: There are no critical points in [3,1].
// Example 2:

// Input: head = [5,3,1,2,5,1,2]
// Output: [1,3]
// Explanation: There are three critical points:
// - [5,3,1,2,5,1,2]: The third node is a local minima because 1 is less than 3 and 2.
// - [5,3,1,2,5,1,2]: The fifth node is a local maxima because 5 is greater than 2 and 1.
// - [5,3,1,2,5,1,2]: The sixth node is a local minima because 1 is less than 5 and 2.
// The minimum distance is between the fifth and the sixth node. minDistance = 6 - 5 = 1.
// The maximum distance is between the third and the sixth node. maxDistance = 6 - 3 = 3.
// Example 3:

// Input: head = [1,3,2,2,3,2,2,2,7]
// Output: [3,3]
// Explanation: There are two critical points:
// - [1,3,2,2,3,2,2,2,7]: The second node is a local maxima because 3 is greater than 1 and 2.
// - [1,3,2,2,3,2,2,2,7]: The fifth node is a local maxima because 3 is greater than 2 and 2.
// Both the minimum and maximum distances are between the second and the fifth node.
// Thus, minDistance and maxDistance is 5 - 2 = 3.
// Note that the last node is not considered a local maxima because it does not have a next node.

// Constraints:

// The number of nodes in the list is in the range [2, 105].
// 1 <= Node.val <= 105

class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> criticalPoints;
        ListNode *prev = nullptr;
        ListNode *curr = head;
        int position = 0;

        while (curr != nullptr && curr->next != nullptr)
        {
            if (prev != nullptr && curr->next != nullptr)
            {
                if ((curr->val > prev->val && curr->val > curr->next->val) ||
                    (curr->val < prev->val && curr->val < curr->next->val))
                {
                    criticalPoints.push_back(position);
                }
            }
            prev = curr;
            curr = curr->next;
            position++;
        }

        if (criticalPoints.size() < 2)
        {
            return {-1, -1};
        }

        int minDistance = INT_MAX;
        int maxDistance = criticalPoints.back() - criticalPoints.front();

        for (int i = 1; i < criticalPoints.size(); i++)
        {
            minDistance = min(minDistance, criticalPoints[i] - criticalPoints[i - 1]);
        }

        return {minDistance, maxDistance};
    }
};