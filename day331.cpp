-- -- -- -- -- -- -- -- -GFG - POTD - 23 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Total Decoding Messages
Difficulty: MediumAccuracy: 15.79%Submissions: 147K+Points: 4Average Time: 20m
A message containing letters A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

You are given a string digits. You have to determine the total number of ways that message can be decoded.

Examples:

Input: digits = "123"
Output: 3
Explanation: "123" can be decoded as "ABC"(1, 2, 3), "LC"(12, 3) and "AW"(1, 23).
Input: digits = "90"
Output: 0
Explanation: "90" cannot be decoded, as it's an invalid string and we cannot decode '0'.
Input: digits = "05"
Output: 0
Explanation: "05" cannot be mapped to "E" because of the leading zero ("5" is different from "05"), the string is not a valid encoding message.
Constraints:
1 ≤ digits.size() ≤ 103



-- -- -- -- -- -- -- -- -LeetCode - POTD - 23 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


