------------------------------------------------------------ GFG POTD 14/06/2024 ------------------------------------------------------

Symmetric Tree
Difficulty: EasyAccuracy: 44.96%Submissions: 166K+Points: 2Average Time: 20m
Given the root of a binary tree, check whether it is symmetric, i.e., whether the tree is a mirror image of itself.


A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree.

Examples:

Input: root[] = [1, 2, 2, 3, 4, 4, 3]
   ex-1_1
Output: True
Explanation: As the left and right half of the above tree is mirror image, tree is symmetric.
Input: root[] = [1, 2, 2, N, 3, N, 3]
   ex-2_1
Output: False
Explanation:  As the left and right half of the above tree is not the mirror image, tree is not symmetric. 
Constraints:
1  ≤ number of nodes ≤ 2000

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(h)

   class Solution {
  public:
  bool solve(Node* r1, Node* r2){
        if(r1==NULL && r2==NULL) return 1;
        if((r1==NULL && r2!=NULL) || (r1!=NULL && r2==NULL)) return 0;
        return ((r1->data==r2->data) && solve(r1->left, r2->right) 
        && solve(r1->right, r2->left));
    }
    
    bool isSymmetric(Node* root) {
        if(root==NULL) return true;
        return solve(root->left,root->right);
    }
};



------------------------------------------------------------ Leetcode POTD 14/06/2024 ------------------------------------------------------




2566. Maximum Difference by Remapping a Digit
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.

Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.

Notes:

When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
Bob can remap a digit to itself, in which case num does not change.
Bob can remap different digits for obtaining minimum and maximum values respectively.
The resulting number after remapping can contain leading zeroes.
 

Example 1:

Input: num = 11891
Output: 99009
Explanation: 
To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
The difference between these two numbers is 99009.
Example 2:

Input: num = 90
Output: 99
Explanation:
The maximum value that can be returned by the function is 99 (if 0 is replaced by 9) and the minimum value that can be returned by the function is 0 (if 9 is replaced by 0).
Thus, we return 99.
 

Constraints:

1 <= num <= 108


   class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        string t=s;
        size_t pos=s.find_first_not_of('9');
        if(pos!=string::npos){
            char a = s[pos];
            replace(s.begin(),s.end(),a,'9');
        }
        char b=t[0];
        replace(t.begin(),t.end(),b,'0');
        return stoi(s)-stoi(t);
    }
};
