-- -- -- -- -- -- -- -- -GFG - POTD - 18 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Reverse a linked list
Difficulty: EasyAccuracy: 73.11%Submissions: 327K+Points: 2
Given the head of a linked list, the task is to reverse this list and return the reversed head.

Examples:

Input: head: 1 -> 2 -> 3 -> 4 -> NULL
Output: head: 4 -> 3 -> 2 -> 1 -> NULL
Explanation:

Input: head: 2 -> 7 -> 10 -> 9 -> 8 -> NULL
Output: head: 8 -> 9 -> 10 -> 7 -> 2 -> NULL
Explanation:

Input: head: 2 -> NULL
Output: 2 -> NULL
Explanation:

Constraints:
1 <= number of nodes, data of nodes <= 105

Time Complexity: O(n)Auxiliary Space: O(1)


class Solution {
  public:
    Node* reverseList(struct Node* head) {
        Node * prev=NULL;
        Node* curr=head;
        while(curr->next!=NULL){
            
        }
    }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 18 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
