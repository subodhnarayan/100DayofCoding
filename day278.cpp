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


827. Making A Large Island
Solved
Hard
Topics
Companies
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.



class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.empty())
            return 0;

        int n = grid.size();
        vector<vector<int>> labels(n,vector<int>(n, 0));
        unordered_map<int, int> islandSizes;
        int label = 1;
        int maxSize = 0;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1 && labels[i][j] == 0) {
                    int size = 0;
                    vector<pair<int, int>> stack;
                    stack.push_back({i, j});
                    labels[i][j] = label;

                    while (!stack.empty()) {
                        auto [x, y] = stack.back();
                        stack.pop_back();
                        size++;

                        for (auto [dx, dy] : dirs) {
                            int nx = x + dx, ny = y + dy;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                                grid[nx][ny] == 1 && labels[nx][ny] == 0) {
                                labels[nx][ny] = label;
                                stack.push_back({nx, ny});
                            }
                        }
                    }

                    islandSizes[label] = size;
                    maxSize = max(maxSize, size);
                    label++;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    unordered_set<int> neighborLabels;
                    int total = 1;

                    for (auto [dx, dy] : dirs) {
                        int nx = i + dx, ny = j + dy;
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n &&
                            grid[nx][ny] == 1) {
                            neighborLabels.insert(labels[nx][ny]);
                        }
                    }

                    for (int lbl : neighborLabels) {
                        total += islandSizes[lbl];
                    }

                    maxSize = max(maxSize, total);
                }
            }
        }

        return maxSize;
    }
};