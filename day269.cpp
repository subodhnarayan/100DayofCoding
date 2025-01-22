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

1765. Map of Highest Peak
Solved
Medium
Topics
Companies
Hint
You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

 

Example 1:



Input: isWater = [[0,1],[0,0]]
Output: [[1,0],[2,1]]
Explanation: The image shows the assigned heights of each cell.
The blue cell is the water cell, and the green cells are the land cells.
Example 2:



Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
Output: [[1,1,0],[0,1,1],[1,2,2]]
Explanation: A height of 2 is the maximum possible height of any assignment.
Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.
 

Constraints:

m == isWater.length
n == isWater[i].length
1 <= m, n <= 1000
isWater[i][j] is 0 or 1.
There is at least one water cell.
 



