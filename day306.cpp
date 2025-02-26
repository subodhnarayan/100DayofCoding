Maximum of minimum for every window size
Difficulty: HardAccuracy: 42.9%Submissions: 54K+Points: 8Average Time: 45m
Given an array of integers arr[], the task is to find the maximum of the minimum values for every possible window size in the array, where the window size ranges from 1 to arr.size().

More formally, for each window size k, determine the smallest element in all windows of size k, and then find the largest value among these minimums where 1<=k<=arr.size().

Examples :

Input: arr[] = [10, 20, 30, 50, 10, 70, 30]
Output: [70, 30, 20, 10, 10, 10, 10] 
Explanation: 
1. First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of size 1 are [10], [20], [30], [50], [10], [70] and [30]. Maximum of these minimums is 70. 
2. Second element in output indicates maximum of minimums of all windows of size 2. Minimums of windows of size 2 are [10], [20], [30], [10], [10], and [30]. Maximum of these minimums is 30. 
3. Third element in output indicates maximum of minimums of all windows of size 3. Minimums of windows of size 3 are [10], [20], [10], [10] and [10]. Maximum of these minimums is 20. 
Similarly other elements of output are computed.
Input: arr[] = [10, 20, 30]
Output: [30, 20, 10]
Explanation: First element in output indicates maximum of minimums of all windows of size 1. Minimums of windows of size 1 are [10] , [20] , [30]. Maximum of these minimums are 30 and similarly other outputs can be computed
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 106

class Solution {
    public:
      vector<int> maxOfMins(vector<int>& arr) {
          // Your code here
          
             stack<int>st;
            stack<int>st2;
            int n=arr.size();
            vector<int>left(n,-1);
            vector<int>right(n,n);
            for(int i=0;i<n;i++)
            {
                while(!st.empty() && arr[i]<=arr[st.top()])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    left[i]=-1;
                }
                else{
                    left[i]=st.top();
                }
                st.push(i);
            }
            for(int i=n-1;i>=0;i--)
            {
                while(!st2.empty() && arr[i]<=arr[st2.top()])
                {
                    st2.pop();
                }
                if(st2.empty())
                {
                    right[i]=n;
                }
                else{
                    right[i]=st2.top();
                }
                st2.push(i);
            }
            
            vector<int>ans(n,0);
            for(int i=0;i<n;i++)
            {
                int mx=right[i]-left[i]-1;
                ans[mx-1]=max(ans[mx-1],arr[i]);
            }
            for(int i=n-2;i>=0;i--)
            {
                ans[i]=max(ans[i],ans[i+1]);
            }
            return ans;
      }
  };