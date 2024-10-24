 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 24 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
 Modify the Array
Difficulty: EasyAccuracy: 29.5%Submissions: 56K+Points: 2
Given an array arr. Return the modified array in such a way that if the current and next numbers are valid numbers and are equal then double the current number value and replace the next number with 0. After the modification, rearrange the array such that all 0's are shifted to the end.

Note:

Assume ‘0’ as the invalid number and all others as a valid number.
The sequence of the valid numbers is present in the same order.
Example:

Input: arr[] = [2, 2, 0, 4, 0, 8] 
Output: [4, 4, 8, 0, 0, 0] 
Explanation: At index 0 and 1 both the elements are the same. So, we will change the element at index 0 to 4 and the element at index 1 is 0 then we will shift all the zeros to the end of the array. So, the array will become [4, 4, 8, 0, 0, 0].
Input: arr[] = [0, 2, 2, 2, 0, 6, 6, 0, 0, 8] 
Output: [4, 2, 12, 8, 0, 0, 0, 0, 0, 0]
Explanation: At index 5 and 6 both the elements are the same. So, we will change the element at index 5 to 12 and the element at index 6 is 0. We will change the element at index 1 to 4 and the element at index 2 is 0. Then we shift all the zeros to the end of the array. So, array will become [4, 2, 12, 8, 0, 0, 0, 0, 0, 0].
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106



class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        int n = arr.size();
        vector<int>ans(n);
        int i = 0,j = n-1;
        for(int k = 0;k<n;k++) {
            if(k+1<n && arr[k]!=0 && arr[k+1]!=0 && arr[k] == arr[k+1]) {
                ans[i++] = 2*arr[k];
                arr[k+1] = 0;
            }
            else if(arr[k]!=0) {
                ans[i++] = arr[k];
            }
            else ans[j--] = arr[k];
        }
        return ans;
    }
};
 

 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 24 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
 
Code
Testcase
Testcase
Test Result
951. Flip Equivalent Binary Trees
Solved
Medium
Topics
Companies
For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.

Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.

 

Example 1:

Flipped Trees Diagram
Input: root1 = [1,2,3,4,5,6,null,null,null,7,8], root2 = [1,3,2,null,6,4,5,null,null,null,null,8,7]
Output: true
Explanation: We flipped at nodes with values 1, 3, and 5.
Example 2:

Input: root1 = [], root2 = []
Output: true
Example 3:

Input: root1 = [], root2 = [1]
Output: false
 

Constraints:

The number of nodes in each tree is in the range [0, 100].
Each tree will have unique node values in the range [0, 99].