-- -- -- -- -- -- -- -- -GFG - POTD - 17 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

k largest elements
Difficulty: MediumAccuracy: 53.56%Submissions: 179K+Points: 4
Given an array arr[] of positive integers and an integer k, Your task is to return k largest elements in decreasing order. 

Examples:

Input: arr[] = [12, 5, 787, 1, 23], k = 2
Output: [787, 23]
Explanation: 1st largest element in the array is 787 and second largest is 23.
Input: arr[] = [1, 23, 12, 9, 30, 2, 50], k = 3 
Output: [50, 30, 23]
Explanation: Three Largest elements in the array are 50, 30 and 23.
Input: arr[] = [12, 23], k = 1
Output: [23]
Explanation: 1st Largest element in the array is 23.
Constraints:
1 ≤ k ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
 
Time Complexity: k+(n-k)*logkAuxiliary Space: k+(n-k)*logk

-- -- -- -- -- -- -- -- -LeetCode - POTD - 17 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

1079. Letter Tile Possibilities
Solved
Medium
Topics
Companies
Hint
You have n  tiles, where each tile has one letter tiles[i] printed on it.

Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.

 

Example 1:

Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
Example 2:

Input: tiles = "AAABBC"
Output: 188
Example 3:

Input: tiles = "V"
Output: 1
 

Constraints:

1 <= tiles.length <= 7
tiles consists of uppercase English letters.


class Solution {
    public:
        int numTilePossibilities(string tiles) {
            int n = tiles.length();
            std::vector<int> counts(26, 0);
            std::vector<int> fac(n + 1, 1);
            for (int i = 1; i <= n; i++) {
                fac[i] = i * fac[i - 1];
            }
            for (char c : tiles) {
                counts[c - 'A']++;
            }
            std::vector<int> lengthcounts(n + 1, 0);
            lengthcounts[0] = 1;
            for (int i = 0; i < 26; i++) {
                if (counts[i] > 0) {
                    std::vector<int> temp(n + 1, 0);
                    for (int j = 0; j <= n && lengthcounts[j] > 0; j++) {
                        for (int k = 1; k <= counts[i]; k++) {
                            int totallength = j + k;
                            temp[totallength] += lengthcounts[j] * fac[totallength] / (fac[k] * fac[j]);
                        }
                    }
                    for (int j = 0; j <= n; j++) {
                        lengthcounts[j] += temp[j];
                    }
                }
            }
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                ans += lengthcounts[i];
            }
            return ans;
        }
};
