-- -- -- -- -- -- -- -- -GFG - POTD - 16 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Serialize and deserialize a binary tree
Difficulty: MediumAccuracy: 51.67%Submissions: 92K+Points: 4Average Time: 45m
Serialization is to store a tree in an array so that it can be later restored and deserialization is reading tree back from the array. Complete the functions

serialize() : stores the tree into an array a and returns the array.
deSerialize() : deserializes the array to the tree and returns the root of the tree.
Note: Multiple nodes can have the same data and the node values are always positive integers. Your code will be correct if the tree returned by deSerialize(serialize(input_tree)) is same as the input tree. Driver code will print the in-order traversal of the tree returned by deSerialize(serialize(input_tree)).

Examples :

Input: root = [1, 2, 3]
      
Output: [2, 1, 3]
Input: root = [10, 20, 30, 40, 60, N, N]
      
Output: [40, 20, 60, 10, 30]
Constraints:
1 <= Number of nodes <= 104
1 <= Data of a node <= 109

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

class Solution {
  public:
    // Function to serialize a tree and return a list containing nodes of tree.
    void helper(Node* root,vector<int>&ans){
        if(root==NULL) return;
        helper(root->left,ans);
        ans.push_back(root->data);
        helper(root->right,ans);
    }
    vector<int> serialize(Node *root) {
        vector<int>ans;
        helper(root,ans);
        return ans;
    }
    
     void help(vector<int>&arr,int index,Node* root,Node* &sol){
        if(index>=arr.size()) return;
        Node* node=new Node(arr[index]);
        node->left=root;
        if(index+1<arr.size()){
            Node* r=new Node(arr[index+1]);
            node->right=r;
        }
        sol=node;
        help(arr,index+2,node,sol);
    }
    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &arr) {
        Node* ans=new Node(arr[0]);
        if(arr.size()==1){
            return ans;
        }
        Node* sol=NULL;
        help(arr,1,ans,sol);
        return sol;
    }
};

//{ Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node *node) {
    if (node == NULL)
        return;

    /* first delete both subtrees */
    _deleteTree(node->left);
    _deleteTree(node->right);

    /* then delete the node */
    // cout << "Deleting node: " << node->data << endl;
    delete node;
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(Node **node_ref) {
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);

        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node *temp = root;
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);

        cout << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends

-- -- -- -- -- -- -- -- -LeetCode - POTD - 16 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

1718. Construct the Lexicographically Largest Valid Sequence
Solved
Medium
Topics
Companies
Hint
Given an integer n, find a sequence that satisfies all of the following:

The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.

Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.

A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

 

Example 1:

Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
Example 2:

Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]
 

Constraints:

1 <= n <= 20


class Solution {
    public:
        bool backtrack(vector<int>& result, vector<bool>& used, int n, int index) {
            while (index < result.size() && result[index] != 0) {
                index++;
            }
            if (index == result.size()) {
                return true;
            }
    
            for (int i = n; i >= 1; i--) {
                if (used[i]) continue;
    
                if (i == 1) {
                    result[index] = 1;
                    used[1] = true;
                    if (backtrack(result, used, n, index + 1)) return true;
                    result[index] = 0;
                    used[1] = false;
                } else if (index + i < result.size() && result[index + i] == 0) {
                    result[index] = i;
                    result[index + i] = i;
                    used[i] = true;
                    if (backtrack(result, used, n, index + 1)) return true;
                    result[index] = 0;
                    result[index + i] = 0;
                    used[i] = false;
                }
            }
            return false;
        }
        vector<int> constructDistancedSequence(int n) {
            vector<int> result(2 * n - 1, 0);
            vector<bool> used(n + 1, false);
            backtrack(result, used, n, 0);
            return result;
        }
    };