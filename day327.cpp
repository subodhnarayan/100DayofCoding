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



3191. Minimum Operations to Make Binary Array Elements Equal to One I
Medium
Topics
Companies
Hint
You are given a binary array nums.

You can do the following operation on the array any number of times (possibly zero):

Choose any 3 consecutive elements from the array and flip all of them.
Flipping an element means changing its value from 0 to 1, and from 1 to 0.

Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.

 

Example 1:

Input: nums = [0,1,1,1,0,0]

Output: 3

Explanation:
We can do the following operations:

Choose the elements at indices 0, 1 and 2. The resulting array is nums = [1,0,0,1,0,0].
Choose the elements at indices 1, 2 and 3. The resulting array is nums = [1,1,1,0,0,0].
Choose the elements at indices 3, 4 and 5. The resulting array is nums = [1,1,1,1,1,1].
Example 2:

Input: nums = [0,1,1,1]

Output: -1

Explanation:
It is impossible to make all elements equal to 1.

 

Constraints:

3 <= nums.length <= 105
0 <= nums[i] <= 

class Solution {
    public:
        int minOperations(vector<int>& nums) {
            int count = 0;
            int n = nums.size();
            
            for (int i = 0; i < n - 2; i++) {
                if (nums[i] == 0) {
                    nums[i] ^= 1;
                    nums[i + 1] ^= 1;
                    nums[i + 2] ^= 1;
                    count++;
                }
            }
            
            return (nums[n - 2] == 1 && nums[n - 1] == 1) ? count : -1;
        }
    };