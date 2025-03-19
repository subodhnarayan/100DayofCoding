-- -- -- -- -- -- -- -- -GFG - POTD - 19 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Stock Buy and Sell – Max K Transactions Allowed
Difficulty: HardAccuracy: 48.35%Submissions: 51K+Points: 8
In the stock market, a person buys a stock and sells it on some future date. You are given an array prices[] representing stock prices on different days and a positive integer k, find out the maximum profit a person can make in at-most k transactions.

A transaction consists of buying and subsequently selling a stock and new transaction can start only when the previous transaction has been completed.

Examples :

Input: prices[] = [10, 22, 5, 80], k = 2
Output: 87
Explaination:
1st transaction: Buy at 10 and sell at 22. 
2nd transaction : Buy at 5 and sell at 80.
Total Profit will be 12 + 75 = 87.
Input: prices[] = [20, 580, 420, 900], k = 3
Output: 1040
Explaination: 
1st transaction: Buy at 20 and sell at 580. 
2nd transaction : Buy at 420 and sell at 900.
Total Profit will be 560 + 480 = 1040.
Input: prices[] = [100, 90, 80, 50, 25],  k = 1
Output: 0
Explaination: Selling price is decreasing continuously
leading to loss. So seller cannot have any profit.
Constraints:
1 ≤ prices.size() ≤ 103
1 ≤ k ≤ 200
1 ≤ prices[i] ≤ 103


class Solution {
    public:
      int maxProfit(vector<int>& prices, int k) {
          // code here
          int n=(int)prices.size();
          
          vector<vector<int>>dp_prev(3,vector<int>(k+1,0));
  
          for(int i=0;i<=k;i++)
          {
              dp_prev[1][i]=-(int)(1e9);
          }
          for(int i=n-1;i>=0;i--)
          {
             vector<vector<int>>dp_curr(3,vector<int>(k+1,0));
              for(int j=k-1;j>=0;j--)
              {
                  dp_curr[0][j]=max({dp_curr[0][1],dp_prev[0][j],-prices[i]+dp_prev[1][j]});
                  dp_curr[1][j]=max({dp_prev[1][j],dp_curr[1][j],prices[i]+dp_prev[0][j+1]});
                  
              }
              dp_prev=dp_curr;
          }
          return dp_prev[0][0];
      }
  };



-- -- -- -- -- -- -- -- -LeetCode - POTD - 19 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------



