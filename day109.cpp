- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 20 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Burning Tree
Difficulty: HardAccuracy: 53.53%Submissions: 80K+Points: 8
Given a binary tree and a node data called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.
Note: The tree contains unique values.


Examples : 

Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7
Explanation: If leaf with the value 8 is set on fire. 
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.
Input:      
          1
        /   \
      2      3
    /  \      \
   4    5      7
  /    / 
 8    10
Target Node = 10
Output: 5

Expected Time Complexity: O(number of nodes)
Expected Auxiliary Space: O(height of tree)


Constraints:
1 ≤ number of nodes ≤ 105

1 ≤ values of nodes ≤ 105




class Solution {
  public:
    unordered_map<Node*,Node*> par;
    unordered_map<Node*,bool> vis;
    Node *tar  =nullptr;
    void dfs1(Node *root,int target){
        if(root == nullptr){
            return;
        }
        if(root->data == target){
            tar = root;
        }
        if(root->left != nullptr){
            par[root->left] =root;
        }if(root->right != nullptr){
            par[root->right]= root;
        }
        dfs1(root->left,target);
        dfs1(root->right,target);
    }
    int dfs2(Node* from){
        if(from == nullptr){
            return 0;
        }
        int lft = 0, rgt = 0, parent = 0;
        vis[from] =true;
        if(vis.find(from->left) == vis.end()){
            lft = dfs2(from->left);
        }
        if(vis.find(from->right) == vis.end()){
            rgt = dfs2(from->right);
        }
        if(par.find(from) != par.end() && vis.find(par[from]) == vis.end()){
            parent = dfs2(par[from]);
        }
        return 1 + max(max(lft, rgt), parent);
    }

    int minTime(Node* root, int target) 
    {
        dfs1(root,target);
        return dfs2(tar)-1;
    }
};


- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 20 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


1140. Stone Game II
Medium
Topics
Companies
Hint
Alice and Bob continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 

Alice and Bob take turns, with Alice starting first.  Initially, M = 1.

On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).

The game continues until all the stones have been taken.

Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.

 

Example 1:

Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 piles in total. If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
Example 2:

Input: piles = [1,2,3,4,5,100]
Output: 104
 

Constraints:

1 <= piles.length <= 100
1 <= piles[i] <= 104


class Solution {
public:
    int stoneGameII(vector<int>& piles) {
           int n = piles.size();
        
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        vector<int> suffixSum(n, 0);
        suffixSum[n - 1] = piles[n - 1];
        
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int m = 1; m <= n; m++) {
                if (i + 2 * m >= n) {
                    dp[i][m] = suffixSum[i];
                } else {
                    for (int x = 1; x <= 2 * m; x++) {
                        dp[i][m] = max(dp[i][m], suffixSum[i] - dp[i + x][max(m, x)]);
                    }
                }
            }
        }
        
        return dp[0][1];
    }
};


