-- -- -- -- -- -- -- -- -GFG - POTD - 07 / 05 / 2025 -----------------------------------
Root to Leaf Paths
Difficulty: MediumAccuracy: 43.65%Submissions: 143K+Points: 4Average Time: 30m
Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.

Examples:

Input: root[] = [1, 2, 3, 4, 5, N, N]
ex-3
Output: [[1, 2, 4], [1, 2, 5], [1, 3]]
Explanation: All the possible paths from root node to leaf nodes are: 1 -> 2 -> 4, 1 -> 2 -> 5 and 1 -> 3
Input: root[] = [1, 2, 3]

Output: [[1, 2], [1, 3]] 
Explanation: All the possible paths from root node to leaf nodes are: 1 -> 2 and 1 -> 3
Input: root[] = [10, 20, 30, 40, 60, N, N]

Output: [[10, 20, 40], [10, 20, 60], [10, 30]]
Explanation: All the possible paths from root node to leaf nodes are: 10 -> 20 -> 40, 10 -> 20 -> 60 and 10 -> 30
Constraints:
1 <= number of nodes <= 104
1 <= node->data <= 104

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(h)

void ways(Node* root,vector<int>&cur,vector<vector<int>>& result) {
    if (root==nullptr) 
        return;
    cur.push_back(root->data);
    if(root->left==nullptr && root->right==nullptr) 
        result.push_back(cur);
     else {
        ways(root->left,cur,result);
        ways(root->right,cur,result);
    }
    
    cur.pop_back();
}
class Solution {
public:
vector<vector<int>> Paths(Node* root) {
    // code here
     vector<vector<int>>result;
    vector<int>cur;
    ways(root,cur,result);
    return result;
}
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 07 / 05 / 2025 -----------------------------------



3341. Find Minimum Time to Reach Last Room I
Solved
Medium
Topics
Companies
Hint
There is a dungeon with n x m rooms arranged as a grid.

You are given a 2D array moveTime of size n x m, where moveTime[i][j] represents the minimum time in seconds when you can start moving to that room. You start from the room (0, 0) at time t = 0 and can move to an adjacent room. Moving between adjacent rooms takes exactly one second.

Return the minimum time to reach the room (n - 1, m - 1).

Two rooms are adjacent if they share a common wall, either horizontally or vertically.

 

Example 1:

Input: moveTime = [[0,4],[4,4]]

Output: 6

Explanation:

The minimum time required is 6 seconds.

At time t == 4, move from room (0, 0) to room (1, 0) in one second.
At time t == 5, move from room (1, 0) to room (1, 1) in one second.
Example 2:

Input: moveTime = [[0,0,0],[0,0,0]]

Output: 3

Explanation:

The minimum time required is 3 seconds.

At time t == 0, move from room (0, 0) to room (1, 0) in one second.
At time t == 1, move from room (1, 0) to room (1, 1) in one second.
At time t == 2, move from room (1, 1) to room (1, 2) in one second.
Example 3:

Input: moveTime = [[0,1],[1,2]]

Output: 3

 

Constraints:

2 <= n == moveTime.length <= 50
2 <= m == moveTime[i].length <= 50
0 <= moveTime[i][j] <= 109


class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
            int n = moveTime.size(), m = moveTime[0].size();
            vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minh;
            minh.push({0, 0, 0});
            moveTime[0][0] = 0;
    
            vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            while (!minh.empty()) {
                auto current = minh.top();
                minh.pop();
                int currTime = current[0];
                int currRow = current[1];
                int currCol = current[2];
                if (currTime >= dp[currRow][currCol]) continue;
                if (currRow == n - 1 && currCol == m - 1) return currTime;
                dp[currRow][currCol] = currTime;
    
                for (auto& direction : directions) {
                    int nextRow = currRow + direction[0];
                    int nextCol = currCol + direction[1];
                    if (nextRow >= 0 && nextRow < n &&
                        nextCol >= 0 && nextCol < m &&
                        dp[nextRow][nextCol] == INT_MAX) {
                        int nextTime = max(moveTime[nextRow][nextCol], currTime) + 1;
                        minh.push({nextTime, nextRow, nextCol});
                    }
                }
            }
            return -1;
        }
    };