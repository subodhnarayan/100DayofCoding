// GFG POTD 13/7/2024
//  Shortest Path in Weighted undirected graph
//  Difficulty: MediumAccuracy: 50.0%Submissions: 45K+Points: 4
//  You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

// The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

// Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1.

// Examples :

// Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
// Output: 5
// Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5.
// Input: n = 2, m= 1, edges = [[1, 2, 2]]
// Output: 2
// Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2.
// Input: n = 2, m= 0, edges = [ ]
// Output: -1
// Explanation: Since there are no edges, so no answer is possible.
// Expected Time Complexity: O(m* log(n))
// Expected Space Complexity: O(n+m)

// Constraint:
// 2 <= n <= 106
// 0 <= m <= 106
// 1 <= a, b <= n
// 1 <= w <= 105

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> par(n + 1, -1);
    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    pq.push({0, {1, -1}});
    while (!pq.empty())
    {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjnode = it.first;
            int edW = it.second;
            if (wt + edW < dist[adjnode])
            {
                dist[adjnode] = wt + edW;
                par[adjnode] = node;
                pq.push({dist[adjnode], {adjnode, node}});
            }
        }
    }

    int cost = dist[n];
    if (cost == INT_MAX)
    {
        return {-1};
    }
    vector<int> ans;
    for (int v = n; v != -1; v = par[v])
    {
        ans.push_back(v);
    }
    ans.push_back(cost);
    reverse(ans.begin(), ans.end());
    return ans;
}

// POTD Leetcode 13/7/2024

// 2751. Robot Collisions
// Solved
// Hard
// Topics
// Companies
// Hint
// There are n 1-indexed robots, each having a position on a line, health, and movement direction.

// You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.

// All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

// If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.

// Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.

// Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

// Note: The positions may be unsorted.

// Example 1:

// Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
// Output: [2,17,9,15,10]
// Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].
// Example 2:

// Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
// Output: [14]
// Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide, and since both have the same health, they will be removed from the line. Next, robot 3 and robot 4 will collide and since robot 4's health is smaller, it gets removed, and robot 3's health becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].
// Example 3:

// Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
// Output: []
// Explanation: Robot 1 and robot 2 will collide and since both have the same health, they are both removed. Robot 3 and 4 will collide and since both have the same health, they are both removed. So, we return an empty array, [].

// Constraints:

// 1 <= positions.length == healths.length == directions.length == n <= 105
// 1 <= positions[i], healths[i] <= 109
// directions[i] == 'L' or directions[i] == 'R'
// All values in positions are distinct

vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
{
    int n = positions.size();
    vector<vector<int>> robots;

    for (int i = 0; i < n; ++i)
    {
        robots.push_back({positions[i], healths[i], directions[i], i});
    }

    sort(robots.begin(), robots.end());

    vector<vector<int>> stack;

    for (auto &robot : robots)
    {
        if (robot[2] == 'R' || stack.empty() || stack.back()[2] == 'L')
        {
            stack.push_back(robot);
            continue;
        }

        if (robot[2] == 'L')
        {
            bool add = true;
            while (!stack.empty() && stack.back()[2] == 'R' && add)
            {
                int last_health = stack.back()[1];
                if (robot[1] > last_health)
                {
                    stack.pop_back();
                    robot[1] -= 1;
                }
                else if (robot[1] < last_health)
                {
                    stack.back()[1] -= 1;
                    add = false;
                }
                else
                {
                    stack.pop_back();
                    add = false;
                }
            }

            if (add)
            {
                stack.push_back(robot);
            }
        }
    }

    vector<int> result;
    sort(stack.begin(), stack.end(), [](vector<int> &a, vector<int> &b)
         { return a[3] < b[3]; });

    for (auto &robot : stack)
    {
        result.push_back(robot[1]);
    }

    return result;
}
