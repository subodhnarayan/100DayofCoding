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

2901. Longest Unequal Adjacent Groups Subsequence II
Solved
Medium
Topics
Companies
Hint
You are given a string array words, and an array groups, both arrays having length n.

The hamming distance between two strings of equal length is the number of positions at which the corresponding characters are different.

You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], such that for the subsequence denoted as [i0, i1, ..., ik-1] having length k, the following holds:

For adjacent indices in the subsequence, their corresponding groups are unequal, i.e., groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k.
words[ij] and words[ij+1] are equal in length, and the hamming distance between them is 1, where 0 < j + 1 < k, for all indices in the subsequence.
Return a string array containing the words corresponding to the indices (in order) in the selected subsequence. If there are multiple answers, return any of them.

Note: strings in words may be unequal in length.

 

Example 1:

Input: words = ["bab","dab","cab"], groups = [1,2,2]

Output: ["bab","cab"]

Explanation: A subsequence that can be selected is [0,2].

groups[0] != groups[2]
words[0].length == words[2].length, and the hamming distance between them is 1.
So, a valid answer is [words[0],words[2]] = ["bab","cab"].

Another subsequence that can be selected is [0,1].

groups[0] != groups[1]
words[0].length == words[1].length, and the hamming distance between them is 1.
So, another valid answer is [words[0],words[1]] = ["bab","dab"].

It can be shown that the length of the longest subsequence of indices that satisfies the conditions is 2.

Example 2:

Input: words = ["a","b","c","d"], groups = [1,2,3,4]

Output: ["a","b","c","d"]

Explanation: We can select the subsequence [0,1,2,3].

It satisfies both conditions.

Hence, the answer is [words[0],words[1],words[2],words[3]] = ["a","b","c","d"].

It has the longest length among all subsequences of indices that satisfy the conditions.

Hence, it is the only answer.

 

Constraints:

1 <= n == words.length == groups.length <= 1000
1 <= words[i].length <= 10
1 <= groups[i] <= n
words consists of distinct strings.
words[i] consists of lowercase English letters.
