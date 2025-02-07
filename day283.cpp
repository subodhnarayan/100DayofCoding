-- -- -- -- -- -- -- -- -GFG - POTD - 05 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Mirror Tree
Difficulty: EasyAccuracy: 72.67%Submissions: 221K+Points: 2Average Time: 20m
Given a binary tree, convert the binary tree to its Mirror tree.

Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged.     

Examples:

Input: root[] = [1, 2, 3, N, N, 4]
Output: [1, 3, 2, N, 4]
Explanation: 

In the inverted tree, every non-leaf node has its left and right child interchanged.
Input: root[] = [1, 2, 3, 4, 5]
Output: [1, 3, 2, N, N, 5, 4]
Explanation:

In the inverted tree, every non-leaf node has its left and right child interchanged.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105


class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(!node) return;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 05 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

1790. Check if One String Swap Can Make Strings Equal
Solved
Easy
Topics
Companies
Hint
You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

 

Example 1:

Input: s1 = "bank", s2 = "kanb"
Output: true
Explanation: For example, swap the first character with the last character of s2 to make "bank".
Example 2:

Input: s1 = "attack", s2 = "defend"
Output: false
Explanation: It is impossible to make them equal with one string swap.
Example 3:

Input: s1 = "kelb", s2 = "kelb"
Output: true
Explanation: The two strings are already equal, so no string swap operation is required.
 

Constraints:

1 <= s1.length, s2.length <= 100
s1.length == s2.length
s1 and s2 consist of only lowercase English letters.


class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        const int n=s1.size();
        int cntD=0, i;
        array<char, 2> D={0};
        for(i=0; i<n && cntD<=2; i++){
            char x=s1[i], y=s2[i];
            if (x!=y){
                cntD++;
                if (cntD>2 ||(cntD==2 && (D[0]!=y || D[1]!=x )))
                    return 0;
                D={x, y};
            }
        }
        return cntD==0 || cntD==2;
    }
};