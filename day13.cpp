// Number of Good Components
// MediumAccuracy: 60.81%Submissions: 34K+Points: 4
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// Given an undirected graph with v vertices(numbered from 1 to v) and e edges. Find the number of good components in the graph.
// A component of the graph is good if and only if the component is fully connected.
// Note: A fully connected component is a subgraph of a given graph such that there's an edge between every pair of
// vertices in the component, the given graph can be a disconnected graph.

// Example 1:

// Input:

// e=3
// v=3
// edges={{1, 2},{1, 3},{3, 2}}
// Output:
// 1
// Explanation:
// We can see that there is only one component in the graph and in this component there is a edge between any two vertces.
// Example 2:

// Input:

// e=5
// v=7
// edges={{1, 2},{7, 2},{3, 5},{3, 4},{4, 5}}
// Output:
// 2
// Explanation:
// We can see that there are 3 components in the graph. For 1-2-7 there is no edge between 1 to 7, so it is
// not a fully connected component. Rest 2 are individually fully connected component.

class Solution
{
public:
    void check(int i, vector<int> &vis, vector<vector<int>> &adj, int &e, int &n)
    {
        vis[i] = 1;
        e += adj[i].size();
        n += 1;
        for (auto &it : adj[i])
        {
            if (!vis[it])
            {
                check(it, vis, adj, e, n);
            }
        }
        return;
    }
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges)
    {
        int ans = 0;
        vector<int> vis(v + 1, 0);
        vector<vector<int>> adj(v + 1, vector<int>(0, 0));
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for (int i = 1; i <= v; i++)
        {
            if (!vis[i])
            {
                int n = 0, e = 0;
                check(i, vis, adj, e, n);
                if (e / 2 == (n * (n - 1)) / 2)
                    ans += 1;
            }
        }
        return ans;
    }
};
