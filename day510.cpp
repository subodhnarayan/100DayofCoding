-- -- -- -- -- -- -- -- -GFG - POTD - 21 / 05 / 2025 ----------------------------------------

Kth Smallest Number in Multiplication Table
Difficulty: HardAccuracy: 50.15%Submissions: 17K+Points: 8
Given three integers m, n and k. Consider a grid of m * n, where mat[i][j] = i * j (1 based index). The task is to return the kth smallest element in the m * n multiplication table.

Examples :

Input: m = 3, n = 3, k = 5
Output: 3
Explanation: 

The 5th smallest element is 3. 
Input: m = 2, n = 3, k = 6
Output: 6 
Explanation: [1, 2, 3][2, 4, 6]. The 6th smallest element is 6.
Constraints:
1 <= m, n <= 3 * 104
1 <= k <= m * n

Expected Complexities
Time Complexity: O(m * log (m*n))
Auxiliary Space: O(1)


class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
         int low = 1, high = n * m; // Search space: 1 to m*n
        int ans = n * m; // Initialize answer with the largest possible value

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid overflow
            int cnt = 0; // Count numbers <= mid

            // For each row, count how many numbers are <= mid
            for (int i = 1; i <= m; ++i) {
                // Numbers in row i: i, 2i, 3i, ..., ni
                // The count is min(mid/i, n)
                cnt += min(mid / i, n);
            }

            // If count >= k, the answer is in the left half
            if (cnt >= k) {
                ans = mid;
                high = mid - 1;
            } 
            // Else, search the right half
            else {
                low = mid + 1;
            }
        }

        return ans; // The kth smallest number
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 21 / 05 / 2025 ----------------------------------------

