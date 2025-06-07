-- -- -- -- -- -- -- -- -GFG - POTD - 07 / 06 / 2025 ----------------------------------------
Longest Span in two Binary Arrays
Difficulty: MediumAccuracy: 48.22%Submissions: 20K+Points: 4
Given two binary arrays, a1[] and a2[]. Find the length of longest common span (i, j) where j>= i such that a1[i] + a1[i+1] + .... + a1[j] =  a2[i] + a2[i+1] + ... + a2[j].

Examples:

Input: a1[] = [0, 1, 0, 0, 0, 0], a2[] = [1, 0, 1, 0, 0, 1]
Output: 4
Explanation: The longest span with same sum is from index 1 to 4 following zero based indexing.
Input: a1[] = [0, 1, 0, 1, 1, 1, 1], a2[] = [1, 1, 1, 1, 1, 0, 1]
Output: 6
Explanation: The longest span with same sum is from index 1 to 6 following zero based indexing.
Constraints:
1 <= a1.size() = a2.size() <= 106
0 <= a1[i], a2[i] <= 1

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        // Code here.
        int n=a1.size();
        unordered_map<int,int> mpp;
        
        int sum=0;
        int maxi=0;
        
        mpp[0]=-1;
        
        for(int i=0;i<n;i++){
            sum+=(a1[i]-a2[i]);
            if(mpp.find(sum)!=mpp.end()){
                maxi=max(maxi,i-mpp[sum]);
            }
            else{
                mpp[sum]=i;
            }
        }
        return maxi;
    }
};
-- -- -- -- -- -- -- -- -Leetcode - POTD - 07 / 06 / 2025 ----------------------------------------

3170. Lexicographically Minimum String After Removing Stars
Solved
Medium
Topics
premium lock icon
Companies
You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.

 

Example 1:

Input: s = "aaba*"

Output: "aab"

Explanation:

We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.

Example 2:

Input: s = "abc"

Output: "abc"

Explanation:

There is no '*' in the string.

 

Constraints:

1 <= s.length <= 105
s consists only of lowercase English letters and '*'.
The input is generated such that it is possible to delete all '*' characters.


