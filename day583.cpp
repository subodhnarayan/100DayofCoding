-- -- -- -- -- -- -- -- -GFG - POTD - 03/ 07 / 2025 ----------------------------------------


Longest Substring with K Uniques
Difficulty: MediumAccuracy: 34.65%Submissions: 208K+Points: 4
You are given a string s consisting only lowercase alphabets and an integer k. Your task is to find the length of the longest substring that contains exactly k distinct characters.

Note : If no such substring exists, return -1. 

Examples:

Input: s = "aabacbebebe", k = 3
Output: 7
Explanation: The longest substring with exactly 3 distinct characters is "cbebebe", which includes 'c', 'b', and 'e'.
Input: s = "aaaa", k = 2
Output: -1
Explanation: There's no substring with 2 distinct characters.
Input: s = "aabaaab", k = 2
Output: 7
Explanation: The entire string "aabaaab" has exactly 2 unique characters 'a' and 'b', making it the longest valid substring.
Constraints:
1 ≤ s.size() ≤ 105
1 ≤ k ≤ 26

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)





-- -- -- -- -- -- -- -- -Leetcode - POTD - 03/ 07 / 2025 ----------------------------------------

