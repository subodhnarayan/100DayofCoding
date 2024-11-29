-- -- -- -- -- -- -- -- -GFG - POTD - 28 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Implement Atoi
Difficulty: MediumAccuracy: 32.58%Submissions: 233K+Points: 4
Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.

Cases for atoi() conversion:

Skip any leading whitespaces.
Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.
Examples:

Input: s = "-123"
Output: -123
Explanation: It is possible to convert -123 into an integer so we returned in the form of an integer
Input: s = "  -"
Output: 0
Explanation: No digits are present, therefore the returned answer is 0.
Input: s = " 1231231231311133"
Output: 2147483647
Explanation: The converted number will be greater than 231 – 1, therefore print 231 – 1 = 2147483647.
Input: s = "-999999999999"
Output: -2147483648
Explanation: The converted number is smaller than -231, therefore print -231 = -2147483648.
Input: s = "  -0012gfg4"
Output: -12
Explanation: Nothing is read after -12 as a non-digit character ‘g’ was encountered.
Constraints:
1 ≤ |s| ≤ 15


class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
     long long ans = 0;
        int i = 0, n = strlen(s);
        int sign = 1; // Default to positive

        // Skip leading spaces
        while (i < n && (s[i]==' ' || s[i]=='0')) i++;

        // Handle sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Process digits
        while (i < n && s[i]>='0' && s[i]<='9' ) {
            ans = ans * 10 + (s[i] - '0');

            // Check for overflow
            if (ans * sign > INT_MAX) return INT_MAX;
            if (ans * sign < INT_MIN) return INT_MIN;

            i++;
        }

        return ans * sign;
    }
};






-- -- -- -- -- -- -- -- -Leetcode - POTD - 28 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;

        distance[0][0] = 0;
        dq.push_front({0, 0});
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newDist = distance[x][y] + grid[nx][ny];
                    if (newDist < distance[nx][ny]) {
                        distance[nx][ny] = newDist;
                        if (grid[nx][ny] == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }
        return distance[m-1][n-1];
    }
};




