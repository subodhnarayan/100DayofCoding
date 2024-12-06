-- -- -- -- -- -- -- -- -GFG - POTD - 05 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Find H-Index
Difficulty: MediumAccuracy: 53.4%Submissions: 22K+Points: 4
Given an integer array citations[], where citations[i] is the number of citations a researcher received for the ith paper. The task is to find the H-index.

H-Index is the largest value such that the researcher has at least H papers that have been cited at least H times.

Examples:

Input: citations[] = [3, 0, 5, 3, 0]
Output: 3
Explanation: There are at least 3 papers (3, 5, 3) with at least 3 citations.
Input: citations[] = [5, 1, 2, 4, 1]
Output: 2
Explanation: There are 3 papers (with citation counts of 5, 2, and 4) that have 2 or more citations. However, the H-Index cannot be 3 because there aren't 3 papers with 3 or more citations.
Input: citations[] = [0, 0]
Output: 0
Constraints:
1 ≤ citations.size() ≤ 106
0 ≤ citations[i] ≤ 106


class Solution {
  public:
    // Function to find hIndex
    bool check(vector<int>&arr, int t){
        int cnt=0;
        int n=arr.size();
        for(int i=0; i<n; i++){
            if(arr[i]>=t) cnt++;
        }
        if(cnt>=t) return 1;
        else return 0;
    }
    int hIndex(vector<int>& citations) {
        // code here
         int maxi=-1e9, mini=1e9;
      int  n=citations.size();
        
        for(int i=0; i<n; i++){
            maxi=max(maxi, citations[i]);
            mini=min(mini, citations[i]);
        }
        
        int lo=min(0, mini), hi=max(maxi, n);
        int ans=0;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(citations, mid)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 05 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

2554. Maximum Number of Integers to Choose From a Range I
Solved
Medium
Topics
Companies
Hint
You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:

The chosen integers have to be in the range [1, n].
Each integer can be chosen at most once.
The chosen integers should not be in the array banned.
The sum of the chosen integers should not exceed maxSum.
Return the maximum number of integers you can choose following the mentioned rules.

 

Example 1:

Input: banned = [1,6,5], n = 5, maxSum = 6
Output: 2
Explanation: You can choose the integers 2 and 4.
2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
Example 2:

Input: banned = [1,2,3,4,5,6,7], n = 8, maxSum = 1
Output: 0
Explanation: You cannot choose any integer while following the mentioned conditions.
Example 3:

Input: banned = [11], n = 7, maxSum = 50
Output: 7
Explanation: You can choose the integers 1, 2, 3, 4, 5, 6, and 7.
They are from the range [1, 7], all did not appear in banned, and their sum is 28, which did not exceed maxSum.
 

Constraints:

1 <= banned.length <= 104
1 <= banned[i], n <= 104
1 <= maxSum <= 109


class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
         unordered_set<int> bannedSet(banned.begin(), banned.end());
        
        long long sum = 0; // Track cumulative sum
        int count = 0;     // Track count of valid numbers

        // Iterate through 1 to n
        for (int i = 1; i <= n; i++) {
            if (bannedSet.count(i)) continue; // Skip banned numbers
            sum += i; // Add current number to the sum
            if (sum > maxSum) break; // Stop if sum exceeds maxSum
            count++; // Increment count of valid numbers
        }

        return count; // Return the count of valid numbers
    }
};