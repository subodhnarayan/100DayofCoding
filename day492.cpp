-- -- -- -- -- -- -- -- -GFG - POTD - 03 / 05 / 2025 -----------------------------------

Prime List
Difficulty: MediumAccuracy: 53.68%Submissions: 39K+Points: 4
You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one. Return the head of the modified linked list.

Examples :

Input: head = 2 → 6 → 10
Output: 2 → 5 → 11

Explanation: The nearest prime of 2 is 2 itself. The nearest primes of 6 are 5 and 7, since 5 is smaller so, 5 will be chosen. The nearest prime of 10 is 11.
Input: head = 1 → 15 → 20
Output: 2 → 13 → 19

Explanation: The nearest prime of 1 is 2. The nearest primes of 15 are 13 and 17, since 13 is smaller so, 13 will be chosen. The nearest prime of 20 is 19.
Constraints:
1 <= no. of Nodes <= 104
1 <= node.val <= 104

Expected Complexities
Time Complexity: O(n * sqrt(node.val))
Auxiliary Space: O(1)



-- -- -- -- -- -- -- -- -Leetcode - POTD - 03 / 05 / 2025 -----------------------------------

