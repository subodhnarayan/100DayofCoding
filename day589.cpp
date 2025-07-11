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

------------------------------------------------------leetCode POTD 07/06/2025 --------------------------------------------

  1865. Finding Pairs With a Certain Sum
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given two integer arrays nums1 and nums2. You are tasked to implement a data structure that supports queries of two types:

Add a positive integer to an element of a given index in the array nums2.
Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a given value (0 <= i < nums1.length and 0 <= j < nums2.length).
Implement the FindSumPairs class:

FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object with two integer arrays nums1 and nums2.
void add(int index, int val) Adds val to nums2[index], i.e., apply nums2[index] += val.
int count(int tot) Returns the number of pairs (i, j) such that nums1[i] + nums2[j] == tot.
 

Example 1:

Input
["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
[[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1], [1, 1], [7]]
Output
[null, 8, null, 2, 1, null, null, 11]

Explanation
FindSumPairs findSumPairs = new FindSumPairs([1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]);
findSumPairs.count(7);  // return 8; pairs (2,2), (3,2), (4,2), (2,4), (3,4), (4,4) make 2 + 5 and pairs (5,1), (5,5) make 3 + 4
findSumPairs.add(3, 2); // now nums2 = [1,4,5,4,5,4]
findSumPairs.count(8);  // return 2; pairs (5,2), (5,4) make 3 + 5
findSumPairs.count(4);  // return 1; pair (5,0) makes 3 + 1
findSumPairs.add(0, 1); // now nums2 = [2,4,5,4,5,4]
findSumPairs.add(1, 1); // now nums2 = [2,5,5,4,5,4]
findSumPairs.count(7);  // return 11; pairs (2,1), (2,2), (2,4), (3,1), (3,2), (3,4), (4,1), (4,2), (4,4) make 2 + 5 and pairs (5,3), (5,5) make 3 + 4
 

Constraints:

1 <= nums1.length <= 1000
1 <= nums2.length <= 105
1 <= nums1[i] <= 109
1 <= nums2[i] <= 105
0 <= index < nums2.length
1 <= val <= 105
1 <= tot <= 109
At most 1000 calls are made to add and count each.


  class FindSumPairs {
public:
    vector<int> n1, n2;
    unordered_map<int, int> m;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for (int x : n2) {
            m[x]++;
        }
    }
    
    void add(int i, int v) {
        m[n2[i]]--;
        n2[i] += v;
        m[n2[i]]++;
        
    }
    
    int count(int t) {
         int c = 0;
        for (int x : n1) {
            c += m[t - x];
        }
        return c;
    }
};
  

