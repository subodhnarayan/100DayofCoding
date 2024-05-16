// Divisibility tree
// MediumAccuracy: 68.8%Submissions: 18K+Points: 4
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// Given a tree with n nodes where n is even. The tree is numbered from 1 to n, has n - 1 edges and is rooted at node 1. Your task is to eliminate the maximum number of edges resulting in a set of disjoint trees where the number of nodes in each tree is divisible by 2.

// Example 1:

// Input:
// n = 10
// edges = {{2,1},{3,1},{4,3},{5,2},{6,1},{7,2},{8,6},{9,8},{10,8}}
// Output:
// 2
// Explanation:
// Original tree:

// After removing edge 1-3 and 1-6, each remaining component consists of even number of nodes.

// Example 2:

// Input:
// n = 4
// edges = {{2,1},{4,2},{1,3}}
// Output:
// 1
// Explanation:
// After removing 2-1, each remaining component consists of even number of nodes.
// Your Task:
// You don't need to read or print anyhting. Your task is to complete the function minimumEdgeRemove() which takes n and edges as input parameters and returns the maximum number of edges that need to be removed from the given tree.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(n)

class Solution
{
public:
    int help(vector<int> adj[], vector<int> &vis, int &ans, int node)
    {
        vis[node] = 1;
        int size = 1;
        for (int x : adj[node])
        {
            if (!vis[x])
            {
                int temp = help(adj, vis, ans, x);
                size += temp;
                if (temp % 2 == 0)
                    ans++;
            }
        }
        return size;
    }

    int minimumEdgeRemove(int n, vector<vector<int>> edges)
    {
        vector<int> adj[n + 1];
        for (auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        vector<int> vis(n + 1, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                help(adj, vis, ans, i);
            }
        }

        return ans;
    }
};
