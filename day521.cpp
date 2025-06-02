-- -- -- -- -- -- -- -- -GFG - POTD - 02 / 06 / 2025 ----------------------------------------

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

-- -- -- -- -- -- -- -- -Leetcode - POTD - 02 / 06 / 2025 ----------------------------------------


909. Snakes and Ladders
Solved
Medium
Topics
premium lock icon
Companies
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.

Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.

 

Example 1:


Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
Output: 4
Explanation: 
In the beginning, you start at square 1 (at row 5, column 0).
You decide to move to square 2 and must take the ladder to square 15.
You then decide to move to square 17 and must take the snake to square 13.
You then decide to move to square 14 and must take the ladder to square 35.
You then decide to move to square 36, ending the game.
This is the lowest possible number of moves to reach the last square, so return 4.
Example 2:

Input: board = [[-1,-1],[-1,3]]
Output: 1
 

Constraints:

n == board.length == board[i].length
2 <= n <= 20
board[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 are not the starting points of any snake or ladder.


class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> min_rolls(n * n + 1, -1);
        queue<int> q;
        min_rolls[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 1; i <= 6 && x + i <= n * n; i++) {
                int t = x + i, row = (t - 1) / n, col = (t - 1) % n;
                int v = board[n - 1 - row][row % 2 ? n - 1 - col : col];
                int y = v > 0 ? v : t; // follow ladder / snake if present
                if (y == n * n)
                    return min_rolls[x] + 1;
                if (min_rolls[y] == -1) {
                    min_rolls[y] = min_rolls[x] + 1;
                    q.push(y);
                }
            }
        }
        return -1;
    }
};