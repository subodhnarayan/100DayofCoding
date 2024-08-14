-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 14 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Longest Common Substring
Difficulty: MediumAccuracy: 42.69%Submissions: 232K+Points: 4
You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.

Examples:

Input: str1 = "ABCDGH", str2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.
Input: str1 = "ABC", str2 = "ACB"
Output: 1
Explanation: The longest common substrings are "A", "B", "C" all having length 1.
Expected Time Complexity: O(n*m).
Expected Auxiliary Space: O(n*m).

Constraints:
1<= str1.size(), str2.size()<=1000
Both strings may contain upper and lower case alphabets.

class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
    int n=str1.length(), m=str2.length();
        
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        int maxi=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(str1[i]==str2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                    maxi=max(maxi, dp[i+1][j+1]);
                }
            }
        }
        return maxi;

    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 14 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


719. Find K-th Smallest Pair Distance
Solved
Hard
Topics
Companies
Hint
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

 

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.
Example 2:

Input: nums = [1,1,1], k = 2
Output: 0
Example 3:

Input: nums = [1,6,1], k = 3
Output: 5
 

Constraints:

n == nums.length
2 <= n <= 104
0 <= nums[i] <= 106
1 <= k <= n * (n - 1) / 2


