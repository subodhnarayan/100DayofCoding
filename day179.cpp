-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 29 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Quick Sort on Linked List
Difficulty: MediumAccuracy: 71.8%Submissions: 30K+Points: 4
You are given a Linked List. Sort the given Linked List using quicksort. 

Examples:

Input: Linked list: 1->6->2
Output: 1->2->6

Explanation:
After sorting the nodes, we have 1, 2 and 6.
Input: Linked list: 1->9->3->8
Output: 1->3->8->9

Explanation:
After sorting the nodes, we have 1, 3, 8 and 9. 
Constraints:
1<= size of linked list <= 105


class Solution {
  public:
   struct Node* Partition(struct Node* head,struct Node* last){
       struct Node* i=head;
       struct Node* j=head->next;
       while(j!=last){
           if(j->data<head->data){
               i=i->next;
               swap(i->data,j->data);
           }
           j=j->next;
       }
       swap(i->data,head->data);
       return i;
       
   }
   
   void QuickSort(struct Node* head,struct Node* last){
       if(head==last || head->next==last){
           return;
       }
       struct Node* p=Partition(head,last);
       QuickSort(head,p);
       QuickSort(p->next,last);
   }
    struct Node* quickSort(struct Node* head) {
        QuickSort(head,NULL);
        return head;
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 29 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --