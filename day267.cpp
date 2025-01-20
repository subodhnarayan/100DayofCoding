-- -- -- -- -- -- -- -- -GFG - POTD - 21 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Merge two sorted linked lists
Difficulty: MediumAccuracy: 62.91%Submissions: 174K+Points: 4
Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the sorted merged list.

Examples:

Input: head1 = 5 -> 10 -> 15 -> 40, head2 = 2 -> 3 -> 20
Output: 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40
Explanation:

Input: head1 = 1 -> 1, head2 = 2 -> 4
Output: 1 -> 1 -> 2 -> 4
Explanation:

Constraints:
1 <= no. of nodes<= 103
0 <= node->data <= 105

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        int m=0;
        int n=0;
       
        Node * res=new Node(0);
        Node * ans=res;
        while(head1!=NULL && head2!=NULL){
            if(head1->data>head2->data){
                ans->next=new Node(head2->data);
                ans=ans->next;
                head2=head2->next;
            }
            else{
               ans->next=new Node(head1->data);
                ans=ans->next;
                head1=head1->next;
            }
        }
        while(head1!=NULL){
            ans->next=new Node(head1->data);
            ans=ans->next;
            head1=head1->next;
        }
        while(head2!=NULL){
            ans->next=new Node(head2->data);
            ans=ans->next;
            head2=head2->next;
        }
        return res->next;
        
    }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 21 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

