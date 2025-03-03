-- -- -- -- -- -- -- -- -GFG - POTD - 03 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Longest Bounded-Difference Subarray
Difficulty: MediumAccuracy: 59.11%Submissions: 11K+Points: 4
Given an array of positive integers arr[] and a non-negative integer x, the task is to find the longest sub-array where the absolute difference between any two elements is not greater than x.
If multiple such subarrays exist, return the one that starts at the smallest index.

Examples: 

Input: arr[] = [8, 4, 2, 6, 7], x = 4 
Output: [4, 2, 6] 
Explanation: The sub-array described by index [1..3], i.e. [4, 2, 6] contains no such difference of two elements which is greater than 4.
Input: arr[] = [15, 10, 1, 2, 4, 7, 2], x = 5 
Output: [2, 4, 7, 2] 
Explanation: The sub-array described by indexes [3..6], i.e. [2, 4, 7, 2] contains no such difference of two elements which is greater than 5. 
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 109
0 <= x<= 109

Time Complexity: O(n)Auxiliary Space: O(n)


class Solution {
    public:
      vector<int> longestSubarray(vector<int>& arr, int x) {
          // code here
          int n=arr.size();
          deque<int> mn,mx;
          int en=0,st=0;
          int i=0,j=0;
          
          while(j<n){
              while(!mn.empty() && mn.back()>arr[j]) mn.pop_back();
              while(!mx.empty() && mx.back()<arr[j]) mx.pop_back();
              mn.push_back(arr[j]);
              mx.push_back(arr[j]);
              
              if(mx.front()-mn.front()<=x){
                  if((en-st)<(j-i)) {
                      en=j;
                      st=i;
                  }
                  j++;
              } else{ //mx.front()-mn.front()>x
                  if(arr[i]==mx.front()) mx.pop_front();
                  if(arr[i]==mn.front()) mn.pop_front();
                  i++;
                  j++;
              }
          }
          
          if(en==st) return {arr[0]}; //If multiple such subarrays exist, return the one that starts at the smallest inde
          vector<int> res;
          for(int i=st;i<=en;i++) res.push_back(arr[i]);
          return res;
      }
};


-- -- -- -- -- -- -- -- -LeetCode - POTD - 03 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
