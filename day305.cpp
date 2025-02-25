-- -- -- -- -- -- -- -- -GFG - POTD - 25 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Histogram Max Rectangular Area
Difficulty: HardAccuracy: 32.12%Submissions: 185K+Points: 8
You are given a histogram represented by an array arr, where each element of the array denotes the height of the bars in the histogram. All bars have the same width of 1 unit.

Your task is to find the largest rectangular area possible in the given histogram, where the rectangle can be formed using a number of contiguous bars.

Examples:

Input: arr[] = [60, 20, 50, 40, 10, 50, 60]
 Largest-Rectangular-Area-in-a-Histogram
Output: 100
Explanation: We get the maximum by picking bars highlighted above in green (50, and 60). The area is computed (smallest height) * (no. of the picked bars) = 50 * 2 = 100.
Input: arr[] = [3, 5, 1, 7, 5, 9]
Output: 15
Explanation:  We get the maximum by picking bars 7, 5 and 9. The area is computed (smallest height) * (no. of the picked bars) = 5 * 3 = 15.
Input: arr[] = [3]
Output: 3
Explanation: In this example the largest area would be 3 of height 3 and width 1.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 104

class Solution {
    public:
    
    vector<int> prevSmall(vector<int> arr){
        int n=arr.size();
        vector<int> res(n);
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    
    vector<int> nextSmall(vector<int> arr){
        int n=arr.size();
        vector<int> res(n);
        stack<int> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            res[i]=st.top();
            st.push(i);
        }
        return res;
    }
    
    
      int getMaxArea(vector<int> &arr) {
          vector<int> next=nextSmall(arr);
          vector<int> prev=prevSmall(arr);
          int n=arr.size();
          int maxArea=0;
          for(int i=0;i<n;i++){
              int length=arr[i];
              if(next[i]==-1){
                  next[i]=n;
              }
              
            int width=next[i]-prev[i]-1;
            int area=(int)(length*width);
            maxArea=max(maxArea,area);
          }
          
          return maxArea;
      }
  };



-- -- -- -- -- -- -- -- -LeetCode - POTD - 25 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


1524. Number of Sub-arrays With Odd Sum
Solved
Medium
Topics
Companies
Hint
Given an array of integers arr, return the number of subarrays with an odd sum.

Since the answer can be very large, return it modulo 109 + 7.

 

Example 1:

Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.
Example 2:

Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.
Example 3:

Input: arr = [1,2,3,4,5,6,7]
Output: 16
 

Constraints:

1 <= arr.length <= 105
1 <= arr[i] <= 100