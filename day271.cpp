-- -- -- -- -- -- -- -- -GFG - POTD - 24 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Detect Loop in linked list
Difficulty: MediumAccuracy: 43.49%Submissions: 461K+Points: 4
You are given the head of a singly linked list. Your task is to determine if the linked list contains a loop. A loop exists in a linked list if the next pointer of the last node points to any other node in the list (including itself), rather than being null.

Custom Input format:
A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.

Examples:

Input: head: 1 -> 3 -> 4, pos = 2
Output: true
Explanation: There exists a loop as last node is connected back to the second node.

Input: head: 1 -> 8 -> 3 -> 4, pos = 0
Output: false
Explanation: There exists no loop in given linked list.

Input: head: 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: There exists a loop as last node is connected back to the first node.


Constraints:
1 ≤ number of nodes ≤ 104
1 ≤ node->data ≤ 103       
0 ≤ pos ≤ Number of nodes in Linked List

Time Complexity: O(n)Auxiliary Space: O(1)

class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
        // your code here
        Node* fast=head;
        Node* slow=head;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            
            if(fast==slow) return true;
        }
        
        return false;
    }
};


-- -- -- -- -- -- -- -- -LeetCode - POTD - 24 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

802. Find Eventual Safe States
Solved
Medium
Topics
Companies
There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
 

Constraints:

n == graph.length
1 <= n <= 104
0 <= graph[i].length <= n
0 <= graph[i][j] <= n - 1
graph[i] is sorted in a strictly increasing order.
The graph may contain self-loops.
The number of edges in the graph will be in the range [1, 4 * 104].

class Solution {
public:
    int n;
    vector<int> degreein;
    vector< vector<int> > rGraph;
    vector<int> ans;
    
    void init(vector<vector<int>>& G){
        n = G.size();
        degreein = vector<int>(n,0);
        rGraph.resize(n, vector<int>(0) );
        
        for (int u=0; u<n; u++){
            for (int v:G[u]){
                rGraph[v].push_back(u);
                degreein[u]++;
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        init(graph);
        queue<int> que;
        for (int i=0; i<n; i++){
            if (degreein[i]==0) que.push(i);
        }
        while (que.size()){
            int u = que.front(); que.pop();
            ans.push_back(u);
            for (int v:rGraph[u]){
                degreein[v]--;
                if (degreein[v]==0) que.push(v);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};