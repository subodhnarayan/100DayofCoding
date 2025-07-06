------------------------------------------------------GFG POTD 07/06/2025 --------------------------------------------
  Maximum Sum Combination
Difficulty: MediumAccuracy: 49.69%Submissions: 89K+Points: 4Average Time: 30m
You are given two integer arrays a[] and b[] of equal size. A sum combination is formed by adding one element from a[] and one from b[], using each index pair (i, j) at most once. Return the top k maximum sum combinations, sorted in non-increasing order.

Examples:

Input: a[] = [3, 2], b[] = [1, 4], k = 2
Output: [7, 6]
Explanation: Possible sums: 3 + 1 = 4, 3 + 4 = 7, 2 + 1 = 3, 2 + 4 = 6, Top 2 sums are 7 and 6.
Input: a[] = [1, 4, 2, 3], b[] = [2, 5, 1, 6], k = 3
Output: [10, 9, 9]
Explanation: The top 3 maximum possible sums are : 4 + 6 = 10, 3 + 6 = 9, and 4 + 5 = 9
Constraints:
1 ≤ a.size() = b.size() ≤ 105
1 ≤ k ≤ a.size()
1 ≤ a[i], b[i] ≤ 104

Expected Complexities
Time Complexity: O(n log n)
Auxiliary Space: O(n)

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        sort(a.begin(), a.end(), greater <int> ());
        sort(b.begin(), b.end(), greater <int> ());
        
        priority_queue <pair <int, pair<int, int>>> pq;
        map <pair <int, int>, bool> vis;
        
        pq.push({a[0] + b[0], {0, 0}});
        vis[{0, 0}] = true;
        vector <int> res;
        
        while(res.size() < k){
            int sum = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            res.push_back(sum);
            pq.pop();
            
            if(i+1 < n && !vis[{i+1, j}]){
                vis[{i+1, j}] = true;
                pq.push({a[i+1] + b[j], {i+1, j}});
            }
            if(j+1 < n && !vis[{i, j+1}]){
                vis[{i, j+1}] = true;
                pq.push({a[i] + b[j+1], {i, j+1}});
            }
        }
        
        return res;
    }
};

