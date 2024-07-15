// GFG POTD 15/7/2024
Smallest number

    // Difficulty: MediumAccuracy: 38.74%Submissions: 55K+Points: 4
    // Given two integers s and d. The task is to find the smallest number such that the sum of its digits is s and the number of digits in the number are d. Return a string that is the smallest possible number. If it is not possible then return -1.

    // Examples:

    // Input: s = 9, d = 2
    // Output: 18
    // Explanation: 18 is the smallest number possible with the sum of digits = 9 and total digits = 2.
    // Input: s = 20, d = 3
    // Output: 299
    // Explanation: 299 is the smallest number possible with the sum of digits = 20 and total digits = 3.
    // Expected Time Complexity: O(d)
    // Expected Auxiliary Space: O(1)

    // Constraints:
    // 1 ≤ s ≤ 100
    // 1 ≤ d ≤ 6

    class Solution
{
public:
    string smallestNumber(int s, int d)
    {
        string ans = "";
        int i = 1;
        while (i <= d)
        {
            int num = (s - (d - i) * 9) <= 0 ? 0 : s - (d - i) * 9;
            if (num > 9)
                return "-1";
            if (num == 0 && i == 1)
                num = 1;

            ans += (num + '0');
            i++;
            s -= num;
        }
        return ans;
    }
};


//LeetCode
2196. Create Binary Tree From Descriptions
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.

// The test cases will be generated such that the binary tree is valid.

 

// Example 1:


// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.
// Example 2:


// Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// Output: [1,2,null,null,3,4]
// Explanation: The root node is the node with value 1 since it has no parent.
// The resulting binary tree is shown in the diagram.
 

// Constraints:

// 1 <= descriptions.length <= 104
// descriptions[i].length == 3
// 1 <= parenti, childi <= 105
// 0 <= isLefti <= 1
// The binary tree described by descriptions is valid.


