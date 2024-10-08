-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 21 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Clone a linked list with next and random pointer
Difficulty: HardAccuracy: 64.8%Submissions: 87K+Points: 8
You are given a special linked list where each node has a next pointer pointing to its next node. You are also given some random pointers, where you will be given some pairs denoting two nodes a and b i.e. a->random = b (random is a pointer to a random node).

Construct a copy of the given list. The copy should consist of the same number of new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the original and copied list pointers represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes x and y in the original list, where x->random = y, then for the corresponding two nodes xnew and ynew in the copied list, xnew->random = ynew.

Return the head of the copied linked list.

NOTE : 
1. If there is any node whose arbitrary pointer is not given then it's by default NULL. 
2. Don't make any changes to the original linked list.

ArbitLinked List1

Note: The diagram isn't part of any example, it just depicts an example of how the linked list may look.

Examples:

Input: LinkedList: 1->2->3->4 , pairs = [{1,2},{2,4}]
Output: true
Explanation: In this test case, there are 4 nodes in linked list.  Among these 4 nodes,  2 nodes have arbitrary pointer set, rest two nodes have arbitrary pointer as NULL. Second line tells us the value of four nodes. The third line gives the information about arbitrary pointers. The first node arbitrary pointer is set to node 2.  The second node arbitrary pointer is set to node 4.
Input: LinkedList: 1->3->5->9 , pairs[] = [{1,1},{3,4}]
Output: true
Explanation: In the given testcase, applying the method as stated in the above example, the output will be 1.
Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)

Constraints:
1 <= numbers of random pointer <= number of nodes <= 100
0 <= node->data <= 1000
1 <= a, b <= 100

class Solution {
  public:
    Node *copyList(Node *head) {
        
        Node* curr=head;
          //ading the cpoy of the each node
        while(curr){
           Node* clone=new Node(curr->data);
           clone->next=curr->next;
           curr->next=clone;
           curr=clone->next;
        }
        
        //
        curr=head;
        while(curr){
        if(curr->random){
            curr->next->random=curr->random->next;
        }
        curr=curr->next->next;
        }
        
        
        Node* Clone=new Node(0),*ans=Clone;
        curr=head;
        while(curr){
            Clone->next=curr->next;
            Clone=Clone->next;
            curr->next=Clone->next;
            curr=curr->next;
        }
        
        return ans->next;
        
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 21 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- --

386. Lexicographical Numbers
Solved
Medium
Topics
Companies
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]
 

Constraints:

1 <= n <= 5 * 104



class Solution {
public:
    vector<int> lexicalOrder(int n) {
       //what is my approach is that first store all this number
       //range in the string array and then sort that string 
       //array and then return these each string by converting
       // number


//        vector<string> an;
//        for(int i=1;i<=n;i++){
//         an.push_back(to_string(i));
//        }
//        sort(an.begin(),an.end());
//        vector<int> ans;
//        for(int i=0;i<n;i++){
// ans.push_back(stoi(an[i]));
//        }
//        return ans;  0(nlogn)

       vector<int> ans;
       int curr=1;
       for(int i=1;i<=n;i++){
        ans.push_back(curr);
        if(curr*10<=n){
            curr=curr*10;
        }
        else{
            while(curr%10==9 || curr>=n){
                curr=curr/10;
            }
            curr+=1;
        }
       }
       return ans;
    }
};