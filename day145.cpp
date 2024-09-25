-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 25 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Palindrome Linked List
Difficulty: MediumAccuracy: 41.48%Submissions: 334K+Points: 4
Given a singly linked list of integers. The task is to check if the given linked list is palindrome or not.

Examples:

Input: LinkedList: 1->2->1->1->2->1
Output: true
Explanation: The given linked list is 1->2->1->1->2->1 , which is a palindrome and Hence, the output is true.

Input: LinkedList: 1->2->3->4
Output: false
Explanation: The given linked list is 1->2->3->4, which is not a palindrome and Hence, the output is false.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1) 
Note: You should not use the recursive stack space as well

Constraints:
1 <= number of nodes <= 105
1 ≤ node->data ≤ 103


class Solution {
  public:
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // vector<int> ans;
        // Node* curr=head;
        // while(curr!=NULL){
        //     ans.push_back(curr->data);
        //     curr=curr->next;
        // }
        
        // int n=ans.size()-1,i=0;
        // while(i<n){
        //     if(ans[i]!=ans[n]) return false;
        //     i++,n--;
        // }
        // return true;
        
        string ans="";
        Node* curr=head;
        while(curr!=NULL){
            ans.push_back(curr->data);
            curr=curr->next;
        }
        
        int n=ans.size()-1,i=0;
        while(i<n){
            if(ans[i]!=ans[n]) return false;
            i++,n--;
        }
        return true;
        
        
    }
};