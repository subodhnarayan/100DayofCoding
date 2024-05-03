// GFG Questions
// K distance from root

// Given a binary tree having n nodes and an integer k.
// Print all nodes that are at distance k from the root (root is considered at
// distance 0 from itself). Nodes should be printed from left to right.

class Solution
{
public:
    void solve(Node *root, int k, int dist, vector<int> &ans)
    {
        if (root == NULL || k < dist)
        {
            return;
        }
        else if (k == dist)
        {
            ans.push_back(root->data);
        }
        solve(root->left, k, dist + 1, ans);
        solve(root->right, k, dist + 1, ans);
    }
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
        vector<int> ans;
        solve(root, k, 0, ans);
        return ans;
    }
};