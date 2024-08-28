-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 27 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Maximum Difference
Difficulty: MediumAccuracy: 33.3%Submissions: 69K+Points: 4
Given an integer array arr of integers, the task is to find the maximum absolute difference between the nearest left smaller element and the nearest right smaller element of every element in array arr. If for any component of the arr, the nearest smaller element doesn't exist then consider it as 0.

Examples :

Input: arr = [2, 1, 8]
Output: 1
Explanation: left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1
Input: arr = [2, 4, 8, 7, 7, 9, 3]
Output: 4
Explanation: left smaller array ls = [0, 2, 4, 4, 4, 7, 2], right smaller rs = [0, 3, 7, 3, 3, 3, 0]. Maximum Diff of abs(ls[i] - rs[i]) = abs(7 - 3) = 4
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 <= arr.size() <= 106
1<= arr[i] <=109



class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n=arr.size();
        vector<int> ls(n,0);
        vector<int> rs(n,0);
        
    stack<int> S;
 
    // Traverse all array elements
    for (int i=0; i<n; i++)
    {
        // Keep removing top element from S while the top
        // element is greater than or equal to arr[i]
        while (!S.empty() && S.top() >= arr[i])
            S.pop();
 
        // If all elements in S were greater than arr[i]
        if (!S.empty()){
            ls[i]=S.top();
        }
            
 
        // Push this element
        S.push(arr[i]);
    }
    stack<int> St;
    for(int i=n-1; i>=0; i--)
    {
        // Keep removing top element from S while the top
        // element is greater than or equal to arr[i]
        while (!St.empty() && St.top() >= arr[i])
            St.pop();
 
        // If all elements in S were greater than arr[i]
        if (!St.empty()){
            rs[i]=St.top();
        }
 
        // Push this element
        St.push(arr[i]);
    }
    
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(abs(ls[i]-rs[i]),ans);
    }
    return ans;
    
    }
};



-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 27 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

1514. Path with Maximum Probability
Solved
Medium
Topics
Companies
Hint
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

 

Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
Example 2:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000
Example 3:



Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.
 

Constraints:

2 <= n <= 10^4
0 <= start, end < n
start != end
0 <= a, b < n
a != b
0 <= succProb.length == edges.length <= 2*10^4
0 <= succProb[i] <= 1
There is at most one edge between every two nodes.


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        for (int i = 0; i < n - 1; ++i) {
            bool updated = false;
            for (int j = 0; j < edges.size(); ++j) {
                int u = edges[j][0];
                int v = edges[j][1];
                double prob = succProb[j];

                if (maxProb[u] * prob > maxProb[v]) {
                    maxProb[v] = maxProb[u] * prob;
                    updated = true;
                }
                if (maxProb[v] * prob > maxProb[u]) {
                    maxProb[u] = maxProb[v] * prob;
                    updated = true;
                }
            }
            if (!updated) break;
        }

        return maxProb[end_node];
    }
};fs