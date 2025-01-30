-- -- -- -- -- -- -- -- -GFG - POTD - 29 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
N-Queen Problem
Difficulty: HardAccuracy: 35.43%Submissions: 99K+Points: 8
The n-queens puzzle is the problem of placing n queens on a (n × n) chessboard such that no two queens can attack each other. Note that two queens attack each other if they are placed on the same row, the same column, or the same diagonal.

Given an integer n, find all distinct solutions to the n-queens puzzle.
You can return your answer in any order but each solution should represent a distinct board configuration of the queen placements, where the solutions are represented as permutations of [1, 2, 3, ..., n]. In this representation, the number in the ith position denotes the row in which the queen is placed in the ith column.
For eg. below figure represents a chessboard [3 1 4 2].



Examples:

Input: n = 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.
Input: n = 4
Output: [[2 4 1 3 ] [3 1 4 2 ]]
Explaination: There are 2 possible solutions for n = 4.
Input: n = 2
Output: []
Explaination: There are no possible solutions for n = 2.
Constraints:
1 ≤ n ≤ 10

Time Complexity: O(n!)Auxiliary Space: O(n^2)


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool issafe(int row,int col,vector<vector<int>> &board,int n){
        int crow=row;
        int ccol=col;
        
        while(row>=0 && col>=0){
            if(board[row][col]==1) return false;
            row--;
            col--;
        }
        
        row=crow;
        col=ccol;
        while(col>=0){
            if(board[row][col]==1) return false;
            col--;
        }
        
    
        row=crow;
        col=ccol;
        
         while(row<n && col>=0){
            if(board[row][col]==1) return false;
            row++;
            col--;
        }
        
        return true;
        
    }
    
    void soln(int col,vector<vector<int>> &board, vector<vector<int>> &ans,int n){
        if(col==n){
            vector<int> res;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]==1){
                        res.push_back(j+1);
                    }
                }
            }
            ans.push_back(res);
            return;
        }
        
        for(int row=0;row<n;row++){
         if(issafe(row,col,board,n)){
             board[row][col]=1;
             soln(col+1,board,ans,n);
             board[row][col]=0;
         }
            
        }
    }
  
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<std::vector<int>> board(n, std::vector<int>(n, 0));
        soln(0,board,ans,n);
        sort(ans.begin(),ans.end());
        return ans;
       // getsoln(0,chesbod,ans,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends

-- -- -- -- -- -- -- -- -LeetCode - POTD - 29 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


