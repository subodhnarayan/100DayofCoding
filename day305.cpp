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


