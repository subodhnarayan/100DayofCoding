-- -- -- -- -- -- -- -- -GFG - POTD - 07 / 06 / 2025 ----------------------------------------
Longest Span in two Binary Arrays
Difficulty: MediumAccuracy: 48.22%Submissions: 20K+Points: 4
Given two binary arrays, a1[] and a2[]. Find the length of longest common span (i, j) where j>= i such that a1[i] + a1[i+1] + .... + a1[j] =  a2[i] + a2[i+1] + ... + a2[j].

Examples:

Input: a1[] = [0, 1, 0, 0, 0, 0], a2[] = [1, 0, 1, 0, 0, 1]
Output: 4
Explanation: The longest span with same sum is from index 1 to 4 following zero based indexing.
Input: a1[] = [0, 1, 0, 1, 1, 1, 1], a2[] = [1, 1, 1, 1, 1, 0, 1]
Output: 6
Explanation: The longest span with same sum is from index 1 to 6 following zero based indexing.
Constraints:
1 <= a1.size() = a2.size() <= 106
0 <= a1[i], a2[i] <= 1

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)


-- -- -- -- -- -- -- -- -Leetcode - POTD - 07 / 06 / 2025 ----------------------------------------

