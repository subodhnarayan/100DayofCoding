//GFG POTD 11/7/2024
// Maximum Connected group
// Difficulty: HardAccuracy: 49.48%Submissions: 34K+Points: 8
// You are given a square binary grid. A grid is considered binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1's. Two cells are said to be connected if both are adjacent(top, bottom, left, right) to each other and both have the same value.

// Examples :

// Input: grid = [1, 1]
//              [0, 1]
// Output: 4
// Explanation: By changing cell (2,1), we can obtain a connected group of 4 1's
// [1, 1]
// [1, 1]
// Input: grid = [1, 0, 1]
//              [1, 0, 1]
//              [1, 0, 1]
// Output: 7
// Explanation: By changing cell (3,2), we can obtain a connected group of 7 1's
// [1, 0, 1]
// [1, 0, 1]
// [1, 1, 1]
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 <= size of the grid<= 500
// 0 <= grid[i][j] <= 1