-- -- -- -- -- -- -- -- -GFG - POTD - 21 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Rotate by 90 degree
Difficulty: EasyAccuracy: 56.88%Submissions: 99K+Points: 2
Given a square matrix mat[][] of size n x n. The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 

Examples:

Input: mat[][] = [[1, 2, 3],
                [4, 5, 6]
                [7, 8, 9]]
Output: Rotated Matrix:
[3, 6, 9]
[2, 5, 8]
[1, 4, 7]
Input: mat[][] = [[1, 2],
                [3, 4]]
Output: Rotated Matrix:
[2, 4]
[1, 3]
Constraints:
1 ≤ n ≤ 102
0 <= mat[i][j] <= 103

class Solution {
  public:
    // Function to rotate matrix anticlockwise by 90 degrees.
    void rotateby90(vector<vector<int>>& arr) {
        int n=arr.size();
       for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                swap(arr[i][j],arr[j][i]);
            }
        }
    for(int i=0;i<n;i++)
    {
        int start=0;
        int end=n-1;
        while(start<end)
        {
            swap(arr[start][i],arr[end][i]);
            start++;
            end--;
        }
    }
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 21 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

