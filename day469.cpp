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

2999. Count the Number of Powerful Integers
Solved
Hard
Topics
Companies
Hint
You are given three integers start, finish, and limit. You are also given a 0-indexed string s representing a positive integer.

A positive integer x is called powerful if it ends with s (in other words, s is a suffix of x) and each digit in x is at most limit.

Return the total number of powerful integers in the range [start..finish].

A string x is a suffix of a string y if and only if x is a substring of y that starts from some index (including 0) in y and extends to the index y.length - 1. For example, 25 is a suffix of 5125 whereas 512 is not.

 

Example 1:

Input: start = 1, finish = 6000, limit = 4, s = "124"
Output: 5
Explanation: The powerful integers in the range [1..6000] are 124, 1124, 2124, 3124, and, 4124. All these integers have each digit <= 4, and "124" as a suffix. Note that 5124 is not a powerful integer because the first digit is 5 which is greater than 4.
It can be shown that there are only 5 powerful integers in this range.
Example 2:

Input: start = 15, finish = 215, limit = 6, s = "10"
Output: 2
Explanation: The powerful integers in the range [15..215] are 110 and 210. All these integers have each digit <= 6, and "10" as a suffix.
It can be shown that there are only 2 powerful integers in this range.
Example 3:

Input: start = 1000, finish = 2000, limit = 4, s = "3000"
Output: 0
Explanation: All integers in the range [1000..2000] are smaller than 3000, hence "3000" cannot be a suffix of any integer in this range.
 

Constraints:

1 <= start <= finish <= 1015
1 <= limit <= 9
1 <= s.length <= floor(log10(finish)) + 1
s only consists of numeric digits which are at most limit.
s does not have leading zeros


class Solution {
    public:
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            string low = to_string(start);
            string high = to_string(finish);
            int n = high.size();
            low = string(n - low.size(), '0') + low;  // align digits
            int pre_len = n - s.size();               // prefix length
    
            vector<long long> memo(n, -1);
            function<long long(int, bool, bool)> dfs =
                [&](int i, bool limit_low, bool limit_high) -> long long {
                // recursive boundary
                if (i == low.size()) {
                    return 1;
                }
    
                if (!limit_low && !limit_high && memo[i] != -1) {
                    return memo[i];
                }
    
                int lo = limit_low ? low[i] - '0' : 0;
                int hi = limit_high ? high[i] - '0' : 9;
    
                long long res = 0;
                if (i < pre_len) {
                    for (int digit = lo; digit <= min(hi, limit); digit++) {
                        res += dfs(i + 1, limit_low && digit == lo,
                                   limit_high && digit == hi);
                    }
                } else {
                    int x = s[i - pre_len] - '0';
                    if (lo <= x && x <= min(hi, limit)) {
                        res =
                            dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
                    }
                }
    
                if (!limit_low && !limit_high) {
                    memo[i] = res;
                }
                return res;
            };
            return dfs(0, true, true);
        }
    };




