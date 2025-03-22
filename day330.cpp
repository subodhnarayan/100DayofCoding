-- -- -- -- -- -- -- -- -GFG - POTD - 22 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Stickler Thief II
Difficulty: MediumAccuracy: 52.99%Submissions: 13K+Points: 4Average Time: 30m
You are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.
Determine the maximum amount the thief can steal.

Note: Since the houses are in a circle, the first and last houses are also considered adjacent.

Examples:

Input: arr[] = [2, 3, 2]
Output: 3
Explanation: arr[0] and arr[2] can't be robbed because they are adjacent houses. Thus, 3 is the maximum value thief can rob.
Input: arr[] = [1, 2, 3, 1]
Output: 4
Explanation: Maximum stolen value: arr[0] + arr[2] = 1 + 3 = 4
Input: arr[] = [2, 2, 3, 1, 2]
Output: 5
Explanation: Maximum stolen value: arr[0] + arr[2] = 2 + 3 = 5 or arr[2] + arr[4] = 3 + 2 = 5
Constraints:
2 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 104

class Solution {
  public:
   int solve(int idx, vector<int>& arr){
        int n = arr.size();
        int prev2 = 0, prev1 = arr[idx];
        
        for(int i = idx+1; i < n; ++i){
            int curr = max(arr[i]+prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int includeLastHouse = solve(1, arr);
        arr.pop_back();
        int includeFirstHouse = solve(0, arr);
        return max(includeFirstHouse, includeLastHouse);
    }
};




-- -- -- -- -- -- -- -- -LeetCode - POTD - 22 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

2685. Count the Number of Complete Components
Medium
Topics
Companies
Hint
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

 

Example 1:



Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
Output: 3
Explanation: From the picture above, one can see that all of the components of this graph are complete.
Example 2:



Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
Output: 1
Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
 

Constraints:

1 <= n <= 50
0 <= edges.length <= n * (n - 1) / 2
edges[i].length == 2
0 <= ai, bi <= n - 1
ai != bi
There are no repeated edges.

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
         vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        
        auto unionSets = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) return;
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        };
        
        for (auto& edge : edges) {
            unionSets(edge[0], edge[1]);
        }
        
        unordered_map<int, unordered_set<int>> componentVertices;
        unordered_map<int, int> componentEdges;
        
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            componentVertices[root].insert(i);
        }
        
        for (auto& edge : edges) {
            int root = find(edge[0]);
            componentEdges[root]++;
        }
        
        int completeCount = 0;
        for (auto& [root, vertices] : componentVertices) {
            int numVertices = vertices.size();
            int expectedEdges = numVertices * (numVertices - 1) / 2;
            if (componentEdges[root] == expectedEdges) {
                completeCount++;
            }
        }
        
        return completeCount;
    }
};
