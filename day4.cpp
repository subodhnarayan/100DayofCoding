class Solution
{
public:
    int find(int in[], int n, int e)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == e)
            {
                return i;
            }
        }
        return -1;
    }
    Node *solve(int in[], int post[], int n, int &index, int preIndex, int postIndex)
    {
        if (index < 0 || preIndex > postIndex)
        {
            return NULL;
        }
        int element = post[index--];
        Node *root = new Node(element);
        int position = find(in, n, element);
        root->right = solve(in, post, n, index, position + 1, postIndex);
        root->left = solve(in, post, n, index, preIndex, position - 1);
        return root;
    }

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n)
    {
        // Your code here
        int index = n - 1;
        Node *ans = solve(in, post, n, index, 0, n - 1);
        return ans;
    }
};