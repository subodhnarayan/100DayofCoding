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



- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 30 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

2699. Modify Graph Edge Weights
Solved
Hard
Topics
Companies
Hint
You are given an undirected weighted connected graph containing n nodes labeled from 0 to n - 1, and an integer array edges where edges[i] = [ai, bi, wi] indicates that there is an edge between nodes ai and bi with weight wi.

Some edges have a weight of -1 (wi = -1), while others have a positive weight (wi > 0).

Your task is to modify all edges with a weight of -1 by assigning them positive integer values in the range [1, 2 * 109] so that the shortest distance between the nodes source and destination becomes equal to an integer target. If there are multiple modifications that make the shortest distance between source and destination equal to target, any of them will be considered correct.

Return an array containing all edges (even unmodified ones) in any order if it is possible to make the shortest distance from source to destination equal to target, or an empty array if it's impossible.

Note: You are not allowed to modify the weights of edges with initial positive weights.

 

Example 1:



Input: n = 5, edges = [[4,1,-1],[2,0,-1],[0,3,-1],[4,3,-1]], source = 0, destination = 1, target = 5
Output: [[4,1,1],[2,0,1],[0,3,3],[4,3,1]]
Explanation: The graph above shows a possible modification to the edges, making the distance from 0 to 1 equal to 5.
Example 2:



Input: n = 3, edges = [[0,1,-1],[0,2,5]], source = 0, destination = 2, target = 6
Output: []
Explanation: The graph above contains the initial edges. It is not possible to make the distance from 0 to 2 equal to 6 by modifying the edge with weight -1. So, an empty array is returned.
Example 3:



Input: n = 4, edges = [[1,0,4],[1,2,3],[2,3,5],[0,3,-1]], source = 0, destination = 2, target = 6
Output: [[1,0,4],[1,2,3],[2,3,5],[0,3,1]]
Explanation: The graph above shows a modified graph having the shortest distance from 0 to 2 as 6.
 

Constraints:

1 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= ai, bi < n
wi = -1 or 1 <= wi <= 107
ai != bi
0 <= source, destination < n
source != destination
1 <= target <= 109
The graph is connected, and there are no self-loops or repeated edges