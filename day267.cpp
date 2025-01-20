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

2661. First Completely Painted Row or Column
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

Return the smallest index i at which either a row or a column will be completely painted in mat.

 

Example 1:

image explanation for example 1
Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
Output: 2
Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
Example 2:

image explanation for example 2
Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
Output: 3
Explanation: The second column becomes fully painted at arr[3].
 

Constraints:

m == mat.length
n = mat[i].length
arr.length == m * n
1 <= m, n <= 105
1 <= m * n <= 105
1 <= arr[i], mat[r][c] <= m * n
All the integers of arr are unique.
All the integers of mat are unique.
