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

Nth Fibonacci Number
Matrix Partners India: Exclusive Job-A-Thon | Apply to 15+ Companies via 1 Hiring Challenge | 
Contest LIVE right now!banner Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.
Note: for the reference of this question take first fibonacci number to be 1.

class Solution
{
public:
    int nthFibonacci(int n)
    {
        if (n == 1 || n == 2)
        {
            return 1;
        }
        int a = 1;
        int b = 2;
        int sum = 0;
        int mod = 1e9 + 7;
        for (int i = 3; i < n; i++)
        {
            sum = (a + b) % mod;
            a = b;
            b = sum;
        }
        return sum;
    }
};