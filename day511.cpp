-- -- -- -- -- -- -- -- -GFG - POTD - 22 / 05 / 2025 ----------------------------------------

Minimum Deletions
Difficulty: MediumAccuracy: 58.8%Submissions: 67K+Points: 4
Given a string s, write a program to delete the minimum number of characters from the string so that the resultant string is a palindrome, while maintaining the order of characters.

Examples:

Input: s = "aebcbda"
Output: 2
Explanation: Remove characters 'e' and 'd'.
Input: s = "geeksforgeeks"
Output: 8
Explanation: To make "geeksforgeeks" a palindrome, the longest palindromic subsequence is "eefee" (length 5). The minimum deletions are:
13 (length of s) - 5 = 8.
Constraints:
1 ≤ s.size() ≤ 103

Expected Complexities
Time Complexity: O(n^2)
Auxiliary Space: O(n)

class Solution {
  public:
    int minDeletions(string s) {
        // code here
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        vector<int> dp1(n+1,0),dp2(n+1,0);
        string s2=s;
        reverse(s2.begin(),s2.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s2[j-1]){
                    dp2[j]=1+dp1[j-1];
                }else{
                    dp2[j]=max(dp2[j-1],dp1[j]);
                }
            }
            dp1=dp2;
        }
    return n-dp2[n];
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 22 / 05 / 2025 ----------------------------------------

3362. Zero Array Transformation III
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].

Each queries[i] represents the following action on nums:

Decrement the value at each index in the range [li, ri] in nums by at most 1.
The amount by which the value is decremented can be chosen independently for each index.
A Zero Array is an array with all its elements equal to 0.

Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

 

Example 1:

Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]

Output: 1

Explanation:

After removing queries[2], nums can still be converted to a zero array.

Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
Example 2:

Input: nums = [1,1,1,1], queries = [[1,3],[0,2],[1,3],[1,2]]

Output: 2

Explanation:

We can remove queries[2] and queries[3].

Example 3:

Input: nums = [1,2,3,4], queries = [[0,3]]

Output: -1

Explanation:

nums cannot be converted to a zero array even after using all the queries.

 

Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 105
1 <= queries.length <= 105
queries[i].length == 2
0 <= li <= ri < nums.length