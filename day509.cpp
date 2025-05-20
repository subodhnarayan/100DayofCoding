-- -- -- -- -- -- -- -- -GFG - POTD - 20 / 05 / 2025 ----------------------------------------
Burning Tree
Difficulty: HardAccuracy: 53.53%Submissions: 112K+Points: 8
Given a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.
Note: The tree contains unique values.

Examples : 

Input: root[] = [1, 2, 3, 4, 5, 6, 7], target = 2
  
Output: 3
Explanation: Initially 2 is set to fire at 0 sec 
At 1 sec: Nodes 4, 5, 1 catches fire.
At 2 sec: Node 3 catches fire.
At 3 sec: Nodes 6, 7 catches fire.
It takes 3s to burn the complete tree.
Input: root[] = [1, 2, 3, 4, 5, N, 7, 8, N, 10], target = 10

Output: 5
Explanation: Initially 10 is set to fire at 0 sec 
At 1 sec: Node 5 catches fire.
At 2 sec: Node 2 catches fire.
At 3 sec: Nodes 1 and 4 catches fire.
At 4 sec: Node 3 and 8 catches fire.
At 5 sec: Node 7 catches fire.
It takes 5s to burn the complete tree.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(h)

class Solution {
  public:
    void dfs(Node* node, Node* par, map<Node*, Node*>& parent, int target, Node*& startNode){
    	if(node==NULL) return;
    	parent[node]=par;
        if(node->data==target) startNode=node;
        dfs(node->left, node, parent, target, startNode);
        dfs(node->right, node, parent, target, startNode);
    }
    void dfs2(Node* node, Node* par, int time, int& totalTime, map<Node*, Node*>& parent){
    	if(node==NULL) return;
    	totalTime=max(totalTime, time);
    	if(node->left!=par) dfs2(node->left, node, time+1, totalTime, parent);
    	if(node->right!=par) dfs2(node->right, node, time+1, totalTime, parent);
    	if(parent.find(node)!=parent.end() && parent[node]!=par) dfs2(parent[node], node, time+1, totalTime, parent);
    }
    int minTime(Node* root, int target) {
        // code here
        map<Node*, Node*> parent;
        Node* startNode=nullptr;
        dfs(root, NULL, parent, target, startNode);  // O(V+E)
        int totalTime=0;
        dfs2(startNode, NULL, 0, totalTime, parent); // O(V+E)
        return totalTime;  
    }
};



-- -- -- -- -- -- -- -- -Leetcode - POTD - 20 / 05 / 2025 ----------------------------------------
