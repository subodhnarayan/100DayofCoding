-- -- -- -- -- -- -- -- -GFG - POTD - 30 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
sa
Anagram
Difficulty: EasyAccuracy: 44.93%Submissions: 357K+Points: 2
Given two strings s1 and s2 consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, act and tac are an anagram of each other. Strings s1 and s2 can only contain lowercase alphabets.

Note: You can assume both the strings s1 & s2 are non-empty.

Examples :

Input: s1 = "geeks", s2 = "kseeg"
Output: true
Explanation: Both the string have same characters with same frequency. So, they are anagrams.
Input: s1 = "allergy", s2 = "allergic"
Output: false
Explanation: Characters in both the strings are not same, so they are not anagrams.
Input: s1 = "g", s2 = "g"
Output: true
Explanation: Character in both the strings are same, so they are anagrams.
Constraints:
1 ≤ s1.size(), s2.size() ≤ 105


class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        map<char,int> mp1,mp2;
        int n1=s1.size();
        int n2=s2.size();
        if(n1!=n2) return false;
        for(char c:s1){
            mp1[c]++;
        }
        for(char c:s2){
            mp2[c]++;
        }
        return mp1==mp2;
        
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 30 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.

Return any valid arrangement of pairs.

Note: The inputs will be generated such that there exists a valid arrangement of pairs.

 

Example 1:

Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
Output: [[11,9],[9,4],[4,5],[5,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 9 == 9 = start1 
end1 = 4 == 4 = start2
end2 = 5 == 5 = start3
Example 2:

Input: pairs = [[1,3],[3,2],[2,1]]
Output: [[1,3],[3,2],[2,1]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 3 == 3 = start1
end1 = 2 == 2 = start2
The arrangements [[2,1],[1,3],[3,2]] and [[3,2],[2,1],[1,3]] are also valid.
Example 3:

Input: pairs = [[1,2],[1,3],[2,1]]
Output: [[1,2],[2,1],[1,3]]
Explanation:
This is a valid arrangement since endi-1 always equals starti.
end0 = 2 == 2 = start1
end1 = 1 == 1 = start2
 

Constraints:

1 <= pairs.length <= 105
pairs[i].length == 2
0 <= starti, endi <= 109
starti != endi
No two pairs are exactly the same.
There exists a valid arrangement of pairs.


class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjacencyList;
        unordered_map<int, int> inOutDegree;
        
        // Build graph and count in/out degrees
        for (const auto& pair : pairs) {
            adjacencyList[pair[0]].push_back(pair[1]);
            inOutDegree[pair[0]]++;  // out-degree
            inOutDegree[pair[1]]--;  // in-degree
        }
        
        // Find starting node
        int startNode = pairs[0][0];
        for (const auto& [node, degree] : inOutDegree) {
            if (degree == 1) {
                startNode = node;
                break;
            }
        }
        
        vector<int> path;
        stack<int> nodeStack;
        nodeStack.push(startNode);
        
        while (!nodeStack.empty()) {
            auto& neighbors = adjacencyList[nodeStack.top()];
            if (neighbors.empty()) {
                path.push_back(nodeStack.top());
                nodeStack.pop();
            } else {
                int nextNode = neighbors.back();
                nodeStack.push(nextNode);
                neighbors.pop_back();
            }
        }
        
        vector<vector<int>> arrangement;
        int pathSize = path.size();
        arrangement.reserve(pathSize - 1);
        
        for (int i = pathSize - 1; i > 0; --i) {
            arrangement.push_back({path[i], path[i-1]});
        }
        
        return arrangement;
    }
};
