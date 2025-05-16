-- -- -- -- -- -- -- -- -GFG - POTD - 16 / 05 / 2025 ----------------------------------------

Smallest range in K lists
Difficulty: HardAccuracy: 43.21%Submissions: 37K+Points: 8Average Time: 40m
Given a 2d integer array arr[][] of size k*n, where each row is sorted in ascending order. Your task is to find the smallest range [l, r] that includes at least one element from each of the k lists. If more than one such ranges are found, return the first one.

Examples:

Input: n = 5, k = 3, arr[][] = [[4, 7, 9, 12, 15], [0, 8, 10, 14, 20], [6, 12, 16, 30, 50]]
Output: [6, 8]
Explanation: Smallest range is formed by  number 7 from the first list, 8 from second list and 6 from the third list.
Input: n = 5, k = 3, arr[][] = [[1, 3, 5, 7, 9], [0, 2, 4, 6, 8], [2, 3, 5, 7, 11]]
Output: [1, 2]
Explanation: Smallest range is formed by number 1 present in first list and 2 is present in both 2nd and 3rd list.
Input: n = 2, k = 3, arr[][] = [[2, 4], [1, 7], [20, 40]]
Output: [4, 20]
Explanation: Smallest range is formed by number 4 from the first list, 7 from second list and 20 from the third list.
Constraints:
1 <= k, n <= 500
0 <= arr[ i ] <= 105
Expected Complexities
Time Complexity: O(n * k * log k)
Auxiliary Space: O(k)


class Solution {
  public:
    vector<int> findSmallestRange(vector<vector<int>>& arr) {
        // code here
         int n = arr.size();    // number of rows (k lists)
        int m = arr[0].size(); // number of elements in each row

        // Min-heap to store the current minimum element from each list
        // Pair structure: {element_value, {row_index, column_index}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<>> minHeap;

        int maxVal   = INT_MIN; // To track the current maximum among heap elements
        int maxEl    = -1;      // Final max of the smallest range
        int minEl    = -1;      // Final min of the smallest range
        int minRange = INT_MAX; // Initialize minRange to maximum possible

        // Initialize heap with first element from each list and update maxVal
        for (int i = 0; i < n; i++) {
            minHeap.push({ arr[i][0], { i, 0 } });
            maxVal = max(maxVal, arr[i][0]); // Update the maximum value so far
        }

        // Iterate until we reach the end of any list
        while (true) {
            auto top = minHeap.top(); // Get the smallest current element
            minHeap.pop();

            int minVal = top.first;         // Current minimum value
            int row    = top.second.first;  // Row of the min element
            int col    = top.second.second; // Column of the min element

            // Update the range if current [minVal, maxVal] is smaller
            if (maxVal - minVal < minRange) {
                minRange = maxVal - minVal;
                minEl    = minVal;
                maxEl    = maxVal;
            }

            // If this list is exhausted, we can't find further complete ranges
            if (col + 1 == m) {
                break;
            }

            // Push the next element from the same row into the heap
            int nextVal = arr[row][col + 1];
            minHeap.push({ nextVal, { row, col + 1 } });

            // Update maxVal if needed
            maxVal = max(maxVal, nextVal);
        }

        return { minEl, maxEl }; // Return the smallest range
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 16 / 05 / 2025 ----------------------------------------


