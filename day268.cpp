-- -- -- -- -- -- -- -- -GFG - POTD - 22 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Linked List Group Reverse
Difficulty: HardAccuracy: 57.08%Submissions: 227K+Points: 8
Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.

Examples:

Input: head = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5

Explanation: The first 4 elements 1, 2, 2, 4 are reversed first and then the next 4 elements 5, 6, 7, 8. Hence, the resultant linked list is 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5.
Input: head = 1 -> 2 -> 3 -> 4 -> 5, k = 3
Output: 3 -> 2 -> 1 -> 5 -> 4

Explanation: The first 3 elements 1, 2, 3 are reversed first and then left out elements 4, 5 are reversed. Hence, the resultant linked list is 3 -> 2 -> 1 -> 5 -> 4.
Constraints:
1 <= size of linked list <= 105
1 <= data of nodes <= 106
1 <= k <= size of linked list 


class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        stack<int> st;
        Node* an=new Node(0);
        Node* re=an;
        
        int len=0;
        Node* temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        int rem=len/k;
        temp=head;
        for(int i=0;i<rem;i++){
            for(int j=0;j<k;j++){
                st.push(temp->data);
                temp=temp->next;
            }
            for(int j=0;j<k;j++){
                re->next=new Node(st.top());
                re=re->next;
                st.pop();
            }
        }
        
        while(temp!=NULL){
            st.push(temp->data);
            temp=temp->next;
        }
        
        while(!st.empty()){
            re->next=new Node(st.top());
                re=re->next;
                st.pop();
        }
        
        return an->next;
        
    }
};


-- -- -- -- -- -- -- -- -LeetCode - POTD - 22 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
