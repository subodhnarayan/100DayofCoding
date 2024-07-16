// GFG POTD 16/7/2024
//  Remaining String
//  Difficulty: EasyAccuracy: 17.06%Submissions: 59K+Points: 2
//  Given a string s without spaces, a character ch and an integer count. Your task is to return the substring that remains after the character ch has appeared count number of times.
//  Note:  Assume upper case and lower case alphabets are different. “”(Empty string) should be returned if it is not possible, or the remaining substring is empty.

// Examples:

// Input: s = "Thisisdemostring", ch = 'i', count = 3
// Output: ng
// Explanation: The remaining substring of s after the 3rd
// occurrence of 'i' is "ng", hence the output is ng.
// Input: s = "Thisisdemostri", ch = 'i', count = 3
// Output: ""
// Explanation: The 3rd occurence of 'i' is at the last index. In this case the remaining substring is empty, hence we return empty string.
// Input: s = "abcd", ch = 'x', count = 2
// Output: ""
// Explanation: The character x is not present in the string, hence we return empty string.
// Expected Time Complexity: O(|s|)
// Expected Auxiliary Space: O(1)

class Solution
{
public:
    string printString(string s, char ch, int count)
    {
        string ans = "";
        int n = s.size();
        int i = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ch)
            {
                count--;
            }
            if (count == 0)
            {
                return s.substr(i + 1);
            }
        }
        return "";
    }
};


//leetcode POTD
2096. Step-By-Step Directions From a Binary Tree Node to Another
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.

 

// Example 1:


// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
// Example 2:


// Input: root = [2,1], startValue = 2, destValue = 1
// Output: "L"
// Explanation: The shortest path is: 2 → 1.
 

// Constraints:

// The number of nodes in the tree is n.
// 2 <= n <= 105
// 1 <= Node.val <= n
// All the values in the tree are unique.
// 1 <= startValue, destValue <= n
// startValue != destValue


