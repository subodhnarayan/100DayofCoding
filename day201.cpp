-- -- -- -- -- -- -- -- -GFG - POTD - 20 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Majority Element II
Difficulty: MediumAccuracy: 48.1%Submissions: 84K+Points: 4
You are given an array of integer arr[] where each number represents a vote to a candidate. Return the candidates that have votes greater than one-third of the total votes, If there's not a majority vote, return an empty array. 

Note: The answer should be returned in an increasing format.

Examples:

Input: arr[] = [2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6]
Output: [5, 6]
Explanation: 5 and 6 occur more n/3 times.
Input: arr[] = [1, 2, 3, 4, 5]
Output: []
Explanation: no candidate occur more than n/3 times.
Constraint:
1 <= arr.size() <= 106
-109 <= arr[i] <= 109


class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& arr) {
        map<int,int> mp;
        vector<int> ans;
        for(int num:arr){
            mp[num]++;
        }
        int n=arr.size();
        int sum=n/3;
        for(const auto& pair:mp){
            if(pair.second>sum){
                ans.push_back(pair.first);
            }
        }
        return ans;
    }
};




-- -- -- -- -- -- -- -- -Leetcode - POTD - 20 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


Code
Testcase
Testcase
Test Result
2516. Take K of Each Character From Left and Right
Solved
Medium
Topics
Companies
Hint
You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

 

Example 1:

Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation: 
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.
Example 2:

Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.
 

Constraints:

1 <= s.length <= 105
s consists of only the letters 'a', 'b', and 'c'.
0 <= k <= s.length
