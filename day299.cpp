-- -- -- -- -- -- -- -- -GFG - POTD - 19 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Merge K sorted linked lists
Difficulty: MediumAccuracy: 57.01%Submissions: 96K+Points: 4Average Time: 60m
Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, then return the head of the merged linked list.

Examples:

Input: arr[] = [1 -> 2 -> 3, 4 -> 5, 5 -> 6, 7 -> 8]
Output: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 7 -> 8
Explanation:
The arr[] has 4 sorted linked list of size 3, 2, 2, 2.
1st list: 1 -> 2-> 3
2nd list: 4 -> 5
3rd list: 5 -> 6
4th list: 7 -> 8
The merged list will be:
 
Input: arr[] = [1 -> 3, 8, 4 -> 5 -> 6]
Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
Explanation:
The arr[] has 3 sorted linked list of size 2, 3, 1.
1st list: 1 -> 3
2nd list: 8
3rd list: 4 -> 5 -> 6
The merged list will be:

Constraints
1 <= total no. of nodes <= 105
1 <= node->data <= 103


class Solution {
    public:
    
     void merge(vector<int> &res,Node* head){
         if(head==NULL) return;
         Node* curr=head;
         while(curr!=NULL){
             res.push_back(curr->data);
             curr=curr->next;
         }
         return;
     }
      Node* mergeKLists(vector<Node*>& arr) {
          
          vector<int> res;
          for(int i=0;i<arr.size();i++){
              merge(res,arr[i]);
          }
          
          sort(res.begin(),res.end());
          Node* ans=new Node(0);
          Node* ret=ans;
          for(int i=0;i<res.size();i++){
              ret->next=new Node(res[i]);
              ret=ret->next;
          }
          
          return ans->next;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 19 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

