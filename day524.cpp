-- -- -- -- -- -- -- -- -GFG - POTD - 05 / 06 / 2025 ----------------------------------------

Count the paths
Difficulty: MediumAccuracy: 42.71%Submissions: 46K+Points: 4Average Time: 10m
Given a Directed Acyclic Graph (DAG) with V nodes labeled from 0 to V-1, and a list of directed edges, count the total number of distinct paths from a given start node to a destination node. Each edge is represented as edges[i] = [u, v], indicating a directed edge from u to v.

Examples :

Input: edges[][] = [[0,1], [0,3], [2,0], [2,1], [1,3]], V = 4, src = 2, dest = 3
Output: 3
Explanation: There are three ways to reach at 3 from 2. These are: 2 -> 1 -> 3, 2 -> 0 -> 3 and 2 -> 0 -> 1 -> 3.
Print-all-paths-1
Input: edges[][] = [[0,1], [1,2], [1,3], [2,3]], V = 4, src = 0, dest = 3
Output: 2
Explanation: There is two way to reach at 3 from 0 that is : 0 -> 1 -> 2 -> 3 and 0 -> 1 -> 3.
Print-all-paths-2
Constraints:
2  ≤  V  ≤  103
1  ≤   E = edges.size()  ≤  (V * (V - 1)) / 2

Expected Complexities
Time Complexity: O(V + E)
Auxiliary Space: O(V + E)


class Solution {
  public:
     int dfs(int node,int dest,vector<vector<int>>&adj,vector<int>&dp){
        if(node==dest){
            // successfull path
            return 1;
        }
        if(dp[node]!=-1){
            // if 2 comes after i have already calculated all its path
            return dp[node];
        }
        int ans=0;
        for(auto it:adj[node]){
            // if i am 2 i will explore all path
            ans+=dfs(it,dest,adj,dp);
        }
        return dp[node]=ans;
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<int>dp(V,-1);
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        return dfs(src,dest,adj,dp);
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 05 / 06 / 2025 ----------------------------------------


