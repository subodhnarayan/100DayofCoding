-- -- -- -- -- -- -- -- -GFG - POTD - 22 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Stickler Thief II
Difficulty: MediumAccuracy: 52.99%Submissions: 13K+Points: 4Average Time: 30m
You are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.
Determine the maximum amount the thief can steal.

Note: Since the houses are in a circle, the first and last houses are also considered adjacent.

Examples:

Input: arr[] = [2, 3, 2]
Output: 3
Explanation: arr[0] and arr[2] can't be robbed because they are adjacent houses. Thus, 3 is the maximum value thief can rob.
Input: arr[] = [1, 2, 3, 1]
Output: 4
Explanation: Maximum stolen value: arr[0] + arr[2] = 1 + 3 = 4
Input: arr[] = [2, 2, 3, 1, 2]
Output: 5
Explanation: Maximum stolen value: arr[0] + arr[2] = 2 + 3 = 5 or arr[2] + arr[4] = 3 + 2 = 5
Constraints:
2 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 104

class Solution {
  public:
   int solve(int idx, vector<int>& arr){
        int n = arr.size();
        int prev2 = 0, prev1 = arr[idx];
        
        for(int i = idx+1; i < n; ++i){
            int curr = max(arr[i]+prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int maxValue(vector<int>& arr) {
        // your code here
        int includeLastHouse = solve(1, arr);
        arr.pop_back();
        int includeFirstHouse = solve(0, arr);
        return max(includeFirstHouse, includeLastHouse);
    }
};




-- -- -- -- -- -- -- -- -LeetCode - POTD - 22 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

