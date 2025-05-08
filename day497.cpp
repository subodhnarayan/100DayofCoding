-- -- -- -- -- -- -- -- -GFG - POTD - 08 / 05 / 2025 -----------------------------------
Missing element of AP
Difficulty: MediumAccuracy: 34.32%Submissions: 70K+Points: 4
Given a sorted array arr[] that represents an Arithmetic Progression (AP) with exactly one missing element, find the missing number.

Note: An element will always exist that, upon inserting into a sequence forms Arithmetic progression. If the given sequence already forms a valid complete AP, return the (n+1)-th element that would come next in the sequence.

Examples:

Input: arr[] = [2, 4, 8, 10, 12, 14]
Output: 6
Explanation: Actual AP should be 2, 4, 6, 8, 10, 12, 14.
Input: arr[] = [1, 6, 11, 16, 21, 31]
Output: 26
Explanation: Actual AP should be 1, 6, 11, 16, 21, 26, 31.
Input: arr[] = [4, 7, 10, 13, 16]
Output: 19
Explanation: Since the sequence already forms a valid AP, the next element after 16 in the sequence would be 19. Therefore, the output is 19.
Constraints:
2 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 2*107

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)

class Solution {
    public:
      int findMissing(vector<int> &arr) {
          // code here
           int n = arr.size();
          bool neg = arr[0] > arr[1]; // Check if AP is decreasing
          
          // Edge Case: If array has only 2 elements
          if(n == 2) {
              int rem = arr[1] - arr[0];
              return (rem + arr[1]); // Next element in AP
          }
          
          map<int,int> mp; // Store frequency of differences
          
          // Calculate all differences between consecutive elements
          for(int i = 1; i < n; ++i) {
              mp[abs(arr[i] - arr[i-1])]++;
          }
          
          // The correct difference is the smallest (since the wrong difference is larger)
          int diff = mp.begin()->first;
          
          // Traverse the array to find where the difference is not 'diff'
          for(int i = 0; i < n-1; ++i) {
              if((arr[i] + (neg ? -1 : 1)*diff) != arr[i+1]) {
                  return (arr[i] + (neg ? -1 : 1)*diff); // Missing element
              }
          }
          
          // If no missing element found, return the next element after the last one
          return (arr[n-1] + (neg ? -1 : 1)*diff);
      }
  };
-- -- -- -- -- -- -- -- -Leetcode - POTD - 08 / 05 / 2025 -----------------------------------

3342. Find Minimum Time to Reach Last Room II
Solved
Medium
Topics
Companies
Hint
There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes one second for one move and two seconds for the next, alternating between the two.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 

Example 1:

Input: moveTime = [[0,4],[4,4]]

Output: 7

Explanation:

The minimum time required is 7 seconds.

At time t == 4, move from room (0, 0) to room (1, 0) in one second.
At time t == 5, move from room (1, 0) to room (1, 1) in two seconds.
Example 2:

Input: moveTime = [[0,0,0,0],[0,0,0,0]]

Output: 6

Explanation:

The minimum time required is 6 seconds.

At time t == 0, move from room (0, 0) to room (1, 0) in one second.
At time t == 1, move from room (1, 0) to room (1, 1) in two seconds.
At time t == 3, move from room (1, 1) to room (1, 2) in one second.
At time t == 4, move from room (1, 2) to room (1, 3) in two seconds.
Example 3:

Input: moveTime = [[0,1],[1,2]]

Output: 4

 

Constraints:

2 <= n == moveTime.length <= 750
2 <= m == moveTime[i].length <= 750
0 <= moveTime[i][j] <= 109


