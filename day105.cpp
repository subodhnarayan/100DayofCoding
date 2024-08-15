- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 14 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Add 1 to a Linked List Number
Difficulty: MediumAccuracy: 31.91%Submissions: 226K+Points: 4
You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
Input: LinkedList: 1->2->3
Output: 124
 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= len(list) <= 105
0 <= list[i] <= 9

class Solution {
  public:  Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* nex = NULL;
        while(curr != NULL){
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
    
    void addone(Node* head1){
        
        Node* head = head1;
        Node* prev = head;
        while(head != NULL && head->data == 9 ){
            head->data = 0;
            prev= head;
            head = head->next;
            
        }

        if(prev -> next == NULL && prev->data == 0){
            Node* node = new Node(1);
            prev->next = node;
        }
        else{
            head->data += 1;
        }
        
    }
    
    Node* addOne(Node* head) {
          if(head == NULL){
            return head;
        }
        head = reverse(head);
        int last = head->data;
        
        if(last < 9){
            head->data += 1;
            return reverse(head);
        }
        else{
            addone(head);
        }
        
        return reverse(head);;
    }
