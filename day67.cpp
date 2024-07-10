//GFG POTD 2024/7/11
// Largest square formed in a matrix
// Difficulty: MediumAccuracy: 36.98%Submissions: 106K+Points: 4
// Given a binary matrix mat of size n * m, find out the maximum length of a side of a square sub-matrix with all 1s.

// Examples:

// Input: n = 6, m = 5
// mat = [[0, 1, 1, 0, 1], 
//        [1, 1, 0, 1, 0],
//        [0, 1, 1, 1, 0],
//        [1, 1, 1, 1, 0],
//        [1, 1, 1, 1, 1],
//        [0, 0, 0, 0, 0]]
// Output: 3
// Explanation: 

// The maximum length of a side of the square sub-matrix is 3 where every element is 1.
// Input: n = 2, m = 2
// mat = [[1, 1], 
//        [1, 1]]
// Output: 2
// Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.
// Input: n = 2, m = 2
// mat = [[0, 0], 
//        [0, 0]]
// Output: 0
// Explanation: There is no 1 in the matrix.
// Expected Time Complexity: O(n*m)
// Expected Auxiliary Space: O(n*m)

// Constraints:
// 1 ≤ n, m ≤ 500
// 0 ≤ mat[i][j] ≤ 1 

