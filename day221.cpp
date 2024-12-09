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


 
3152. Special Array II
Solved
Medium
Topics
Companies
Hint
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

 

Example 1:

Input: nums = [3,4,1,2,6], queries = [[0,4]]

Output: [false]

Explanation:

The subarray is [3,4,1,2,6]. 2 and 6 are both even.

Example 2:

Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]

Output: [false,true]

Explanation:

The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= queries[i][0] <= queries[i][1] <= nums.length - 1


class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
             int n = nums.size();
        vector<int> prefix(n, 0); // Initialize prefix array with size n
        
        // Calculate the prefix array
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 != 0)) {
                prefix[i]++;
            }
        }

        vector<bool> ans; // Result vector
        
        // Process the queries
        for (auto& q : queries) {
            int left = q[0], right = q[1];
            int specialCount = prefix[right] - (left > 0 ? prefix[left] : 0);
            ans.push_back(specialCount == 0);
        }

        return ans; // Return the result
    }
};