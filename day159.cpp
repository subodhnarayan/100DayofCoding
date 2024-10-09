-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 10 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --



Linked List Matrix
Difficulty: EasyAccuracy: 67.33%Submissions: 27K+Points: 2
Given a Matrix mat of n*n size. Your task is constructing a 2D linked list representation of the given matrix.

Input: mat = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: 

Input: mat = [[23, 28], [23, 28]]
Output:

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n2)

Constraints:
1 <= mat.size() <=15
1 <= mat[i][j] <=104

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // 
        // int row=mat.size();
        // int col=mat[0].size();
        // Node tem=new Node(0);
        // Node* rt=NULL,dn=NULL;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         Node* temp=new Node(mat[i][j]);
                
        //     }
        // }
        
        // //when i am solving this problem i am getting issue like how to set the right and down  link
        Node *ans, *prev;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            Node *curH = new Node(mat[i][0]);
            Node *iter = curH;
            if (i == 0)
                ans = curH;
            for (int j = 1; j < m; j++) {
                Node *newNode = new Node(mat[i][j]);
                iter -> right = newNode;
                iter = iter -> right;
            }
            iter = curH;
            if (i != 0) {
                while (prev && iter) {
                    prev -> down = iter;
                    prev = prev -> right;
                    iter = iter -> right;
                }
            }
            prev = curH;
        }
        return ans;
    }
};




-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 10 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


Code


Testcase
Testcase
Test Result
921. Minimum Add to Make Parentheses Valid
Solved
Medium
Topics
Companies
A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

 

Example 1:

Input: s = "())"
Output: 1
Example 2:

Input: s = "((("
Output: 3
 

Constraints:

1 <= s.length <= 1000
s[i] is either '(' or ')'.

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;

    // Traverse the string
    for (char ch : s) {
        // If it's an opening parenthesis, push it to the stack
        if (ch == '(') {
            st.push(ch);
        }
        // If it's a closing parenthesis, check for a matching opening parenthesis
        else if (ch == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();  // Found a pair, pop it out
            } else {
                st.push(ch);  // No matching opening, push the closing parenthesis
            }
        }
    }

    // Return the size of the stack (remaining unpaired parentheses)
    return st.size();
    }
};