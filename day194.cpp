-- -- -- -- -- -- -- -- -GFG - POTD - 13 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


Intersection Point in Y Shaped Linked Lists
Difficulty: MediumAccuracy: 44.67%Submissions: 289K+Points: 4
Given two singly linked lists, return the point where two linked lists intersect.

Note: If the linked lists do not merge at any point, return -1.

Examples:

Input: Linked list 1: 4->4->4->4->4, Linked list 2: 4->4->4
 
Output: 4
Explanation: From the above image, it is clearly seen that the common part is 4->4 whose starting point is 4.

Input: Linked list 1: 4->1->8->4->5, Linked List 2: 5->6->1->8->4->5
 
Output: 8
Explanation: From the above image, it is clearly seen that the common part is 8->4->5 whose starting point is 8.
Input: Linked list 1: 1->2->3, Linked list 2: 4->5->6
Output: -1
Explanation: There is no common part, so there is no interaction point.
Try to solve the problem without using any extra space.

Constraints:
2 ≤ size of first linkedist + size of second linkedlist ≤ 2*105
-10000 ≤ data of nodes ≤ 10000

class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
         if (!head1 || !head2) return -1;  // No intersection if one list is empty
    
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    
    while (ptr1 != ptr2) {
        ptr1 = (ptr1 == nullptr) ? head2 : ptr1->next;
        ptr2 = (ptr2 == nullptr) ? head1 : ptr2->next;
    }
    
    // ptr1 (or ptr2) will be nullptr if there's no intersection, or the intersection node otherwise.
    return (ptr1 ? ptr1->data : -1);
    }
};
