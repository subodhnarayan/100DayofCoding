- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 20 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Shortest path in Undirected Graph
Difficulty: MediumAccuracy: 49.98%Submissions: 93K+Points: 4
You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Examples :

Input:
n = 9, m = 10
edges=[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4

Input:
n = 4, m = 2
edges=[[1,3],[3,0]] 
src=3
Output:
1 1 -1 0

Constraint:
1<=n,m<=104
0<=edges[i][j]<=n-1

Expected Time Complexity: O(N + E), where N is the number of nodes and E is the edges
Expected Space Complexity: O(N)

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
     vector<int> ans(N, -1);
        vector< vector<pair<int, int>> > adj(N);
        
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }
  
        vector<int> vis(N, 0);
        vis[src]=1;
        ans[src]=0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        while(!q.empty()){
            
            int node = q.front().first;
            int len = q.front().second;
            q.pop();
            
            for(auto it : adj[node]){
                if(!vis[it.first]){
                    vis[it.first] = 1;
                    ans[it.first] = len+1;
                    q.push({it.first, len+1});
                }
                else{
                    ans[it.first] = min(ans[it.first] , len+1);
                }
            }
        }
        return ans; 
    }
};
