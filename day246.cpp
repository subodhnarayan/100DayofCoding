-- -- -- -- -- -- -- -- -GFG - POTD - 31 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Longest Consecutive Subsequence
Difficulty: MediumAccuracy: 33.0%Submissions: 331K+Points: 4
Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Examples:

Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
Output: 6
Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.
Input: arr[] = [1, 9, 3, 10, 4, 20, 2]
Output: 4
Explanation: 1, 2, 3, 4 is the longest consecutive subsequence.
Input: arr[] = [15, 13, 12, 14, 11, 10, 9]
Output: 7
Explanation: The longest consecutive subsequence is 9, 10, 11, 12, 13, 14, 15, which has a length of 7.
Constraints:
1 <= arr.size() <= 105
0 <= arr[i] <= 105



class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& nums) {
       
       int n=nums.size();
        int longest=1;
        if(n==0){
            return 0;
        }
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
            
            while(st.find(x+1)!=st.end()){
                x=x+1;
                cnt=cnt+1;
            }
            longest=max(longest,cnt);
        }
        }
        return longest;

    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 31 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -



983. Minimum Cost For Tickets
Solved
Medium
Topics
Companies
You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

Train tickets are sold in three different ways:

a 1-day pass is sold for costs[0] dollars,
a 7-day pass is sold for costs[1] dollars, and
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.

For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
Return the minimum number of dollars you need to travel every day in the given list of days.

 

Example 1:

Input: days = [1,4,6,7,8,20], costs = [2,7,15]
Output: 11
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 1-day pass for costs[0] = $2, which covered day 1.
On day 3, you bought a 7-day pass for costs[1] = $7, which covered days 3, 4, ..., 9.
On day 20, you bought a 1-day pass for costs[0] = $2, which covered day 20.
In total, you spent $11 and covered all the days of your travel.
Example 2:

Input: days = [1,2,3,4,5,6,7,8,9,10,30,31], costs = [2,7,15]
Output: 17
Explanation: For example, here is one way to buy passes that lets you travel your travel plan:
On day 1, you bought a 30-day pass for costs[2] = $15 which covered days 1, 2, ..., 30.
On day 31, you bought a 1-day pass for costs[0] = $2 which covered day 31.
In total, you spent $17 and covered all the days of your travel.
 

Constraints:

1 <= days.length <= 365
1 <= days[i] <= 365
days is in strictly increasing order.
costs.length == 3
1 <= costs[i] <= 1000


class Solution {
public:
     vector<int> dp; 
    int mincostTickets(vector<int>& days, vector<int>& costs) {
         int n=days.size();
        dp.assign(n, -1);
        function<int(int)> f=[&](int i) mutable
        {
            if (i>=n) return 0;
            if (dp[i]!=-1) return dp[i];
            int ans=INT_MAX;
            int j=i;
            int d=days[i];
            
            while(j<n && days[j]<d+1) j++;
            ans=min(ans, f(j)+costs[0]);
            while( j<n && days[j]<d+7) j++;
            ans=min(ans, f(j)+costs[1]);
            while( j<n && days[j]<d+30) j++;
            ans=min(ans, f(j)+costs[2]);            
            return dp[i]=ans;   
        };
        return f(0); 


    }
};

