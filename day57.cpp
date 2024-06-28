// GFG POTD 6/28/2024

// The Palindrome Pattern
// Difficulty: HardAccuracy: 55.18%Submissions: 21K+Points: 8
// Given a two-dimensional integer array arr of dimensions n x n, consisting solely of zeros and ones, identify the row or column (using 0-based indexing) where all elements form a palindrome. If multiple palindromes are identified, prioritize the palindromes found in rows over those in columns. Within rows or columns, the palindrome with the smaller index takes precedence. The result should be represented by the index followed by either 'R' or 'C', indicating whether the palindrome was located in a row or column. The output should be space-separated. If no palindrome is found, return the string -1.

// Examples:

// Input:
// arr[][] =  [[1, 0, 0],
//            [0, 1, 0],
//            [1, 1, 0]]
// Output: 1 R
// Explanation: In the first test case, 0-1-0 is a palindrome
// occuring in a row having index 1.
// Input:
// arr[][] =   [[1, 0],
//            [1, 0]]
// Output: 0 C
// Explanation: 1-1 occurs before 0-0 in the 0th column. And there is no palindrome in the two rows.
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1<= arr.size <= 50
// 0 <= arr[i][j] <= 1

class Solution
{
public:
    string pattern(vector<vector<int>> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int start = 0;
            int end = n - 1;
            bool ch = true;
            while (start < end)
            {
                if (arr[i][start] != arr[i][end])
                {
                    ch = false;
                    break;
                }
                start++;
                end--;
            }
            if (ch == true)
            {
                string ans = to_string(i) + " " + "R";
                return ans;
            }
        }

        for (int i = 0; i < n; i++)
        {
            int start = 0;
            int end = n - 1;
            bool ch = true;
            while (start < end)
            {
                if (arr[start][i] != arr[end][i])
                {
                    ch = false;
                    break;
                }
                start++;
                end--;
            }
            if (ch == true)
            {
                string ans = to_string(i) + " " + "C";
                return ans;
            }
        }

        return "-1";
    }
};

// #Leetcode POTD
// 2285. Maximum Total Importance of Roads
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.

// You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

// You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.

// Return the maximum total importance of all roads possible after assigning the values optimally.

// Example 1:

// Input: n = 5, roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
// Output: 43
// Explanation: The figure above shows the country and the assigned values of [2,4,5,3,1].
// - The road (0,1) has an importance of 2 + 4 = 6.
// - The road (1,2) has an importance of 4 + 5 = 9.
// - The road (2,3) has an importance of 5 + 3 = 8.
// - The road (0,2) has an importance of 2 + 5 = 7.
// - The road (1,3) has an importance of 4 + 3 = 7.
// - The road (2,4) has an importance of 5 + 1 = 6.
// The total importance of all roads is 6 + 9 + 8 + 7 + 7 + 6 = 43.
// It can be shown that we cannot obtain a greater total importance than 43.
// Example 2:

// Input: n = 5, roads = [[0,3],[2,4],[1,3]]
// Output: 20
// Explanation: The figure above shows the country and the assigned values of [4,3,2,5,1].
// - The road (0,3) has an importance of 4 + 5 = 9.
// - The road (2,4) has an importance of 2 + 1 = 3.
// - The road (1,3) has an importance of 3 + 5 = 8.
// The total importance of all roads is 9 + 3 + 8 = 20.
// It can be shown that we cannot obtain a greater total importance than 20.

// Constraints:

// 2 <= n <= 5 * 104
// 1 <= roads.length <= 5 * 104
// roads[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no duplicate roads.

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        // n = total number of nodes numbered from 0 to n-1

        vector<int> degree(n, 0);

        for (auto &vec : roads)
        {
            int u = vec[0];
            int v = vec[1];

            degree[u]++;
            degree[v]++;
        }

        sort(begin(degree), end(degree)); // ascedning order

        long long value = 1;
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += (degree[i] * value);
            value++;
        }

        return sum;
    }
};