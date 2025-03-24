-- -- -- -- -- -- -- -- -GFG - POTD - 23 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Total Decoding Messages
Difficulty: MediumAccuracy: 15.79%Submissions: 147K+Points: 4Average Time: 20m
A message containing letters A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

You are given a string digits. You have to determine the total number of ways that message can be decoded.

Examples:

Input: digits = "123"
Output: 3
Explanation: "123" can be decoded as "ABC"(1, 2, 3), "LC"(12, 3) and "AW"(1, 23).
Input: digits = "90"
Output: 0
Explanation: "90" cannot be decoded, as it's an invalid string and we cannot decode '0'.
Input: digits = "05"
Output: 0
Explanation: "05" cannot be mapped to "E" because of the leading zero ("5" is different from "05"), the string is not a valid encoding message.
Constraints:
1 ≤ digits.size() ≤ 103

class Solution {
    public:
      int mod=1e9+7;
      int func(string &str,int n,vector<int> &dp){
          if(n==0 || n==1) return 1;
          if(dp[n]!=-1) return dp[n];
          int cnt=0;
          if(str[n-1] >= '1') cnt = cnt + func(str,n-1,dp)%mod;
          if(str[n-2]== '1' || str[n-2]== '2' && str[n-1] <='6') cnt=(cnt+func(str,n-2,dp)%mod)%mod;
          return dp[n]=cnt%mod;
         
      }
      int countWays(string &str) {
          
          int n=str.size();
          if(str[0]=='0') return 0;
          vector<int> dp(n+1,-1);
          
          return func(str,n,dp);
      }
  };



-- -- -- -- -- -- -- -- -LeetCode - POTD - 23 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


1976. Number of Ways to Arrive at Destination
Medium
Topics
Companies
Hint
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:


Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
Output: 4
Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
The four ways to get there in 7 minutes are:
- 0 ➝ 6
- 0 ➝ 4 ➝ 6
- 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
- 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
Example 2:

Input: n = 2, roads = [[1,0,10]]
Output: 1
Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.
 

Constraints:

1 <= n <= 200
n - 1 <= roads.length <= n * (n - 1) / 2
roads[i].length == 3
0 <= ui, vi <= n - 1
1 <= timei <= 109
ui != vi
There is at most one road connecting any two intersections.
You can reach any intersection from any other intersection.

class Solution {
    public:
        int countPaths(int n, vector<vector<int>>& roads) {
            vector<vector<pair<int, int>>> graph(n);
            for (const auto& road : roads) {
                int u = road[0], v = road[1], time = road[2];
                graph[u].emplace_back(v, time);
                graph[v].emplace_back(u, time);
            }
    
            vector<long long> dist(n, LLONG_MAX);
            vector<int> ways(n, 0);
    
            dist[0] = 0;
            ways[0] = 1;
    
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            pq.emplace(0, 0);
    
            const int MOD = 1e9 + 7;
    
            while (!pq.empty()) {
                auto [d, node] = pq.top();
                pq.pop();
    
                if (d > dist[node]) continue;
    
                for (const auto& [neighbor, time] : graph[node]) {
                    if (dist[node] + time < dist[neighbor]) {
                        dist[neighbor] = dist[node] + time;
                        ways[neighbor] = ways[node];
                        pq.emplace(dist[neighbor], neighbor);
                    } else if (dist[node] + time == dist[neighbor]) {
                        ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                    }
                }
            }
    
            return ways[n - 1];
        }
};

