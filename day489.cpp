-- -- -- -- -- -- -- -- -GFG - POTD - 30 / 04 / 2025 -----------------------------------

Find length of Loop
Difficulty: EasyAccuracy: 44.26%Submissions: 252K+Points: 2Average Time: 30m
Given the head of a linked list, determine whether the list contains a loop. If a loop is present, return the number of nodes in the loop, otherwise return 0.

Note: 'c' is the position of the node which is the next pointer of the last node of the linkedlist. If c is 0, then there is no loop.

Examples:

Input: head: 1 → 2 → 3 → 4 → 5, c = 2
Output: 4
Explanation: There exists a loop in the linked list and the length of the loop is 4.

Input: head: 25 → 14 → 19 → 33 → 10 → 21 → 39 → 90 → 58 → 45, c = 4
Output: 7
Explanation: The loop is from 33 to 45. So length of loop is 33 → 10 → 21 → 39 → 90 → 58 → 45 = 7.
The number 33 is connected to the last node of the linkedlist to form the loop because according to the input the 4th node from the beginning(1 based indexing) 
will be connected to the last node in the LinkedList.

Input: head: 0 → 1 → 2 → 3, c = 0
Output: 0
Explanation: There is no loop.

Constraints:
1 ≤ no. of nodes ≤ 106
0 ≤ node.data ≤ 106
0 ≤ c ≤ n-1

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

class Solution {
    public:
      // Function to find the length of a loop in the linked list.
      int countNodesinLoop(Node *head) {
          // Code here
          unordered_map<Node*, int> mp;
          Node* ptr = head;
          while(ptr){
              if(mp[ptr]) break;
              mp[ptr] = ptr->data;
              ptr = ptr -> next;
          }
          int len = 0;
          if(ptr){
              Node* ptr2 = ptr;
              while(ptr2){
                  ptr2 = ptr2 -> next;
                  len++;
                  if(ptr2 == ptr) break;
              }
          }
          return len;
      }
  };

-- -- -- -- -- -- -- -- -Leetcode - POTD - 30 / 04 / 2025 -----------------------------------


1295. Find Numbers with Even Number of Digits
Solved
Easy
Topics
Companies
Hint
Given an array nums of integers, return how many of them contain an even number of digits.

 

Example 1:

Input: nums = [12,345,2,6,7896]
Output: 2
Explanation: 
12 contains 2 digits (even number of digits). 
345 contains 3 digits (odd number of digits). 
2 contains 1 digit (odd number of digits). 
6 contains 1 digit (odd number of digits). 
7896 contains 4 digits (even number of digits). 
Therefore only 12 and 7896 contain an even number of digits.
Example 2:

Input: nums = [555,901,482,1771]
Output: 1 
Explanation: 
Only 1771 contains an even number of digits.
 

Constraints:

1 <= nums.length <= 500
1 <= nums[i] <= 105

class Solution {
    public:
         bool hasEvenDigits(int num) {
            int digitCount = 0;
            while (num) {
                digitCount++;
                num /= 10;
            }
            return (digitCount & 1) == 0;
        }
        int findNumbers(vector<int>& nums) {
            int evenDigitCount = 0;
    
            for (int num : nums) {
                if (hasEvenDigits(num))
                    evenDigitCount++;
            }
    
            return evenDigitCount;
        }
    };