// Maximum product subset of an array
// Difficulty: MediumAccuracy: 17.21%Submissions: 68K+Points: 4
// Given an array arr. The task is to find and return the maximum product possible with the subset of elements present in the array.

// Note:

// The maximum product can be a single element also.
// Since the product can be large, return it modulo 109 + 7.
// Examples:

// Input: arr[] = [-1, 0, -2, 4, 3]
// Output: 24
// Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24
// Input: arr[] = [-1, 0]
// Output: 0
// Explanation: Maximum product will be ( -1 * 0) = 0
// Input: arr[] = [5]
// Output: 5
// Explanation: Maximum product will be 5.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= arr.size() <= 2 * 104
// -10 <= arr[i] <= 10

class Solution
{
public:
    long long int findMaxProduct(vector<int> &arr)
    {
        int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        long long ans = 0;

        int n = arr.size();
        if (n == 1)
            return arr[0];
        int i = n - 1;
        for (; i >= 0; i--)
        {
            if (arr[i] < 0)
                break;
            if (arr[i] == 0)
                continue;

            if (ans == 0)
                ans += arr[i];
            else
                ans = (ans * arr[i]) % mod;
        }

        if ((i + 1) % 2 != 0)
            i--;

        while (i >= 0)
        {
            if (ans == 0)
                ans += abs(arr[i]);
            else
                ans = (ans * abs(arr[i])) % mod;
            i--;
        }

        return ans;
    }
};

// 2392. Build a Matrix With Conditions
// Solved
// Hard
// Topics
// Companies
// Hint
// You are given a positive integer k. You are also given:

// a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
// a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
// The two arrays contain integers from 1 to k.

// You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

// The matrix should also satisfy the following conditions:

// The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
// The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
// Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

// Example 1:

// Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
// Output: [[3,0,0],[0,0,1],[0,2,0]]
// Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
// The row conditions are the following:
// - Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
// - Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
// The column conditions are the following:
// - Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
// - Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
// Note that there may be multiple correct answers.
// Example 2:

// Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
// Output: []
// Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
// No matrix can satisfy all the conditions, so we return the empty matrix.

// Constraints:

// 2 <= k <= 400
// 1 <= rowConditions.length, colConditions.length <= 104
// rowConditions[i].length == colConditions[i].length == 2
// 1 <= abovei, belowi, lefti, righti <= k
// abovei != belowi
// lefti != righti

class Solution
{
public:
    vector<int> topoSort(vector<vector<int>> &graph, int k)
    {
        vector<int> inDegree(k + 1, 0), order;
        queue<int> q;
        for (int i = 1; i <= k; ++i)
        {
            for (int j : graph[i])
            {
                ++inDegree[j];
            }
        }
        for (int i = 1; i <= k; ++i)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            order.push_back(node);
            for (int adj : graph[node])
            {
                if (--inDegree[adj] == 0)
                    q.push(adj);
            }
        }
        return order.size() == k ? order : vector<int>();
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        vector<vector<int>> rowGraph(k + 1), colGraph(k + 1);
        for (auto &rc : rowConditions)
        {
            rowGraph[rc[0]].push_back(rc[1]);
        }
        for (auto &cc : colConditions)
        {
            colGraph[cc[0]].push_back(cc[1]);
        }

        vector<int> rowOrder = topoSort(rowGraph, k);
        vector<int> colOrder = topoSort(colGraph, k);

        if (rowOrder.empty() || colOrder.empty())
            return {};

        vector<vector<int>> result(k, vector<int>(k, 0));
        unordered_map<int, int> rowMap, colMap;
        for (int i = 0; i < k; ++i)
        {
            rowMap[rowOrder[i]] = i;
            colMap[colOrder[i]] = i;
        }

        for (int i = 1; i <= k; ++i)
        {
            result[rowMap[i]][colMap[i]] = i;
        }

        return result;
    }
};