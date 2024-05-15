// Account Merge
// HardAccuracy: 53.56%Submissions: 27K+Points: 8
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// Given a list of accounts of size n where each element accounts [ i ] is a list of strings, where the first element account [ i ][ 0 ]  is a name, and the rest of the elements are emails representing emails of the account.
// Geek wants you to merge these accounts. Two accounts belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts have the same name.
// After merging the accounts, return the accounts in the following format: The first element of each account is the name, and the rest of the elements are emails in sorted order.

// Note: Accounts themselves can be returned in any order.

// Example 1:

// Input:
// n = 4
// accounts [ ] =
// [["John","johnsmith@mail.com","john_newyork@mail.com"],
// ["John","johnsmith@mail.com","john00@mail.com"],
// ["Mary","mary@mail.com"],
// ["John","johnnybravo@mail.com"]]
// Output:
// [["John","john00@mail.com","john_newyork@mail.com", "johnsmith@mail.com"],
// ["Mary","mary@mail.com"],
// ["John","johnnybravo@mail.com"]]
// Explanation:
// The first and second John's are the same person as they have the common email "johnsmith@mail.com". The third John and Mary are different people as none of their email addresses are used by other accounts.We could return these arrays in any order, for example, the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.



class DisjointSet
{
public:
    vector<int> rank, parent;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findUpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    void Unionbyrank(int u, int v)
    {
        int u_v = findUpar(u);
        int u_u = findUpar(v);
        if (u_v == u_u)
            return;
        if (rank[u_v] > rank[u_u])
            parent[u_u] = u_v;
        else if (rank[u_v] < rank[u_u])
            parent[u_v] = u_u;
        else
        {
            parent[u_v] = u_u;
            rank[u_u]++;
        }
    }
};
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        // code here
        int n = accounts.size();
        unordered_map<string, int> helper;
        DisjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (helper.find(mail) == helper.end())
                    helper[mail] = i;
                else
                    ds.Unionbyrank(i, helper[mail]);
            }
        }
        vector<vector<string>> ans;
        vector<string> merged[n];
        for (auto it : helper)
        {
            string mail = it.first;
            int node = ds.findUpar(it.second);
            merged[node].push_back(mail);
        }
        for (int i = 0; i < n; i++)
        {
            if (merged[i].size() == 0)
                continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : merged[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
