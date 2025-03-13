-- -- -- -- -- -- -- -- -GFG - POTD - 13 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
0 - 1 Knapsack Problem
Difficulty: MediumAccuracy: 31.76%Submissions: 471K+Points: 4
Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

Examples :

Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
Constraints:
2 ≤ val.size() = wt.size() ≤ 103
1 ≤ W ≤ 103
1 ≤ val[i] ≤ 103
1 ≤ wt[i] ≤ 103

class Solution {
  public:
    int rec(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& mem) {
        if(i>=val.size()) return 0;
        if(mem[i][W]!=-1) return mem[i][W];
        int take=0;
        if(W>=wt[i])
            take=val[i]+rec(i+1,W-wt[i],wt,val,mem);
        int not_take=rec(i+1,W,wt,val,mem);
        return mem[i][W]=max(take,not_take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
          vector<vector<int>> mem(val.size()+1, vector<int>(W+1,-1));
        return rec(0,W,wt,val,mem);
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 13 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


