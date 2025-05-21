-- -- -- -- -- -- -- -- -GFG - POTD - 21 / 05 / 2025 ----------------------------------------

Kth Smallest Number in Multiplication Table
Difficulty: HardAccuracy: 50.15%Submissions: 17K+Points: 8
Given three integers m, n and k. Consider a grid of m * n, where mat[i][j] = i * j (1 based index). The task is to return the kth smallest element in the m * n multiplication table.

Examples :

Input: m = 3, n = 3, k = 5
Output: 3
Explanation: 

The 5th smallest element is 3. 
Input: m = 2, n = 3, k = 6
Output: 6 
Explanation: [1, 2, 3][2, 4, 6]. The 6th smallest element is 6.
Constraints:
1 <= m, n <= 3 * 104
1 <= k <= m * n

Expected Complexities
Time Complexity: O(m * log (m*n))
Auxiliary Space: O(1)


class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
         int low = 1, high = n * m; // Search space: 1 to m*n
        int ans = n * m; // Initialize answer with the largest possible value

        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid overflow
            int cnt = 0; // Count numbers <= mid

            // For each row, count how many numbers are <= mid
            for (int i = 1; i <= m; ++i) {
                // Numbers in row i: i, 2i, 3i, ..., ni
                // The count is min(mid/i, n)
                cnt += min(mid / i, n);
            }

            // If count >= k, the answer is in the left half
            if (cnt >= k) {
                ans = mid;
                high = mid - 1;
            } 
            // Else, search the right half
            else {
                low = mid + 1;
            }
        }

        return ans; // The kth smallest number
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 21 / 05 / 2025 ----------------------------------------

73. Set Matrix Zeroes
Solved
Medium
Topics
Companies
Hint
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

class Solution {
public:
    void makezero(int m,int n,int row,int col,vector<vector<int>> &mat){
        for(int k=0;k<row;k++){
         mat[k][n]=0;
        }
        for(int k=0;k<col;k++){
         mat[m][k]=0;
        }
    }

    
    void setZeroes(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        //First Approach using 0(M*N);
        // vector<vector<int>> an(mat.begin(),mat.end());
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         if(an[i][j]==0){
        //             makezero(i,j,row,col,mat);
        //         }
        //     }
        // }

        //second appraoch using space o(m+n)
        // vector<int> cl(col,0);
        // vector<int> rw(row,0);
        
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         if(mat[i][j]==0){
        //             rw[i]=1;
        //             cl[j]=1;
        //         }
        //     }
        // }

        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         if(mat[i][j]!=0 && (rw[i]==1 || cl[j]==1)){
        //             mat[i][j]=0;
        //         }
        //     }
        // }


        //third approach using space o(1)
        
        int col0=1;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    mat[i][0]=0;
                    if(j!=0)
                    mat[0][j]=0;
                    else
                    col0=0;
                }
            }
        }


        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(mat[i][j]==0 || (mat[0][j]==0 || mat[i][0]==0)){
                    mat[i][j]=0;
                }
            }
        }

        //now first solving in column because row arr is dependent on col
        if(mat[0][0]==0){
            for(int i=0;i<col;i++){
                mat[0][i]=0;
            }
        }

        if(col0==0){
            for(int i=0;i<row;i++){
                mat[i][0]=0;
            }
        }




        

    }
};