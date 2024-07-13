//GFG POTD 13/7/2024
// Shortest Path in Weighted undirected graph
// Difficulty: MediumAccuracy: 50.0%Submissions: 45K+Points: 4
// You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

// The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

// Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1. 

// Examples :

// Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
// Output: 5
// Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 
// Input: n = 2, m= 1, edges = [[1, 2, 2]]
// Output: 2
// Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2. 
// Input: n = 2, m= 0, edges = [ ]
// Output: -1
// Explanation: Since there are no edges, so no answer is possible.
// Expected Time Complexity: O(m* log(n))
// Expected Space Complexity: O(n+m)

// Constraint:
// 2 <= n <= 106
// 0 <= m <= 106
// 1 <= a, b <= n
// 1 <= w <= 105

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
          vector<pair<int,int>> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> par(n+1,-1);
        vector<int> dist(n+1,INT_MAX);
        dist[1]=0;
        pq.push({0,{1,-1}});
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second.first;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int edW=it.second;
                if(wt+edW<dist[adjnode]){
                    dist[adjnode]=wt+edW;
                    par[adjnode]=node;
                    pq.push({dist[adjnode],{adjnode,node}});
                }
            }
        }
        
        int cost=dist[n];
        if(cost==INT_MAX){
            return {-1};
        }
        vector<int> ans;
        for (int v=n;v!=-1;v=par[v]) {
            ans.push_back(v);
        }
        ans.push_back(cost);
        reverse(ans.begin(),ans.end());
        return ans;
    }

