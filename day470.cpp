-- -- -- -- -- -- -- -- -GFG - POTD - 11 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Dijkstra Algorithm
Difficulty: MediumAccuracy: 50.83%Submissions: 218K+Points: 4Average Time: 25m
Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w edge weight.
You have to find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.

Note: The Graph is connected and doesn't contain any negative weight edge.

Examples:

Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
Output: [4, 3, 0]
Explanation:

Shortest Paths:
For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
For 2 to 1 minimum distance will be 3. By following path 2 -> 1
For 2 to 2 minimum distance will be 0. By following path 2 -> 2
Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
Output: [0, 4, 8, 10, 10]
Explanation: 

Shortest Paths: 
For 0 to 1 minimum distance will be 4. By following path 0 -> 1
For 0 to 2 minimum distance will be 8. By following path 0 -> 2
For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3 
For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4
Constraints:
1 ≤ V ≤ 105
1 ≤ E = edges.size() ≤ 105
0 ≤ edges[i][j] ≤ 104
0 ≤ src < V
Expected Complexities
Time Complexity: O((V + E) log V)
Auxiliary Space: O(V)



class Solution {
    public:
      vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
          // Code here
          vector<vector<pair<int,int>>>v(V);
          for(auto &x:edges){
              v[x[0]].push_back({x[2],x[1]});
              v[x[1]].push_back({x[2],x[0]});
          }
          vector<int>ans(V,INT_MAX);
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
          pq.push({0,src});
          ans[src]=0;
          while(!pq.empty()){
              auto x=pq.top();
              int i=x.second;
              int d=x.first;
              pq.pop();
              for(auto &y:v[i]){
                  if(ans[y.second]>y.first+d){
                      ans[y.second]=y.first+d;
                      pq.push({ans[y.second],y.second});
                  }
              }
          }
          return ans;
      }
  };
  


-- -- -- -- -- -- -- -- -LeetCode - POTD - 11 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


2843. Count Symmetric Integers
Solved
Easy
Topics
Companies
Hint
You are given two positive integers low and high.

An integer x consisting of 2 * n digits is symmetric if the sum of the first n digits of x is equal to the sum of the last n digits of x. Numbers with an odd number of digits are never symmetric.

Return the number of symmetric integers in the range [low, high].

 

Example 1:

Input: low = 1, high = 100
Output: 9
Explanation: There are 9 symmetric integers between 1 and 100: 11, 22, 33, 44, 55, 66, 77, 88, and 99.
Example 2:

Input: low = 1200, high = 1230
Output: 4
Explanation: There are 4 symmetric integers between 1200 and 1230: 1203, 1212, 1221, and 1230.
 

Constraints:

1 <= low <= high <= 104




class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
             int res = 0;
            for (int a = low; a <= high; ++a) {
                if (a < 100 && a % 11 == 0) {
                    res++;
                } else if (1000 <= a && a < 10000) {
                    int left = a / 1000 + (a % 1000) / 100;
                    int right = (a % 100) / 10 + a % 10;
                    if (left == right) {
                        res++;
                    }
                }
            }
            return res;
        }
    };
    
    