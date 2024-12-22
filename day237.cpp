-- -- -- -- -- -- -- -- -GFG - POTD - 22 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Search in a Row-Column sorted matrix
Difficulty: EasyAccuracy: 41.62%Submissions: 158K+Points: 2
Given a 2D integer matrix mat[][] of size n x m, where every row and column is sorted in increasing order and a number x, the task is to find whether element x is present in the matrix.

Examples:

Input: mat[][] = [[3, 30, 38],[20, 52, 54],[35, 60, 69]], x = 62
Output: false
Explanation: 62 is not present in the matrix, so output is false.
Input: mat[][] = [[18, 21, 27],[38, 55, 67]], x = 55
Output: true
Explanation: 55 is present in the matrix.
Input: mat[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]], x = 3
Output: true
Explanation: 3 is present in the matrix.
Constraints:
1 <= n, m <=1000
1 <= mat[i][j] <= 109
1<= x <= 109


class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int X) {
        int N=mat.size();
        int M=mat[0].size();
            if(M==0 || N==0) return 0;
	    int row=N;
	    int col=M;
	    int start=0;
	    int end=M-1;  //starting from top right corner
	    while(start<row && end<col){
	       // int mid=start+(end-start)/2;
	       // int ro_idx=mid/M;
	       // int co_idx=mid%M;
	       // if(mat[ro_idx][co_idx]==X)
	       // {
	       //     return 1;
	       // }
	       // else if(mat[ro_idx][co_idx]<X){
	       //     start=mid+1;
	       // }
	       // else
	       // {
	       //     end=mid-1;
	       // }  it will not work here
	       
	       
	       if(mat[start][end]==X){
	           return 1;
	       }
	       else if(mat[start][end]>X){
	           end--;
	       }
	       else{
	           start++;
	       }
	       
	    }
	    return 0;

    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 22 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

