Longest alternating subsequence
            Difficulty : MediumAccuracy : 38.32 %
                         Submissions : 48K +
    Points : 4
    // You are given an array arr. Your task is to find the longest length of a good sequence. A good sequence {x1, x2, .. xn} is an alternating sequence if its elements satisfy one of the following relations :

    // 1.  x1 < x2 > x3 < x4 > x5. . . . . and so on
    // 2.  x1 >x2 < x3 > x4 < x5. . . . . and so on

    // Examples:

    // Input: arr= [1, 5, 4]
    // Output: 3
    // Explanation: The entire sequenece is a good sequence.
    // Input: arr= [1, 17, 5, 10, 13, 15, 10, 5, 16, 8]
    // Output: 7
    // Explanation: There are several subsequences that achieve this length.
    // One maximum length good subsequences is [1, 17, 10, 13, 10, 16, 8].
    // Expected Time Complexity: O(n)
    // Expected Space Complexity: O(1)

    // Constraints:
    // 1 <= nums.size() <= 105
    // 1 <= nums[i] <= 104

    class Solution
{
public:
    int alternatingMaxLength(vector<int> &arr)
    {
        int n = arr.size();
        int inc = 1, dec = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i - 1] < arr[i])
                dec = inc + 1;
            else if (arr[i - 1] > arr[i])
                inc = dec + 1;
        }

        return max(inc, dec);
    }
};

1530. Number of Good Leaf Nodes Pairs
    Solved
        Medium
            Topics
                Companies Hint
    // You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

    // Return the number of good leaf node pairs in the tree.

    // Example 1:

    // Input: root = [1,2,3,null,4], distance = 3
    // Output: 1
    // Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
    // Example 2:

    // Input: root = [1,2,3,4,5,6,7], distance = 3
    // Output: 2
    // Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
    // Example 3:

    // Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
    // Output: 1
    // Explanation: The only good pair is [2,5].

    // Constraints:

    // The number of nodes in the tree is in the range [1, 210].
    // 1 <= Node.val <= 100
    // 1 <= distance <= 10

    class Solution
{
public:
    void makeGraph(TreeNode *root, TreeNode *prev, unordered_map<TreeNode *, vector<TreeNode *>> &adj,
                   unordered_set<TreeNode *> &st)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL && root->right == NULL)
        {
            st.insert(root);
        }

        if (prev != NULL)
        {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);
    }

    int countPairs(TreeNode *root, int distance)
    {
        unordered_map<TreeNode *, vector<TreeNode *>> adj;
        unordered_set<TreeNode *> st;

        makeGraph(root, NULL, adj, st);

        int count = 0; // count of good node pairs

        for (auto &leaf : st)
        {

            // bfs hit karo and see if you can find another leaf nodes within distance
            queue<TreeNode *> que;
            unordered_set<TreeNode *> visited;
            que.push(leaf);
            visited.insert(leaf);

            for (int level = 0; level <= distance; level++)
            { // only to till<=distance
                int size = que.size();
                while (size--)
                {
                    TreeNode *curr = que.front();
                    que.pop();

                    if (curr != leaf && st.count(curr))
                    {
                        count++;
                    }

                    for (auto &ngbr : adj[curr])
                    {
                        if (!visited.count(ngbr))
                        {
                            que.push(ngbr);
                            visited.insert(ngbr);
                        }
                    }
                }
            }
        }
        return count / 2;
    }
};