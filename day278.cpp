-- -- -- -- -- -- -- -- -GFG - POTD - 31 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Solve the Sudoku
Difficulty: HardAccuracy: 37.98%Submissions: 113K+Points: 8
Given an incomplete Sudoku configuration in terms of a 9x9  2-D interger square matrix, mat[][], the task is to solve the Sudoku. It is guaranteed that the input Sudoku will have exactly one solution.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
Note: Zeros represent blanks to be filled with numbers 1-9, while non-zero cells are fixed and cannot be changed.

Examples:

Input: mat[][] = 

Output:

Explanation: Each row, column and 3 x 3 box of the output matrix contains unique numbers.
Input: mat[][] = 

Output:

Explanation: Each row, column and 3 x 3 box of the output matrix contains unique numbers.
Constraints:
mat.size() = 9
mat[i].size() = 9
0 ≤ mat[i][j] ≤ 9


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a solved Sudoku.
    bool check(int i,int j,int k,vector<vector<int>> &mat){
        for(int r=0;r<9;r++){
            if(r!=i && mat[r][j]==k)
            return false;
        }
        
        for(int c=0;c<9;c++){
            if(c!=j && mat[i][c]==k)
            return false;
        }
        
         int r=(i/3)*3 , c=(j/3)*3;
         for(int a=0;a<3;a++){
             for(int b=0;b<3;b++){
                 if(mat[r+a][c+b]==k) return false;
             }
         }
         
         return true;
    }
    bool solve(vector<vector<int>> &mat){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]==0){
                    for(int k=1;k<=9;k++){
                        if(check(i,j,k,mat)){
                            mat[i][j]=k;
                            if(solve(mat))
                             return true;
                             mat[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
        
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends

-- -- -- -- -- -- -- -- -LeetCode - POTD - 31 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


