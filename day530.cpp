-- -- -- -- -- -- -- -- -GFG - POTD - 11 / 06 / 2025 ----------------------------------------

Remove the balls
Difficulty: MediumAccuracy: 58.66%Submissions: 37K+Points: 4
You are given two arrays, color and radius, representing a sequence of balls:


color[i] is the color of the i-th ball.
radius[i] is the radius of the i-th ball.

If two consecutive balls have the same color and radius, remove them both. Repeat this process until no more such pairs exist.


Return the number of balls remaining after all possible removals.

Examples:

Input: color[] = [2, 3, 5], radius[] = [3, 3, 5]
Output: 3
Explanation: All the 3 balls have different colors and radius.
Input: color[] = [2, 2, 5], radius[] = [3, 3, 5]
Output: 1
Explanation: First ball and second ball have same color 2 and same radius 3. So, after removing only one ball is left. It cannot be removed from the array. Hence, the final array has length 1.
Constraints:
1 ≤ color.size() = radius.size() ≤ 105
1 ≤ color[i] ≤ 109
1 ≤ radius[i] ≤ 109                                                                                                                                           

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int,int>>s;
        for(int i = 0;i<color.size();i++){
            if(!s.empty() && s.top().first==color[i] && s.top().second==radius[i]){
                s.pop();
            }
            else s.push({color[i],radius[i]});
        }
        return s.size();
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 11 / 06 / 2025 ----------------------------------------




3445. Maximum Difference Between Even and Odd Frequency II
Solved
Hard
Topics
premium lock icon
Companies
Hint
You are given a string s and an integer k. Your task is to find the maximum difference between the frequency of two characters, freq[a] - freq[b], in a substring subs of s, such that:

subs has a size of at least k.
Character a has an odd frequency in subs.
Character b has an even frequency in subs.
Return the maximum difference.

Note that subs can contain more than 2 distinct characters.

 

Example 1:

Input: s = "12233", k = 4

Output: -1

Explanation:

For the substring "12233", the frequency of '1' is 1 and the frequency of '3' is 2. The difference is 1 - 2 = -1.

Example 2:

Input: s = "1122211", k = 3

Output: 1

Explanation:

For the substring "11222", the frequency of '2' is 3 and the frequency of '1' is 2. The difference is 3 - 2 = 1.

Example 3:

Input: s = "110", k = 3

Output: -1

 

Constraints:

3 <= s.length <= 3 * 104
s consists only of digits '0' to '4'.
The input is generated that at least one substring has a character with an even frequency and a character with an odd frequency.
1 <= k <= s.length

class Solution {
public:
    int maxDifference(string s, int k) {
        auto getStatus = [](int cnt_a, int cnt_b) -> int {
            return ((cnt_a & 1) << 1) | (cnt_b & 1);
        };

        int n = s.size();
        int ans = INT_MIN;
        for (char a = '0'; a <= '4'; ++a) {
            for (char b = '0'; b <= '4'; ++b) {
                if (a == b) {
                    continue;
                }
                int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int cnt_a = 0, cnt_b = 0;
                int prev_a = 0, prev_b = 0;
                int left = -1;
                for (int right = 0; right < n; ++right) {
                    cnt_a += (s[right] == a);
                    cnt_b += (s[right] == b);
                    while (right - left >= k && cnt_b - prev_b >= 2) {
                        int left_status = getStatus(prev_a, prev_b);
                        best[left_status] =
                            min(best[left_status], prev_a - prev_b);
                        ++left;
                        prev_a += (s[left] == a);
                        prev_b += (s[left] == b);
                    }
                    int right_status = getStatus(cnt_a, cnt_b);
                    if (best[right_status ^ 0b10] != INT_MAX) {
                        ans =
                            max(ans, cnt_a - cnt_b - best[right_status ^ 0b10]);
                    }
                }
            }
        }
        return ans;
    }
};