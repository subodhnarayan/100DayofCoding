-- -- -- -- -- -- -- -- -GFG - POTD - 18 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Reverse a linked list
Difficulty: EasyAccuracy: 73.11%Submissions: 327K+Points: 2
Given the head of a linked list, the task is to reverse this list and return the reversed head.

Examples:

Input: head: 1 -> 2 -> 3 -> 4 -> NULL
Output: head: 4 -> 3 -> 2 -> 1 -> NULL
Explanation:

Input: head: 2 -> 7 -> 10 -> 9 -> 8 -> NULL
Output: head: 8 -> 9 -> 10 -> 7 -> 2 -> NULL
Explanation:

Input: head: 2 -> NULL
Output: 2 -> NULL
Explanation:

Constraints:
1 <= number of nodes, data of nodes <= 105

Time Complexity: O(n)Auxiliary Space: O(1)


class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node * prev=NULL;
        Node* curr=head;
        while(curr->next!=NULL){
            
        }
    }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 18 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

1368. Minimum Cost to Make at Least One Valid Path in a Grid
Solved
Hard
Topics
Companies
Hint
Given an m x n grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell. The sign of grid[i][j] can be:

1 which means go to the cell to the right. (i.e go from grid[i][j] to grid[i][j + 1])
2 which means go to the cell to the left. (i.e go from grid[i][j] to grid[i][j - 1])
3 which means go to the lower cell. (i.e go from grid[i][j] to grid[i + 1][j])
4 which means go to the upper cell. (i.e go from grid[i][j] to grid[i - 1][j])
Notice that there could be some signs on the cells of the grid that point outside the grid.

You will initially start at the upper left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path does not have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a cell one time only.

Return the minimum cost to make the grid have at least one valid path.

 

Example 1:


Input: grid = [[1,1,1,1],[2,2,2,2],[1,1,1,1],[2,2,2,2]]
Output: 3
Explanation: You will start at point (0, 0).
The path to (3, 3) is as follows. (0, 0) --> (0, 1) --> (0, 2) --> (0, 3) change the arrow to down with cost = 1 --> (1, 3) --> (1, 2) --> (1, 1) --> (1, 0) change the arrow to down with cost = 1 --> (2, 0) --> (2, 1) --> (2, 2) --> (2, 3) change the arrow to down with cost = 1 --> (3, 3)
The total cost = 3.
Example 2:


Input: grid = [[1,1,3],[3,2,2],[1,1,4]]
Output: 0
Explanation: You can follow the path from (0, 0) to (2, 2).
Example 3:


Input: grid = [[1,2],[4,3]]
Output: 1
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 100
1 <= grid[i][j] <= 4



class Solution {
public:
        const int dx[4] = {0, 0, 1, -1};
        const int dy[4] = {1, -1, 0, 0};
    int minCost(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        deque<pair<int, int>> dq;
        dq.emplace_front(0, 0);
        dist[0][0] = 0;
        
        while (!dq.empty()) {
            auto [x, y] = dq.front(); dq.pop_front();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                    int cost = (i + 1 == grid[x][y]) ? 0 : 1;
                    if (dist[x][y] + cost < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + cost;
                        if (cost == 0) {
                            dq.emplace_front(nx, ny);
                        } else {
                            dq.emplace_back(nx, ny);
                        }
                    }
                }
            }
        }
        return dist[r-1][c-1];
    }
};