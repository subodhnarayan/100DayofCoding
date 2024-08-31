- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 31 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Sorted subsequence of size 3
Difficulty: MediumAccuracy: 25.95%Submissions: 68K+Points: 4
You are given an array arr, you need to find any three elements in it such that arr[i] < arr[j] < arr[k] and i < j < k.

Note:

The output will be 1 if the subsequence returned by the function is present in the array arr
If the subsequence is not present in the array then return an empty array, the driver code will print 0.
If the subsequence returned by the function is not in the format as mentioned then the output will be -1.
Examples :

Input: arr = [1, 2, 1, 1, 3]
Output: 1
Explanation: A subsequence 1 2 3 exist.
Input: arr = [1, 1, 3]
Output: 0
Explanation: No such Subsequence exist, so empty array is returned (the driver code automatically prints 0 in this case).
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 106



class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n=arr.size();
        vector<int> leftsmall(n);
        vector<int> rightlar(n);
        
        leftsmall[0]=arr[0];
        
        for(int i=1;i<n;i++){
            leftsmall[i]=min(arr[i],leftsmall[i-1]);
        }
        
        rightlar[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightlar[i]=max(rightlar[i+1],arr[i]);
        }
        
        for(int i=1;i<=n-2;i++){
            if(leftsmall[i-1]<arr[i] and arr[i]<rightlar[i+1]){
                return {leftsmall[i-1],arr[i],rightlar[i+1]};
            }
        }
       return {};
        
    }
};



- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 31 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

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
};