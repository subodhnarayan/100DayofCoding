
- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 10 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Circle of strings
Difficulty: HardAccuracy: 15.56%Submissions: 78K+Points: 8
Given an array arr of lowercase strings, determine if the strings can be chained together to form a circle.
A string X can be chained together with another string Y if the last character of X is the same as the first character of Y. If every string of the array can be chained with exactly two strings of the array(one with the first character and the second with the last character of the string), it will form a circle.

For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"

Examples

Input: arr[] = ["abc", "bcd", "cdf"]
Output: 0
Explaination: These strings can't form a circle because no string has 'd'at the starting index.
Input: arr[] = ["ab" , "bc", "cd", "da"]
Output: 1
Explaination: These strings can form a circle of strings.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints: 
1 ≤ length of strings ≤ 20






class Solution {
  public:
  
    void dfs(int node, vector<int> adj[], vector<int> &vis){
        
        vis[node] = 1;
        
        for(auto &adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, adj, vis);
            }
        }
        
    }
    int isCircle(vector<string> &arr) {
        // code here
       // int n=arr.size();
        // for(int i=0;i<n-1;i++){
        //     string fr=arr[i];
        //     string sc=arr[i+1];
            
        //     if(fr[fr.size()-1]!=sc[0]){
        //         return 0;
        //     }
        // }
        
        // string fr=arr[0];
        // string sc=arr[n-1];
        
        // if(sc[sc.size()-1]!=fr[0]){
        //     return 0;
        // }
        
        // return 1;
        
        
         int n = arr.size();
        
        // Step 1: Create a adjacency list, indegree and outdegree
        vector<int> adj[26];
        vector<int> inDeg(26, 0), outDeg(26, 0);
        for(auto it : arr){
            int u = it[0] - 'a';
            int v = it[it.size() - 1] - 'a';
            adj[u].push_back(v);
            inDeg[v]++;
            outDeg[u]++;
        }
        
        // Step 2: If indegree and outdegree of any node is not equal
        // then circle is impossible
        for(int i=0; i<26; i++){
            if(inDeg[i] != outDeg[i])
               return 0;
        }
        
        // Step 3: Check for strongly connected component
        vector<int> vis(26, 0);
        dfs(arr[0][0] - 'a', adj, vis);
        
        // Step 4: If any node whose indeg or outdeg is not zero and not visited
        // then circle is impossible
        for(int i=0; i<26; i++){
            if(inDeg[i] and !vis[i])
               return 0;
        }
        
        return 1;
        
        
    }
};


 -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 10 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
