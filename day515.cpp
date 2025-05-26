-- -- -- -- -- -- -- -- -GFG - POTD - 26 / 05 / 2025 ----------------------------------------

Insert in Sorted Circular Linked List
Difficulty: MediumAccuracy: 25.56%Submissions: 133K+Points: 4Average Time: 20m
Given a sorted circular linked list, the task is to insert a new node in this circular linked list so that it remains a sorted circular linked list.

Examples:

Input: head = 1->2->4, data = 2
Output: 1->2->2->4
Explanation: We can add 2 after the second node.

Input: head = 1->4->7->9, data = 5
Output: 1->4->5->7->9
Explanation: We can add 5 after the second node.

Constraints:
2 <= number of nodes <= 106
0 <= node->data <= 106
0 <= data <= 106

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        Node* tail=head;
        while(tail->next!=head) tail=tail->next;
        
        if(data<head->data){
            Node* node=new Node(data);
            node->next=head;
            tail->next=node;
            return node;
        }
        
        if(data>tail->data){
            Node* node=new Node(data);
            tail->next=node;
            node->next=head;
            return head;
        }
        
        Node* temp=head;
        Node* prev=NULL;
        while(data>temp->data){
            prev=temp;
            temp=temp->next;
        }
        
          Node* node=new Node(data);
          prev->next=node;
          node->next=temp;
          return head;
    }
};




-- -- -- -- -- -- -- -- -Leetcode - POTD - 26 / 05 / 2025 ----------------------------------------
