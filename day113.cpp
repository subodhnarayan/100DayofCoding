- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 24 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

You are given weights and values of items, and put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val and wt which represent values and weights associated with items respectively. Also given an integer W which represents knapsack capacity, find out the maximum sum values subset of val[] such that the sum of the weights of the corresponding subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don't pick it (0-1 property).

Examples :

Input: W = 4, val[] = {1,2,3}, wt[] = {4,5,1}
Output: 3
Explanation: Choose the last item that weighs 1 unit and holds a value of 3. 
Input: W = 3, val[] = {1,2,3}, wt[] = {4,5,6}
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
Expected Time Complexity: O(N*W).
Expected Auxiliary Space: O(N*W)

Constraints:
2 ≤ N ≤ 1000
1 ≤ W ≤ 1000
1 ≤ wt[i] ≤ 1000
1 ≤ val[i] ≤ 1000


class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
      int rec(int i, int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& mem) {
        if(i>=val.size()) return 0;
        if(mem[i][W]!=-1) return mem[i][W];
        int take=0;
        if(W>=wt[i])
            take=val[i]+rec(i+1,W-wt[i],wt,val,mem);
        int not_take=rec(i+1,W,wt,val,mem);
        return mem[i][W]=max(take,not_take);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
       vector<vector<int>> mem(val.size()+1, vector<int>(W+1,-1));
        return rec(0,W,wt,val,mem);
    }
};


- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 24 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


564. Find the Closest Palindrome
Solved
Hard
Topics
Companies
Hint
Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.

The closest is defined as the absolute difference minimized between two integers.

 

Example 1:

Input: n = "123"
Output: "121"
Example 2:

Input: n = "1"
Output: "0"
Explanation: 0 and 2 are the closest palindromes but we return the smallest which is 0.
 

Constraints:

1 <= n.length <= 18
n consists of only digits.
n does not have leading zeros.
n is representing an integer in the range [1, 1018 - 1].

