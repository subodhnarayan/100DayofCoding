-- -- -- -- -- -- -- -- -GFG - POTD - 29 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Implement Pow
Difficulty: MediumAccuracy: 52.79%Submissions: 23K+Points: 4
Implement the function power(b, e), which calculates b raised to the power of e (i.e. be).

Examples:

Input: b = 3.00000, e = 5
Output: 243.00000
Input: b = 0.55000, e = 3
Output: 0.16638
Input: b = -0.67000, e = -7
Output: -16.49971
Constraints:

-100.0 < b < 100.0
-109 <= e <= 109
Either b is not zero or e > 0.
-104 <= be <= 104

class Solution {
  public:
    double power(double b, int e) {
        // code here
        if(e==0)
            return 1;
        if(e==1)
            return b;
        if(e<0)
            return 1/power(b, -e);
            
        if(e%2==0)
            return power(b*b, e/2);
        return power(b, e-1)*b;
    }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 29 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


684. Redundant Connection
Solved
Medium
Topics
Companies
In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

 

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:


Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
 

Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected.

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         unordered_map<int, vector<int>> graph;

        auto isConnected = [&](int u, int v) {
            unordered_set<int> visited;
            stack<int> stack;
            stack.push(u);

            while (!stack.empty()) {
                int node = stack.top();
                stack.pop();

                if (visited.count(node)) continue;
                visited.insert(node);

                if (node == v) return true;

                for (int neighbor : graph[node]) {
                    stack.push(neighbor);
                }
            }
            return false;
        };

        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];

            if (graph.count(u) && graph.count(v) && isConnected(u, v)) {
                return edge;
            }

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return {};
    }
};