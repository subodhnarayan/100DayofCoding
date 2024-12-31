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


