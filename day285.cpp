-- -- -- -- -- -- -- -- -GFG - POTD - 06 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Inorder Traversal
Difficulty: EasyAccuracy: 67.15%Submissions: 176K+Points: 2Average Time: 15m
Given a Binary Tree, your task is to return its In-Order Traversal.

An inorder traversal first visits the left child (including its entire subtree), then visits the node, and finally visits the right child (including its entire subtree).

Follow Up: Try solving this with O(1) auxiliary space.

Examples:

Input: root[] = [1, 2, 3, 4, 5] 
      
Output: [4, 2, 5, 1, 3]
Explanation: The in-order traversal of the given binary tree is [4, 2, 5, 1, 3].
Input: root[] = [8, 1, 5, N, 7, 10, 6, N, 10, 6]
      
Output: [1, 7, 10, 8, 6, 10, 5, 6]
Explanation: The in-order traversal of the given binary tree is [1, 7, 10, 8, 6, 10, 5, 6].
Constraints:

1 <= number of nodes <= 105
0 <= node->data <= 105

-- -- -- -- -- -- -- -- -LeetCode - POTD - 06 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

3160. Find the Number of Distinct Colors Among the Balls
Solved
Medium
Topics
Companies
Hint
You are given an integer limit and a 2D array queries of size n x 2.

There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.

Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.

Note that when answering a query, lack of a color will not be considered as a color.

 

Example 1:

Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]

Output: [1,2,2,3]

Explanation:



After query 0, ball 1 has color 4.
After query 1, ball 1 has color 4, and ball 2 has color 5.
After query 2, ball 1 has color 3, and ball 2 has color 5.
After query 3, ball 1 has color 3, ball 2 has color 5, and ball 3 has color 4.
Example 2:

Input: limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]

Output: [1,2,2,3,4]

Explanation:



After query 0, ball 0 has color 1.
After query 1, ball 0 has color 1, and ball 1 has color 2.
After query 2, ball 0 has color 1, and balls 1 and 2 have color 2.
After query 3, ball 0 has color 1, balls 1 and 2 have color 2, and ball 3 has color 4.
After query 4, ball 0 has color 1, balls 1 and 2 have color 2, ball 3 has color 4, and ball 4 has color 5.
 

Constraints:

1 <= limit <= 109
1 <= n == queries.length <= 105
queries[i].length == 2
0 <= queries[i][0] <= limit
1 <= queries[i][1] <= 109


class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
         unordered_map<int,int> ball, color;
        vector<int> ans;
        ans.reserve(queries.size());
        int distinct = 0;
        for(auto &q : queries) {
            int pos = q[0], c = q[1];
            if(ball.count(pos))
                if(--color[ball[pos]] == 0) distinct--;
            ball[pos] = c;
            if(++color[c] == 1) distinct++;
            ans.push_back(distinct);
        }
        return ans;
    }
};

