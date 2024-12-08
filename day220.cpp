-- -- -- -- -- -- -- -- -GFG - POTD - 08 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Overlapping Intervals
Difficulty: MediumAccuracy: 57.41%Submissions: 85K+Points: 4
Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

Examples:

Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]
Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].
Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
Output: [[1,9]]
Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ starti ≤ endi ≤ 105




class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
      sort(arr.begin(),arr.end());
        vector<vector<int>>result;
        int s1=arr[0][0],e1=arr[0][1];
        for(int i=1;i<arr.size();i++)
        {
            if(e1>=arr[i][0])
            {
                e1=max(e1,arr[i][1]);
            }
            else
            {
                result.push_back({s1,e1});
                s1=arr[i][0];
                e1=arr[i][1];
            }
        }
        result.push_back({s1,e1});
        return result;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 08 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


 
2054. Two Best Non-Overlapping Events
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

 

Example 1:


Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
Example 2:

Example 1 Diagram
Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.
Example 3:


Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.
 

Constraints:

2 <= events.length <= 105
events[i].length == 3
1 <= startTimei <= endTimei <= 109
1 <= valuei <= 106



class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<int> suffixMax(n);
        suffixMax[n - 1] = events[n - 1][2];
        
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(events[i][2], suffixMax[i + 1]);
        }
        
        int maxSum = 0;
        
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = n - 1;
            int nextEventIndex = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]) {
                    nextEventIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            if (nextEventIndex != -1) {
                maxSum = max(maxSum, events[i][2] + suffixMax[nextEventIndex]);
            }
            
            maxSum = max(maxSum, events[i][2]);
        }
        
        return maxSum;
    }
};
