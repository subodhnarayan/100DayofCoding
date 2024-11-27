-- -- -- -- -- -- -- -- -GFG - POTD - 27 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Smallest Positive Missing Number
Difficulty: MediumAccuracy: 25.13%Submissions: 369K+Points: 4
You are given an integer array arr[]. Your task is to find the smallest positive number missing from the array.

Note: Positive number starts from 1. The array can have negative integers too.

Examples:

Input: arr[] = [2, -3, 4, 1, 1, 7]
Output: 3
Explanation: Smallest positive missing number is 3.
Input: arr[] = [5, 3, 2, 5, 1]
Output: 4
Explanation: Smallest positive missing number is 4.
Input: arr[] = [-8, 0, -1, -4, -3]
Output: 1
Explanation: Smallest positive missing number is 1.
Constraints:  
1 <= arr.size() <= 105
-106 <= arr[i] <= 106


class Solution {
  public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(vector<int> &arr) {
        set<int>st;
        for(int i=0;i<arr.size();i++){
            st.insert(arr[i]);
        }
        for(int i=1;i<=100000;i++){
            if(st.find(i)==st.end()) return i;
        }
        return 0;
    }
};





3243. Shortest Distance After Road Addition Queries I
Solved
Medium
Topics
Companies
Hint
You are given an integer n and a 2D integer array queries.

There are n cities numbered from 0 to n - 1. Initially, there is a unidirectional road from city i to city i + 1 for all 0 <= i < n - 1.

queries[i] = [ui, vi] represents the addition of a new unidirectional road from city ui to city vi. After each query, you need to find the length of the shortest path from city 0 to city n - 1.

Return an array answer where for each i in the range [0, queries.length - 1], answer[i] is the length of the shortest path from city 0 to city n - 1 after processing the first i + 1 queries.

 

Example 1:

Input: n = 5, queries = [[2,4],[0,2],[0,4]]

Output: [3,2,1]

Explanation:



After the addition of the road from 2 to 4, the length of the shortest path from 0 to 4 is 3.



After the addition of the road from 0 to 2, the length of the shortest path from 0 to 4 is 2.



After the addition of the road from 0 to 4, the length of the shortest path from 0 to 4 is 1.

Example 2:

Input: n = 4, queries = [[0,3],[0,2]]

Output: [1,1]

Explanation:



After the addition of the road from 0 to 3, the length of the shortest path from 0 to 3 is 1.



After the addition of the road from 0 to 2, the length of the shortest path remains 1.

 

Constraints:

3 <= n <= 500
1 <= queries.length <= 500
queries[i].length == 2
0 <= queries[i][0] < queries[i][1] < n
1 < queries[i][1] - queries[i][0]
There are no repeated roads among the queries.


class Solution {
public:
   void updateDistances(vector<vector<int>>& graph, int current, vector<int>& distances) {
        int newDist = distances[current] + 1;
        for (int neighbor : graph[current]) {
            if (distances[neighbor] <= newDist) continue;
            distances[neighbor] = newDist;
            updateDistances(graph, neighbor, distances);
        }
    }
    
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> distances(n);
        for (int i = 0; i < n; ++i) {
            distances[i] = n - 1 - i;
        }
        
        vector<vector<int>> graph(n);
        for (int i = 0; i + 1 < n; ++i) {
            graph[i + 1].push_back(i);
        }
        
        vector<int> answer(queries.size());
        int queryIdx = 0;
        
        for (const auto& query : queries) {
            int source = query[0];
            int target = query[1];
            
            graph[target].push_back(source);
            distances[source] = min(distances[source], distances[target] + 1);
            updateDistances(graph, source, distances);
            
            answer[queryIdx++] = distances[0];
        }
        
        return answer;
    }
};