-- -- -- -- -- -- -- -- -GFG - POTD - 20 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Stock Buy and Sell – Max 2 Transactions Allowed
Difficulty: HardAccuracy: 50.13%Submissions: 66K+Points: 8Average Time: 20m
In daily share trading, a trader buys shares and sells them on the same day. If the trader is allowed to make at most 2 transactions in a day, find out the maximum profit that a share trader could have made.

You are given an array prices[] representing stock prices throughout the day. Note that the second transaction can only start after the first one is complete (buy->sell->buy->sell).

Examples:

Input: prices[] = [10, 22, 5, 75, 65, 80]
Output: 87
Explanation: 
Trader will buy at 10 and sells at 22. 
Profit earned in 1st transaction = 22 - 10 = 12. 
Then he buys at 5 and sell at 80. 
Profit earned in 2nd transaction = 80 - 5 = 75. 
Total profit earned = 12 + 75 = 87. 
Input: prices[] = [2, 30, 15, 10, 8, 25, 80]
Output: 100
Explanation: 
Trader will buy at 2 and sells at 30. 
Profit earned in 1st transaction = 30 - 2 = 28. 
Then he buys at 8 and sell at 80. 
Profit earned in 2nd transaction = 80 - 8 = 72. 
Total profit earned = 28 + 72 = 100.
Constraints:
1 <= prices.size() <= 105
1 <= prices[i] <= 10

class Solution {
    public:
      int maxProfit(vector<int> &prices) {
          // code here
          vector<int>next(5),curr(5);
           int n=prices.size();
           for(int i=n-1;i>=0;i--){
               for(int j=3;j>=0;j--){
                   int profit=0;
                   if(j%2==0){
                       profit=max(-prices[i]+next[j+1],next[j]);
                   }
                   else{
                       profit=max(prices[i]+next[j+1],next[j]);
                   }
                   curr[j]=profit;
               }
               next=curr;
           }
           return next[0];
      }
  };




-- -- -- -- -- -- -- -- -LeetCode - POTD - 20 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------



