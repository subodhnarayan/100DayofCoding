-- -- -- -- -- -- -- -- -GFG - POTD - 21 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Add Number Linked Lists
Difficulty: MediumAccuracy: 34.52%Submissions: 314K+Points: 4
Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.

For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.

Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

Examples:

Input: num1 = 4 - > 5, num2 = 3 -> 4 -> 5
Output:  3 -> 9 -> 0
 
Explanation: Given numbers are 45 and 345. There sum is 390.
Input: num1 = 0 -> 0 -> 6 -> 3, num2 = 0 -> 7 
Output: 7 -> 0 
 
Explanation: Given numbers are 63 and 7. There sum is 70.
Constraints:
1 <= size of both linked lists <= 106
0 <= elements of both linked lists <= 9


Node* reverse(Node* head){
        Node* prev=NULL;
        Node* curr=head;
        Node* temp;
        while(curr!=NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }

class Solution {
  public:
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
          Node* first=reverse(num1);
        Node* sec=reverse(num2);
        Node * temp=new Node(0);
        Node* res=temp;
        int carry=0;
        while(first!=NULL && sec!=NULL){
            int sum=first->data+sec->data+carry;
            carry = sum/10;
            sum = sum%10;
            res->next = new Node(sum);
            res=res->next;
            first=first->next;
            sec=sec->next;
        }
        
        while(first!=NULL){
            int sum=first->data+carry;
            carry = sum/10;
            sum = sum%10;
            res->next = new Node(sum);
            res=res->next;
            first=first->next;
        }
         while(sec!=NULL){
            int sum=sec->data+carry;
            carry = sum/10;
            sum = sum%10;
            res->next = new Node(sum);
            res=res->next;
            sec=sec->next;
        }
        if(carry != 0){
            res->next = new Node(carry);
            res=res->next;
        }
        Node* final = reverse(temp->next);
        while(final->data == 0){
            final= final->next;
        }
        return final;
    }
};




-- -- -- -- -- -- -- -- -LeetCode - POTD - 21 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

