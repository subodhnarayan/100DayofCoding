-- -- -- -- -- -- -- -- -GFG - POTD - 27/ 06 / 2025 ----------------------------------------

Mobile numeric keypad
Difficulty: MediumAccuracy: 32.6%Submissions: 66K+Points: 4Average Time: 30m
There is a standard numeric keypad on a mobile phone. You can press the current button or any button that is directly above, below, to the left, or to the right of it. For example, if you press 5, then pressing 2, 4, 6, or 8 is allowed. However, diagonal movements and pressing the bottom row corner buttons (* and #) are not allowed.


Given an integer n, determine how many unique sequences of length n can be formed by pressing buttons on the keypad, starting from any digit.

Examples :

Input: n = 1
Output: 10
Explanation: Possible 1-digit numbers follow keypad moves - From 0 → 0, 1 → 1, 2 → 2 and so on, total 10 valid combinations are possible.
Input: n = 2
Output: 36
Explanation: Possible 2-digit numbers follow keypad moves -
From 0 → 00, 08 (2), 
From 1 → 11, 12, 14 (3),
From 3 → 33, 32, 36 (3), and so on,
total 36 valid combinations are possible.
Constraints:
1 ≤ n ≤ 15

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)




-- -- -- -- -- -- -- -- -Leetcode - POTD - 27 / 06 / 2025 ----------------------------------------
