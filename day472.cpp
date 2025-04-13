-- -- -- -- -- -- -- -- -GFG - POTD - 13 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Clone an Undirected Graph
Difficulty: MediumAccuracy: 67.49%Submissions: 38K+Points: 4
Given a connected undirected graph represented by adjacency list, adjList[][] with n nodes, having a distinct label from 0 to n-1, where each adj[i] represents the list of vertices connected to vertex i.

Create a clone of the graph, where each node in the graph contains an integer val and an array (neighbors) of nodes, containing nodes that are adjacent to the current node.

class Node {
    val: integer
    neighbors: List[Node]
}
Your task is to complete the function cloneGraph( ) which takes a starting node of the graph as input and returns the copy of the given node as a reference to the cloned graph.

Note: If you return a correct copy of the given graph, then the driver code will print true; and if an incorrect copy is generated or when you return the original node, the driver code will print false.

Examples :

Input: n = 4, adjList[][] = [[1, 2], [0, 2], [0, 1, 3], [2]]
Output: true
Explanation: 

As the cloned graph is identical to the original one the driver code will print true.
Input: n = 3, adjList[][] = [[1, 2], [0], [0]]
Output: true
Explanation: 

As the cloned graph is identical to the original one the driver code will print true.
Constraints:
1 ≤ n ≤ 104
0 ≤ no. of edges ≤ 105
0 ≤ adjList[i][j] < n

Expected Complexities
Time Complexity: O(n + m)
Auxiliary Space: O(n)

class Solution {
    public:
        Node* solve(Node* node, unordered_map<int, Node*>& vis) {
          if (vis.count(node->val)) return vis[node->val];
          
          Node* newNode = new Node(node->val);
          vis[node->val] = newNode;
          
          for (Node* nbr: node->neighbors)
              newNode->neighbors.push_back( solve(nbr, vis) );
          
          return newNode;
      }
      Node* cloneGraph(Node* node) {
          // code here
          unordered_map<int, Node*> vis;
          return solve(node, vis);
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 13 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

1922. Count Good Numbers
Solved
Medium
Topics
Companies
Hint
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

 

Example 1:

Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
Example 2:

Input: n = 4
Output: 400
Example 3:

Input: n = 50
Output: 564908303
 

Constraints:

1 <= n <= 1015



class Solution {
    private:
        static constexpr int mod = 1000000007;
    
    public:
        int countGoodNumbers(long long n) {
            // use fast exponentiation to calculate x^y % mod
            auto quickmul = [](int x, long long y) -> int {
                int ret = 1, mul = x;
                while (y > 0) {
                    if (y % 2 == 1) {
                        ret = (long long)ret * mul % mod;
                    }
                    mul = (long long)mul * mul % mod;
                    y /= 2;
                }
                return ret;
            };
    
            return (long long)quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod;
        }
};