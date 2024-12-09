-- -- -- -- -- -- -- -- -GFG - POTD - 09 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Insert Interval
Difficulty: MediumAccuracy: 50.61%Submissions: 24K+Points: 4
Geek has an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith event and intervals is sorted in ascending order by starti. He wants to add a new interval newInterval= [newStart, newEnd] where newStart and newEnd represent the start and end of this interval.

Help Geek to insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Examples:

Input: intervals = [[1,3], [4,5], [6,7], [8,10]], newInterval = [5,6]
Output: [[1,3], [4,7], [8,10]]
Explanation: The newInterval [5,6] overlaps with [4,5] and [6,7].
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,9]
Output: [[1,2], [3,10], [12,16]]
Explanation: The new interval [4,9] overlaps with [3,5],[6,7],[8,10].
Constraints:
1 ≤ intervals.size() ≤  105
0 ≤ start[i], end[i] ≤ 109


class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        
        int n = intervals.size();
        int idx = -1;

        // Step 1: Find the insertion point for the new interval
        for (int i = 0; i < n; ++i) {
            if (intervals[i][0] < newInterval[0]) {
                idx = i;
            } else {
                break;
            }
        }

        // Step 2: Insert the new interval
        intervals.push_back(newInterval); // Append to the end temporarily
        for (int i = n - 1; i > idx; --i) { // Shift elements to make space
            swap(intervals[i], intervals[i + 1]);
        }

        // Step 3: Merge overlapping intervals
        vector<vector<int>> ans; // Result array
        vector<int> ele = {-1, -1}; // Temporary variable for merging intervals

        for (int i = 0; i <= n; ++i) {
            if (ele[0] == -1) {
                // Initialize the first interval to merge
                ele = intervals[i];
            } else {
                if (ele[1] >= intervals[i][0]) {
                    // If intervals overlap, merge them
                    ele[1] = max(ele[1], intervals[i][1]);
                } else {
                    // If no overlap, add the merged interval to the result
                    ans.push_back(ele);
                    ele = intervals[i]; // Start a new interval
                }
            }
        }

        // Step 4: Add the last merged interval
        ans.push_back(ele);

        return ans; // Return the final merged array
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 09 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


 

