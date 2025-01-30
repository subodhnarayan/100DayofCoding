-- -- -- -- -- -- -- -- -GFG - POTD - 29 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
N-Queen Problem
Difficulty: HardAccuracy: 35.43%Submissions: 99K+Points: 8
The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

Given an integer n, find all distinct solutions to the n-queens puzzle.
You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.
For eg. below figure represents a chessboard [3 1 4 2].



Examples:

Input: n = 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.
Input: n = 4
Output: [[2 4 1 3 ] [3 1 4 2 ]]
Explaination: There are 2 possible solutions for n = 4.
Input: n = 2
Output: []
Explaination: There are no possible solutions for n = 2.
Constraints:
1 ≤ n ≤ 10

Time Complexity: O(n!)Auxiliary Space: O(n^2)


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool issafe(int row,int col,vector<vector<int>> &board,int n){
        int crow=row;
        int ccol=col;
        
        while(row>=0 && col>=0){
            if(board[row][col]==1) return false;
            row--;
            col--;
        }
        
        row=crow;
        col=ccol;
        while(col>=0){
            if(board[row][col]==1) return false;
            col--;
        }
        
    
        row=crow;
        col=ccol;
        
         while(row<n && col>=0){
            if(board[row][col]==1) return false;
            row++;
            col--;
        }
        
        return true;
        
    }
    
    void soln(int col,vector<vector<int>> &board, vector<vector<int>> &ans,int n){
        if(col==n){
            vector<int> res;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]==1){
                        res.push_back(j+1);
                    }
                }
            }
            ans.push_back(res);
            return;
        }
        
        for(int row=0;row<n;row++){
         if(issafe(row,col,board,n)){
             board[row][col]=1;
             soln(col+1,board,ans,n);
             board[row][col]=0;
         }
            
        }
    }
  
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<std::vector<int>> board(n, std::vector<int>(n, 0));
        soln(0,board,ans,n);
        sort(ans.begin(),ans.end());
        return ans;
       // getsoln(0,chesbod,ans,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends

-- -- -- -- -- -- -- -- -LeetCode - POTD - 29 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


2493. Divide Nodes Into the Maximum Number of Groups
Solved
Hard
Topics
Companies
Hint
You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.

You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.

Divide the nodes of the graph into m groups (1-indexed) such that:

Each node in the graph belongs to exactly one group.
For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.

 

Example 1:


Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
Output: 4
Explanation: As shown in the image we:
- Add node 5 to the first group.
- Add node 1 to the second group.
- Add nodes 2 and 4 to the third group.
- Add nodes 3 and 6 to the fourth group.
We can see that every edge is satisfied.
It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.
Example 2:

Input: n = 3, edges = [[1,2],[2,3],[3,1]]
Output: -1
Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
It can be shown that no grouping is possible.
 

Constraints:

1 <= n <= 500
1 <= edges.length <= 104
edges[i].length == 2
1 <= ai, bi <= n
ai != bi
There is at most one edge between any pair of vertices.

class Solution {
public:
    vector<int> color; // Tracks bipartition colors (0/1)
    vector<vector<int>> adj; // Adjacency list
    int n; // Number of nodes

    // DFS to check bipartiteness and collect component nodes
    bool isBipartite(int node, int c, vector<int>& component) {
        color[node] = c;
        component.push_back(node);
        for (int nbr : adj[node]) {
            if (color[nbr] == c) return false; // Odd cycle detected
            if (color[nbr] == -1 && !isBipartite(nbr, 1 - c, component)) 
                return false;
        }
        return true;
    }

    // BFS to compute max depth (groups) for a component
    int maxGroupsInComponent(const vector<int>& component) {
        int maxDepth = 0;
        for (int start : component) {
            vector<int> depth(n, -1);
            queue<int> q;
            q.push(start);
            depth[start] = 0;
            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int nbr : adj[node]) {
                    if (depth[nbr] == -1) {
                        depth[nbr] = depth[node] + 1;
                        maxDepth = max(maxDepth, depth[nbr]);
                        q.push(nbr);
                    }
                }
            }
        }
        return maxDepth + 1; // Depth to groups conversion
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        this->n = n;
        color.assign(n, -1);
        adj.resize(n);
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> components;
        for (int i = 0; i < n; ++i) {
            if (color[i] == -1) {
                components.emplace_back();
                if (!isBipartite(i, 0, components.back())) 
                    return -1; // Non-bipartite component
            }
        }

        int total = 0;
        for (auto& comp : components) 
            total += maxGroupsInComponent(comp);
        
        return total;
    }
};