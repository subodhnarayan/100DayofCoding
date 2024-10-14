-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 14 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Count Linked List Nodes
Difficulty: BasicAccuracy: 85.99%Submissions: 211K+Points: 1
Given a singly linked list. The task is to find the length of the linked list, where length is defined as the number of nodes in the linked list.

Examples :

Input: LinkedList : 1->2->3->4->5

Output: 5
Explanation: Count of nodes in the linked list is 5, which is its length.
Input: LinkedList : 2->4->6->7->5->1->0
 
Output: 7
Explanation: Count of nodes in the linked list is 7. Hence, the output is 7.
Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)

Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 103

class Solution {
  public:
    // Function to count nodes of a linked list.
    int getCount(struct Node* head) {
        int count=0;
        Node* curr=head;
        while(curr){
            count++;
            curr=curr->next;
        }
        return count;
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 14 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


2530. Maximal Score After Applying K Operations
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.

In one operation:

choose an index i such that 0 <= i < nums.length,
increase your score by nums[i], and
replace nums[i] with ceil(nums[i] / 3).
Return the maximum possible score you can attain after applying exactly k operations.

The ceiling function ceil(val) is the least integer greater than or equal to val.

 

Example 1:

Input: nums = [10,10,10,10,10], k = 5
Output: 50
Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.
Example 2:

Input: nums = [1,10,3,3,3], k = 3
Output: 17
Explanation: You can do the following operations:
Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases by 10.
Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases by 4.
Operation 3: Select i = 2, so nums becomes [1,1,1,3,3]. Your score increases by 3.
The final score is 10 + 4 + 3 = 17.
 

Constraints:

1 <= nums.length, k <= 105
1 <= nums[i] <= 109