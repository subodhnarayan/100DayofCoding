-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 13 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Delete Alternate Nodes
Difficulty: EasyAccuracy: 56.09%Submissions: 81K+Points: 2
Given a Singly Linked List, Delete all alternate nodes of the list ie delete all the nodes present in even positions.

Examples :

Input: LinkedList: 1->2->3->4->5->6
 
Output: 1->3->5

Explanation: Deleting alternate nodes ie 2, 4, 6 results in the linked list with elements 1->3->5.
Input: LinkedList: 99->59->42->20
 
Output: 99->42
 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 103

class Solution {
  public:
    void deleteAlt(struct Node *head) {
      if(head==NULL) return;
      Node* curr=head;
      while(curr && curr->next){
          Node* temp=curr->next;
          curr->next=temp->next;
          delete temp;
          curr=curr->next;
      }
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 13 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


632. Smallest Range Covering Elements from K Lists
Solved
Hard
Topics
Companies
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.

