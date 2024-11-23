-- -- -- -- -- -- -- -- -GFG - POTD - 23 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Minimize the Heights I
Difficulty: MediumAccuracy: 26.16%Submissions: 100K+Points: 4
Given a positive integer k and an array arr[] denoting heights of towers, you have to modify the height of each tower either by increasing or decreasing them by k only once.
Find out what could be the possible minimum difference of the height of shortest and longest towers after you have modified each tower.

Note: A slight modification of the problem can be found here. 

Examples:

Input: k = 2, arr[] = [1, 5, 8, 10]
Output: 5
Explanation: The array can be modified as [3, 3, 6, 8]. The difference between the largest and the smallest is 8 - 3 = 5.
Input: k = 3, arr[] = [3, 9, 12, 16, 20]
Output: 11
Explanation: The array can be modified as [6, 12, 9, 13, 17]. The difference between the largest and the smallest is 17 - 6 = 11. 
Constraints
1 ≤ k ≤ 104
1 ≤ number of towers ≤ 105
0 ≤ arr[i] ≤ 105



class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
          // Step 1: Sort the array to ensure heights are ordered
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        // Initial maximum difference between the tallest and shortest tower
        int ans = arr[n-1] - arr[0];
        
        int mi, ma; // Variables to store the current minimum and maximum
        
        // Step 2: Iterate through the array to calculate possible differences
        for (int i = 1; i < n; i++) {
            // Maximum height can either be reduced by k (last tower) 
            // or increased by k (current tower after modification)
            ma = max(arr[n-1] - k, arr[i-1] + k);
            
            // Minimum height can either be increased by k (first tower) 
            // or reduced by k (current tower after modification)
            mi = min(arr[0] + k, arr[i] - k);
            
            // Step 3: Update the minimum difference found so far
            ans = min(ans, ma - mi);
        }
        
        // Step 4: Return the minimum difference
        return ans;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 23 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

