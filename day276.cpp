-- -- -- -- -- -- -- -- -GFG - POTD - 29 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------



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