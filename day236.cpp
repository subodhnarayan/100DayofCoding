-- -- -- -- -- -- -- -- -GFG - POTD - 21 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Rotate by 90 degree
Difficulty: EasyAccuracy: 56.88%Submissions: 99K+Points: 2
Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 

Examples:

Input: mat[][] = [[1, 2, 3],
                [4, 5, 6]
                [7, 8, 9]]
Output: Rotated Matrix:
[3, 6, 9]
[2, 5, 8]
[1, 4, 7]
Input: mat[][] = [[1, 2],
                [3, 4]]
Output: Rotated Matrix:
[2, 4]
[1, 3]
Constraints:
1 ≤ n ≤ 102
0 <= mat[i][j] <= 103

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& arr) {
        int n=arr.size();
       for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(arr[i][j],arr[j][i]);
            }
        }
    for(int i=0;i<n;i++)
    {
        int start=0;
        int end=n-1;
        while(start<end)
        {
            swap(arr[start][i],arr[end][i]);
            start++;
            end--;
        }
    }
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 21 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

2872. Maximum Number of K-Divisible Components
Solved
Hard
Topics
Companies
Hint
There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.

A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.

Return the maximum number of components in any valid split.

 

Example 1:


Input: n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6
Output: 2
Explanation: We remove the edge connecting node 1 with 2. The resulting split is valid because:
- The value of the component containing nodes 1 and 3 is values[1] + values[3] = 12.
- The value of the component containing nodes 0, 2, and 4 is values[0] + values[2] + values[4] = 6.
It can be shown that no other valid split has more than 2 connected components.
Example 2:


Input: n = 7, edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [3,0,6,1,5,2,1], k = 3
Output: 3
Explanation: We remove the edge connecting node 0 with 2, and the edge connecting node 0 with 1. The resulting split is valid because:
- The value of the component containing node 0 is values[0] = 3.
- The value of the component containing nodes 2, 5, and 6 is values[2] + values[5] + values[6] = 9.
- The value of the component containing nodes 1, 3, and 4 is values[1] + values[3] + values[4] = 6.
It can be shown that no other valid split has more than 3 connected components.
 

Constraints:

1 <= n <= 3 * 104
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
values.length == n
0 <= values[i] <= 109
1 <= k <= 109
Sum of values is divisible by k.
The input is generated such that edges represents a valid tree.

class Solution {
public:
int count;
     int dfs(int curr, int prev, vector<vector<int>>& adj, vector<int>& values, int k) {
        int sum = 0; // Initialize sum of the current subtree

        // Iterate over all adjacent nodes
        for (int v : adj[curr]) {
            if (v == prev) continue; // Skip the parent node
            sum += dfs(v, curr, adj, values, k); // Process the subtree rooted at v
        }

        sum += values[curr]; // Add current node's value
        sum %= k; // Reduce the sum modulo k

        if (sum == 0) {
            count++; // Increment the count for k-divisible components
        }

        return sum; // Return the sum of the subtree
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
          vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        count = 0; // Initialize count to 0
        dfs(0, -1, adj, values, k); // Start DFS from node 0
        return count;
    }
};

