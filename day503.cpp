-- -- -- -- -- -- -- -- -GFG - POTD - 14 / 05 / 2025 ----------------------------------------
Look and Say Pattern
Difficulty: MediumAccuracy: 62.54%Submissions: 42K+Points: 4
Given an integer n. Return the nth row of the following look-and-say pattern.
1
11
21
1211
111221
Look-and-Say Pattern:

To generate a member of the sequence from the previous member, read off the digits of the previous member, counting the number of digits in groups of the same digit. For example:

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
1211 is read off as "one 1, one 2, then two 1s" or 111221.
111221 is read off as "three 1s, two 2s, then one 1" or 312211.
Examples:

Input: n = 5
Output: 111221
Explanation: The 5th row of the given pattern will be 111221.
Input: n = 3
Output: 21
Explanation: The 3rd row of the given pattern will be 21.

Constraints:
1 ≤ n ≤ 30

Expected Complexities
Time Complexity: O(2^n)
Auxiliary Space: O(2^n)
-- -- -- -- -- -- -- -- -Leetcode - POTD - 14 / 05 / 2025 ----------------------------------------
