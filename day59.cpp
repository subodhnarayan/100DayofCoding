// Delete node in Doubly Linked List
// Difficulty: EasyAccuracy: 42.98%Submissions: 111K+Points: 2
// Given a doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

// Examples:

// Input: LinkedList = 1 <--> 3 <--> 4, x = 3
// Output: 1 3
// Explanation:
// After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.

// Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
// Output: 5 2 9
// Explanation:

// Expected Time Complexity: O(n)
// Expected Auxilliary Space: O(1)

// Constraints:
// 2 <= size of the linked list(n) <= 105
// 1 <= x <= n
// 1 <= node.data <= 109

class Solution
{
public:
    Node *deleteNode(Node *head, int x)
    {
        if (x == 1)
        {
            head->next->prev = NULL;
            return head->next;
        }
        Node *curr = head;
        for (int i = 1; i < x; i++)
        {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        if (curr->next != NULL)
            curr->next->prev = curr->prev;
        return head;
    }
};