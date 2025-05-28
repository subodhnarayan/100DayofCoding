-- -- -- -- -- -- -- -- -GFG - POTD - 28 / 05 / 2025 ----------------------------------------
Find rectangle with corners as 1
Difficulty: MediumAccuracy: 56.75%Submissions: 16K+Points: 4
Given an n x m binary matrix mat[][] containing only 0s and 1s, determine if there exists a rectangle within the matrix such that all four corners of the rectangle are 1. If such a rectangle exists, return true; otherwise, return false.

Example:

Input: mat[][] =
[[1, 0, 0, 1, 0],
[0, 0, 1, 0, 1],
[0, 0, 0, 1, 0], 
[1, 0, 1, 0, 1]] 
Output: true
Explanation: Valid corners are at index (1,2), (1,4), (3,2), (3,4) 
Input: mat[][] =
[[0, 0, 0],
[0, 0, 0],
[0, 0, 0]]
Output: false
Explanation: There are no valid corners.
Constraints:
1 <= n, m <= 200
0 <= mat[i] <= 1

Expected Complexities
Time Complexity: O(n * (m^2))
Auxiliary Space: O(n)

-- -- -- -- -- -- -- -- -Leetcode - POTD - 28 / 05 / 2025 ----------------------------------------

