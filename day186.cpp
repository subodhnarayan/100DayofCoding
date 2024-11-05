Rotate by 90 degree
Difficulty: MediumAccuracy: 66.8%Submissions: 55K+Points: 4
Given a square mat[][]. The task is to rotate it by 90 degrees in clockwise direction without using any extra space.

Examples:

Input: mat[][] = [[1 2 3], [4 5 6], [7 8 9]]
Output:
7 4 1 
8 5 2
9 6 3
Input: mat[][] = [1 2], [3 4]
Output:
3 1 
4 2
Input: mat[][] = [[1]]
Output:
1
Constraints:
1 ≤ mat.size() ≤ 1000
1 <= mat[][] <= 100


void rotate(vector<vector<int> >& mat) {
    // Your code goes here
     int n = mat.size();
    for(int i=0; i < n/2; i++)
    {
        for(int j=i; j < (n-1-i); j++)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[n-j-1][i];
            mat[n-j-1][i] = mat[n-i-1][n-j-1];
            mat[n-i-1][n-j-1] = mat[j][n-i-1];
            mat[j][n-i-1] = temp;
        }
    }
    return;
}
