-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 17 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


Split Linked List Alternatingly
Difficulty: EasyAccuracy: 42.46%Submissions: 30K+Points: 2
Given a singly linked list's head. Your task is to complete the function alternatingSplitList() that splits the given linked list into two smaller lists. The sublists should be made from alternating elements from the original list.
Note: 

The sublist should be in the order with respect to the original list.
Your have to return an array containing the both sub-linked lists.
Examples:

Input: LinkedList = 0->1->0->1->0->1
Output: 0->0->0 , 1->1->1
Explanation: After forming two sublists of the given list as required, we have two lists as: 0->0->0 and 1->1->1.

Input: LinkedList = 2->5->8->9->6
Output: 2->8->6 , 5->9
Explanation: After forming two sublists of the given list as required, we have two lists as: 2->8->6 and 5->9.
Input: LinkedList: 7 
Output: 7 , <empty linked list>
Constraints:
1 <= number of nodes <= 100
1 <= node -> data <= 
104



class Solution {
  public:
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
            if(head->next==NULL) return {head,NULL};
        if(head->next->next==NULL){
            Node *head1=head;
            Node *head2=head->next;
            head1->next=NULL;
            return {head1,head2};
        }
        Node *head1,*head2,*curr1,*curr2;
        head1=head;
        head2=head->next;
        curr1=head1;
        curr2=head2;
        while(curr2&&curr2->next){
            curr1->next=curr2->next;
            curr1=curr1->next;
            if(curr2->next){
                curr2->next=curr2->next->next;
                curr2=curr2->next;
            }
            if(curr2&&curr2->next==NULL){
                curr1->next=NULL;
            }
        }
        return {head1,head2};
    }
};

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 17 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


670. Maximum Swap
Solved
Medium
Topics
Companies
You are given an integer num. You can swap two digits at most once to get the maximum valued number.

Return the maximum valued number you can get.

 

Example 1:

Input: num = 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:

Input: num = 9973
Output: 9973
Explanation: No swap.
 

Constraints:

0 <= num <= 108


class Solution {
public:
    int maximumSwap(int num) {
         string numStr = to_string(num);
        int n = numStr.size();
        
        // Store the last occurrence of each digit (0-9)
        vector<int> last(10, -1);
        for (int i = 0; i < n; ++i) {
            last[numStr[i] - '0'] = i;
        }
        
        // Traverse each digit from left to right
        for (int i = 0; i < n; ++i) {
            // Check if there's a larger digit appearing later
            for (int d = 9; d > numStr[i] - '0'; --d) {
                if (last[d] > i) {
                    // Swap the current digit with the larger one
                    swap(numStr[i], numStr[last[d]]);
                    return stoi(numStr); // Convert back to integer and return
                }
            }
        }
        
        // If no swap was made, return the original number
        return num;
    }
};