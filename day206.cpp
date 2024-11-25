-- -- -- -- -- -- -- -- -GFG - POTD - 25 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -



Maximum Product Subarray
Difficulty: MediumAccuracy: 18.09%Submissions: 402K+Points: 4
Given an array arr[] that contains positive and negative integers (may contain 0 as well). Find the maximum product that we can get in a subarray of arr.

Note: It is guaranteed that the output fits in a 32-bit integer.

Examples

Input: arr[] = [-2, 6, -3, -10, 0, 2]
Output: 180
Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.
Input: arr[] = [-1, -3, -10, 0, 6]
Output: 30
Explanation: The subarray with maximum product is {-3, -10} with product = (-3) * (-10) = 30.
Input: arr[] = [2, 3, 4] 
Output: 24 
Explanation: For an array with all positive elements, the result is product of all elements. 
Constraints:
1 ≤ arr.size() ≤ 106
-10  ≤  arr[i]  ≤  10
-- -- -- -- -- -- -- -- -Leetcode - POTD - 25 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
773. Sliding Puzzle
Solved
Hard
Topics
Companies
Hint
On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

 

Example 1:


Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Example 2:


Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Example 3:


Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
 

Constraints:

board.length == 2
board[i].length == 3
0 <= board[i][j] <= 5
Each value board[i][j] is unique.



class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
         // Directions for possible swaps based on '0' position
        vector<vector<int>> dir = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string target = "123450";
        set<string> vis; // Track visited configurations
        queue<string> q;
        string start = "";

        // Convert 2D board to a single string
        for (auto row : board) {
            for (auto col : row) {
                start += col + '0';
            }
        }

        q.push(start);
        vis.insert(start);
        int step = 0;

        // Perform BFS
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string current = q.front();
                q.pop();

                // Check if target is reached
                if (current == target) return step;

                int zero = current.find('0'); // Find position of '0'

                // Generate next moves
                for (auto move : dir[zero]) {
                    string next = current;
                    swap(next[move], next[zero]);
                    if (!vis.count(next)) { // Add unvisited states to the queue
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            step++;
        }
        return -1; // Return -1 if target is unreachable
    }
};


