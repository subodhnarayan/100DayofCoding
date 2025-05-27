-- -- -- -- -- -- -- -- -GFG - POTD - 27 / 05 / 2025 ----------------------------------------
Print leaf nodes from preorder traversal of BST
Difficulty: MediumAccuracy: 47.26%Submissions: 34K+Points: 4
Given a preorder traversal of a BST, find the leaf nodes of the tree without building the tree.


Examples:

Input: preorder[] = [5, 2, 10]
Output: [2, 10]
Explaination: 

2 and 10 are the leaf nodes as shown in the figure.
Input: preorder[] = [4, 2, 1, 3, 6, 5]
Output: [1, 3, 5]
Explaination: 

1, 3 and 5 are the leaf nodes as shown in the figure.
Input: preorder[] = [8, 2, 5, 10, 12]
Output: [5, 12]
Explaination: 

5 and 12 are the leaf nodes as shown in the figure.

Constraints:
1 ≤ preorder.size() ≤ 103
1 ≤ preorder[i] ≤ 103

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        queue<vector<int>>q;
        q.push(preorder);
        vector<int>ans;
        while(!q.empty())
        {
            vector<int>t=q.front();
            q.pop();
            vector<int>small;
            vector<int>large;
            if(t.size()==1)
            ans.push_back(t[0]);
            else
            {
                for(int i=1;i<t.size();i++)
                {
                    if(t[i]>t[0])
                    large.push_back(t[i]);
                    else
                    small.push_back(t[i]);
                    
                }
                if(!small.empty())
                q.push(small);
                if(!large.empty())
                q.push(large);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 27 / 05 / 2025 ----------------------------------------


2894. Divisible and Non-divisible Sums Difference
Solved
Easy
Topics
premium lock icon
Companies
Hint
You are given positive integers n and m.

Define two integers as follows:

num1: The sum of all integers in the range [1, n] (both inclusive) that are not divisible by m.
num2: The sum of all integers in the range [1, n] (both inclusive) that are divisible by m.
Return the integer num1 - num2.

 

Example 1:

Input: n = 10, m = 3
Output: 19
Explanation: In the given example:
- Integers in the range [1, 10] that are not divisible by 3 are [1,2,4,5,7,8,10], num1 is the sum of those integers = 37.
- Integers in the range [1, 10] that are divisible by 3 are [3,6,9], num2 is the sum of those integers = 18.
We return 37 - 18 = 19 as the answer.
Example 2:

Input: n = 5, m = 6
Output: 15
Explanation: In the given example:
- Integers in the range [1, 5] that are not divisible by 6 are [1,2,3,4,5], num1 is the sum of those integers = 15.
- Integers in the range [1, 5] that are divisible by 6 are [], num2 is the sum of those integers = 0.
We return 15 - 0 = 15 as the answer.
Example 3:

Input: n = 5, m = 1
Output: -15
Explanation: In the given example:
- Integers in the range [1, 5] that are not divisible by 1 are [], num1 is the sum of those integers = 0.
- Integers in the range [1, 5] that are divisible by 1 are [1,2,3,4,5], num2 is the sum of those integers = 15.
We return 0 - 15 = -15 as the answer.
 

Constraints:

1 <= n, m <= 1000