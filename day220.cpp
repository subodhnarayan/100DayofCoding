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


 

