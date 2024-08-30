- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 30 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

N-Queen Problem
Difficulty: HardAccuracy: 35.43%Submissions: 86K+Points: 8
The n-queens puzzle is the problem of placing n queens on a (n×n) chessboard such that no two queens can attack each other.
Given an integer n, find all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].



Examples:

Input: 1
Output: [1]
Explaination: Only one queen can be placed in the single cell available.
Input: 4
Output: [[2 4 1 3 ],[3 1 4 2 ]]
Explaination: These are the 2 possible solutions.
Expected Time Complexity: O(n!)
Expected Auxiliary Space: O(n2) 

Constraints:
1 ≤ n ≤ 10



class Solution{
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
        vector<vector<int>> ans;
        vector<std::vector<int>> board(n, std::vector<int>(n, 0));
        soln(0,board,ans,n);
        sort(ans.begin(),ans.end());
        return ans;
       // getsoln(0,chesbod,ans,0);
    }
};