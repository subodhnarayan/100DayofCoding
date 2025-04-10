-- -- -- -- -- -- -- -- -GFG - POTD - 10 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Minimum cost to connect all houses in a city
Difficulty: MediumAccuracy: 66.31%Submissions: 12K+Points: 4
Given a 2D array houses[][], consisting of n 2D coordinates {x, y} where each coordinate represents the location of each house, the task is to find the minimum cost to connect all the houses of the city.

The cost of connecting two houses is the Manhattan Distance between the two points (xi, yi) and (xj, yj) i.e., |xi – xj| + |yi – yj|, where |p| denotes the absolute value of p.

Examples :

Input: n = 5 houses[][] = [[0, 7], [0, 9], [20, 7], [30, 7], [40, 70]]
Output: 105
Explanation:
Connect house 1 (0, 7) and house 2 (0, 9) with cost = 2
Connect house 1 (0, 7) and house 3 (20, 7) with cost = 20
Connect house 3 (20, 7) with house 4 (30, 7) with cost = 10 
At last, connect house 4 (30, 7) with house 5 (40, 70) with cost 73.
All the houses are connected now.
The overall minimum cost is 2 + 10 + 20 + 73 = 105.

Input: n = 4 houses[][] = [[0, 0], [1, 1], [1, 3], [3, 0]]
Output: 7
Explanation: 
Connect house 1 (0, 0) with house 2 (1, 1) with cost = 2
Connect house 2 (1, 1) with house 3 (1, 3) with cost = 2 
Connect house 1 (0, 0) with house 4 (3, 0) with cost = 3 
The overall minimum cost is 3 + 2 + 2 = 7.
Constraint:
1 ≤ n ≤ 103
0 ≤ houses[i][j] ≤ 103

class Solution {
    public:
      int minCost(vector<vector<int>>& houses) {
          // code here
            // code here
          int n = houses.size();
          
          priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
          
          vector<int> vis(n, 0);
          pq.push({0, 0});
          int sum =0; 
          
          while(!pq.empty()){
              auto node = pq.top();
              pq.pop();
              int wt = node.first;
              int ind = node.second;
              if (vis[ind]) continue;
      
              vis[ind] = 1;
              sum += wt;
      
              for (int i = 0; i < n; i++) {
                  if (!vis[i]) {
                      int newWt = abs(houses[ind][0] - houses[i][0]) + abs(houses[ind][1] - houses[i][1]);
                      pq.push({newWt, i});
                  }
              }
          }
          
          return sum;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 10 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------






