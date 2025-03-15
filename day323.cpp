-- -- -- -- -- -- -- -- -GFG - POTD - 15 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
Coin Change (Minimum Coins)
Difficulty: MediumAccuracy: 26.74%Submissions: 242K+Points: 4
You are given an array coins[], where each element represents a coin of a different denomination, and a target value sum. You have an unlimited supply of each coin type {coins1, coins2, ..., coinsm}.

Your task is to determine the minimum number of coins needed to obtain the target sum. If it is not possible to form the sum using the given coins, return -1.

Examples:

Input: coins[] = [25, 10, 5], sum = 30
Output: 2
Explanation: Minimum 2 coins needed, 25 and 5  
Input: coins[] = [9, 6, 5, 1], sum = 19
Output: 3
Explanation: 19 = 9 + 9 + 1
Input: coins[] = [5, 1], sum = 0
Output: 0
Explanation: For 0 sum, we do not need a coin
Input: coins[] = [4, 6, 2], sum = 5
Output: -1
Explanation: Not possible to make the given sum.
 
Constraints:
1 ≤ sum * coins.size() ≤ 106
0 <= sum <= 104
1 <= coins[i] <= 104
1 <= coins.size() <= 103

Time Complexity: O(coins.size * sum)Auxiliary Space: O(sum)

class Solution {
    public:
      int minCoins(vector<int> &coins, int V) {
          // code here
           int table[V + 1];
           int m=coins.size();
   
      // Base case (If given value V is 0)
      table[0] = 0;
   
      // Initialize all table values as Infinite
      for (int i = 1; i <= V; i++)
          table[i] = INT_MAX;
   
      // Compute minimum coins required for all
      // values from 1 to V
      for (int i = 1; i <= V; i++) {
          // Go through all coins smaller than i
          for (int j = 0; j < m; j++)
              if (coins[j] <= i) {
                  int sub_res = table[i - coins[j]];
                  if (sub_res != INT_MAX
                      && sub_res + 1 < table[i])
                      table[i] = sub_res + 1;
              }
      }
   
      if (table[V] == INT_MAX)
          return -1;
   
      return table[V];
      }
  };
-- -- -- -- -- -- -- -- -LeetCode - POTD - 15 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
