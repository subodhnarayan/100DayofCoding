-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFg - POTD - 2 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Edit Distance
Difficulty: HardAccuracy: 35.14%Submissions: 209K+Points: 8
Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.
Examples:

Input: str1 = "geek", srt2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e'.
Input : str1 = "gfg", str2 = "gfg"
Output: 0
Explanation: Both strings are same.
Expected Time Complexity: O(|str1|*|str2|)
Expected Space Complexity: O(|str1|*|str2|)

Constraints:
1 ≤ str1.length(), str2.length() ≤ 100
Both the strings are in lowercase.

class Solution {
  public:
  int solve(string &str1,string &str2,int i,int j,vector<vector<int>>&dp){
      if(i==str1.length()&&j!=str2.length()){
          return str2.length()-j;
      }
      
      if(j==str2.length()&&i!=str1.length()){
          return str1.length()-i;
      }
      
      if(i==str1.length()&&j==str2.length()){
          return 0;
      }
      if(dp[i][j]!=-1){
          return dp[i][j];
      }
      
      int ans=0;
      if(str1[i]==str2[j]){
          return solve(str1,str2,i+1,j+1,dp);
      }else{
          // insert
          int insert=solve(str1,str2,i,j+1,dp)+1;
          // remove
          int remove=solve(str1,str2,i+1,j,dp)+1;
         // replace
         int replace=solve(str1,str2,i+1,j+1,dp)+1;
         
         dp[i][j]=min(insert,min(remove,replace));
      }
      return dp[i][j];
      
      
  }
    int editDistance(string str1, string str2) {
        // Code here
         int n=str1.length();
        int m=str2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=solve(str1,str2,0,0,dp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -leetcode- POTD - 2 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Code
Testcase
Testcase
Test Result
2134. Minimum Swaps to Group All 1's Together II
Solved
Medium
Topics
Companies
Hint
A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

 

Example 1:

Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.
Example 2:

Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.
Example 3:

Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.
 

Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOnes = 0;
        
        // Count total number of 1's and create a doubled array
        vector<int> doubledNums(2 * n);
        for (int i = 0; i < n; i++) {
            totalOnes += nums[i];
            doubledNums[i] = doubledNums[i + n] = nums[i];
        }
        
        // Edge cases
        if (totalOnes == 0 || totalOnes == n) return 0;
        
        // Create cumulative sum array
        vector<int> cumulativeSum(2 * n + 1, 0);
        for (int i = 0; i < 2 * n; i++) {
            cumulativeSum[i + 1] = cumulativeSum[i] + doubledNums[i];
        }
        
        int maxOnesInWindow = 0;
        
        // Check all possible windows of size totalOnes
        for (int i = 0; i <= n; i++) {
            int onesInWindow = cumulativeSum[i + totalOnes] - cumulativeSum[i];
            maxOnesInWindow = max(maxOnesInWindow, onesInWindow);
        }
        
        return totalOnes - maxOnesInWindow;
    }
};