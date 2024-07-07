// GFG POTD 7/7/2024
//  Ancestors in Binary Tree
//  Difficulty: MediumAccuracy: 40.34%Submissions: 57K+Points: 4
//  Given a Binary Tree and an integer target. Find all the ancestors of the given target.

// Note:

// The ancestor of node x is node y, which is at the upper level of node x, and x is directly connected with node y. Consider multiple levels of ancestors to solve this problem.
// In case there are no ancestors available, return an empty list.
// Examples:

// Input:
//          1
//        /   \
//       2     3
//     /  \    /  \
//    4   5  6   8
//   /
//  7
// target = 7
// Output: [4 2 1]
// Explanation: The given target is 7, if we go above the level of node 7, then we find 4, 2 and 1. Hence the ancestors of node 7 are 4 2 and 1
// Input:
//         1
//       /   \
//      2     3
// target = 1
// Output: [ ]
// Explanation: Since 1 is the root node, there would be no ancestors. Hence we return an empty list.
// Expected Time Complexity: O(n).
// Expected Auxiliary Space: O(height of tree)

// Constraints:
// 1 ≤ no. of nodes ≤ 103
// 1 ≤ data of node ≤ 104

class Solution
{
public:
    // Function should return all the ancestor of the target node
    bool ances(Node *root, int target, vector<int> &an)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->data == target)
        {
            return true;
        }
        if (ances(root->left, target, an) || ances(root->right, target, an))
        {
            an.push_back(root->data);
            return true;
        }
        return false;
    }
    vector<int> Ancestors(struct Node *root, int target)
    {
        vector<int> pre;
        bool ch = ances(root, target, pre);
        return pre;
    }
};

// Leetcode 7/7/2024

// 1518. Water Bottles
// Solved
// Easy
// Topics
// Companies
// Hint
// There are numBottles water bottles that are initially full of water. You can exchange numExchange empty water bottles from the market with one full water bottle.

// The operation of drinking a full water bottle turns it into an empty bottle.

// Given the two integers numBottles and numExchange, return the maximum number of water bottles you can drink.

// Example 1:

// Input: numBottles = 9, numExchange = 3
// Output: 13
// Explanation: You can exchange 3 empty bottles to get 1 full water bottle.
// Number of water bottles you can drink: 9 + 3 + 1 = 13.
// Example 2:

// Input: numBottles = 15, numExchange = 4
// Output: 19
// Explanation: You can exchange 4 empty bottles to get 1 full water bottle.
// Number of water bottles you can drink: 15 + 3 + 1 = 19.

// Constraints:

// 1 <= numBottles <= 100
// 2 <= numExchange <= 100



class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // int nb=numBottles;
        // int ne=numExchange;
        // int ans=nb;
        // while(nb>=ne){
        //     int rem=nb%ne;
        //     int an=nb/ne;
        //     ans=ans+an;
        //     nb=rem+an;
        // }
        // return ans;
        //TC=O(log N)

        //Another Approach;
        return numBottles+(numBottles-1)/(numExchange-1);
    }
};