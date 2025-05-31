-- -- -- -- -- -- -- -- -GFG - POTD - 31 / 05 / 2025 ----------------------------------------

Kth element in Matrix
Difficulty: MediumAccuracy: 61.42%Submissions: 70K+Points: 4Average Time: 35m
Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

Examples:
Input: n = 4, mat[][] = [[16, 28, 60, 64], [22, 41, 63, 91], [27, 50, 87, 93], [36, 78, 87, 94]], k = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
Input: n = 4, mat[][] = [[10, 20, 30, 40], [15, 25, 35, 45], [24, 29, 37, 48], [32, 33, 39, 50]], k = 7
Output: 30
Explanation: 30 is the 7th smallest element.
Constraints:
1 <= n <= 500
1 <= mat[i][j] <= 10000
1 <= k <= n*n

Expected Complexities
Time Complexity: O(n * log (mat[i][j] ))
Auxiliary Space: O(1)


class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
         int m=matrix.size();
        int n=m*m;
        int arr[n];
        int a=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<m;j++)
        {
            arr[a++]=matrix[i][j];
        }
            
        }
        sort(arr,arr+a);
        return arr[k-1];
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 31 / 05 / 2025 ----------------------------------------
