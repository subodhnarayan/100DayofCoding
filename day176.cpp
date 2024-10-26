-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 26 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Occurence of an integer in a Linked List
Difficulty: EasyAccuracy: 80.07%Submissions: 74K+Points: 2
Given a singly linked list and a key, count the number of occurrences of the given key in the linked list.

Examples:

Input: Linked List: 1->2->1->2->1->3->1, key = 1

Output: 4
Explanation: 1 appears 4 times. 
Input: Linked List: 1->2->1->2->1, key = 3

Output: 0
Explanation: 3 appears 0 times.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ number of nodes, key ≤ 105
1 ≤ data of node ≤ 105

class Solution {
  public:
    int count(struct Node* head, int key) {
        
        int count=0;
        Node* curr=head;
        while(curr){
            if(curr->data==key){
                count++;
            }
            curr=curr->next;
        }
        return count;
    }
};