-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 3 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Is Linked List Length Even?
Difficulty: BasicAccuracy: 71.58%Submissions: 86K+Points: 1
Given a linked list, your task is to complete the function isLengthEven() which contains the head of the linked list, and check whether the length of the linked list is even or not. Return true if it is even, otherwise false.

Examples:

Input: Linked list: 12->52->10->47->95->0

Output: true
Explanation: The length of the linked list is 6 which is even, hence returned true.
Input: Linked list: 9->4->3 

Output: false
Explanation: The length of the linked list is 3 which is odd, hence returned false.
Expected Time Complexity: O(n)
Expected Auxillary Space: O(1)

Constraints:
1 <= number of nodes <= 105
1 <= elements of the linked list <= 105

class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        // Code here
        int count = 0;
        Node *curr = *head; // dereference the double pointer to get the actual head
        
        while (curr) {
            curr = curr->next;
            count++;
        }
        // Return true if count is even, else false
        return count % 2 == 0;
    }
};

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -LeetCode - POTD - 3 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
796. Rotate String
Solved
Easy
Topics
Companies
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.


class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        return (s + s).find(goal) != string::npos;
    }
=======
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 3 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Is Linked List Length Even?
Difficulty: BasicAccuracy: 71.58%Submissions: 86K+Points: 1
Given a linked list, your task is to complete the function isLengthEven() which contains the head of the linked list, and check whether the length of the linked list is even or not. Return true if it is even, otherwise false.

Examples:

Input: Linked list: 12->52->10->47->95->0

Output: true
Explanation: The length of the linked list is 6 which is even, hence returned true.
Input: Linked list: 9->4->3 

Output: false
Explanation: The length of the linked list is 3 which is odd, hence returned false.
Expected Time Complexity: O(n)
Expected Auxillary Space: O(1)

Constraints:
1 <= number of nodes <= 105
1 <= elements of the linked list <= 105

class Solution {
  public:
    bool isLengthEven(struct Node **head) {
        // Code here
        int count = 0;
        Node *curr = *head; // dereference the double pointer to get the actual head
        
        while (curr) {
            curr = curr->next;
            count++;
        }
        // Return true if count is even, else false
        return count % 2 == 0;
    }
};

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -LeetCode - POTD - 3 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
796. Rotate String
Solved
Easy
Topics
Companies
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true

Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 

Constraints:

1 <= s.length, goal.length <= 100
s and goal consist of lowercase English letters.


class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        return (s + s).find(goal) != string::npos;
    }
>>>>>>> 1d6f44044e1c3760e347f581317621322d435e10
};