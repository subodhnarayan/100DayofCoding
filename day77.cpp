// Remove Half Nodes
// Difficulty: EasyAccuracy: 59.67%Submissions: 36K+Points: 2
// You are given a binary tree and you need to remove all the half nodes (which have only one child). Return the root node of the modified tree after removing all the half-nodes.

// Note: The output will be judged by the inorder traversal of the resultant tree, inside the driver code.

// Examples:

// Input: tree = 5
//             /   \
//           7     8
//         /
//       2
// Output: 2 5 8
// Explanation: In the above tree, the node 7 has only single child. After removing the node the tree becomes  2<-5->8. Hence, the answer is 2 5 8 & it is in inorder traversal.
// Input:  tree = 2
//               / \   
//             7   5
// Output: 7 2 5
// Explanation: Here there are no nodes which has only one child. So the tree remains same.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(height of the binary tree)

// Constraints:
// 1<=number of nodes<=104

class Solution
{
public:
    Node *RemoveHalfNodes(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);

        if (root->left and !root->right)
            return root->left;
        else if (root->right and !root->left)
            return root->right;
        else
            return root;
    }
};



// 1605. Find Valid Matrix Given Row and Column Sums
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.

// Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.

// Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.

 

// Example 1:

// Input: rowSum = [3,8], colSum = [4,7]
// Output: [[3,0],
//          [1,7]]
// Explanation: 
// 0th row: 3 + 0 = 3 == rowSum[0]
// 1st row: 1 + 7 = 8 == rowSum[1]
// 0th column: 3 + 1 = 4 == colSum[0]
// 1st column: 0 + 7 = 7 == colSum[1]
// The row and column sums match, and all matrix elements are non-negative.
// Another possible matrix is: [[1,2],
//                              [3,5]]
// Example 2:

// Input: rowSum = [5,7,10], colSum = [8,6,8]
// Output: [[0,5,0],
//          [6,1,0],
//          [2,0,8]]
 

// Constraints:

// 1 <= rowSum.length, colSum.length <= 500
// 0 <= rowSum[i], colSum[i] <= 108
// sum(rowSum) == sum(colSum)


class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
         int numRows = rowSum.size();
        int numCols = colSum.size();
        vector<vector<int>> result(numRows, vector<int>(numCols, 0));

        int i = 0, j = 0;

        while (i < numRows && j < numCols) {
            int val = min(rowSum[i], colSum[j]);
            result[i][j] = val;
            rowSum[i] -= val;
            colSum[j] -= val;

            if (rowSum[i] == 0) {
                i++;
            }
            if (colSum[j] == 0) {
                j++;
            }
        }
        return result;
    }
};