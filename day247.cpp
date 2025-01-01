-- -- -- -- -- -- -- -- -GFG - POTD - 01 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Print Anagrams Together
Difficulty: MediumAccuracy: 65.78%Submissions: 82K+Points: 4
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

Note: The final output will be in lexicographic order.

Examples:

Input: arr[] = ["act", "god", "cat", "dog", "tac"]
Output: [["act", "cat", "tac"], ["god", "dog"]]
Explanation: There are 2 groups of anagrams "god", "dog" make group 1. "act", "cat", "tac" make group 2.
Input: arr[] = ["no", "on", "is"]
Output: [["is"], ["no", "on"]]
Explanation: There are 2 groups of anagrams "is" makes group 1. "no", "on" make group 2.
Input: arr[] = ["listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"]
Output: [["abc", "cab", "bac"], ["listen", "silent", "enlist"], ["rat", "tar", "art"]]
Explanation: 
Group 1: "abc", "bac", and "cab" are anagrams.
Group 2: "listen", "silent", and "enlist" are anagrams.
Group 3: "rat", "tar", and "art" are anagrams.
Constraints:
1<= arr.size() <=100
1<= arr[i].size() <=10



class Solution {
  public:
  
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
          map<string,vector<string>> anagram;
        
        for(auto str:arr){
            string sortedString = str;
            sort(sortedString.begin(),sortedString.end());
            anagram[sortedString].push_back(str);
        }
        
        vector<vector<string>> ans;
        
        for(auto i :anagram){
            // sort(i.second.begin(),i.second.end());
            ans.push_back(i.second);
        }
        
        return ans;
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 01 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -




