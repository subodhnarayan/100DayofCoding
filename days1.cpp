---------------------------------GFG-- POTD---------------------------------------
  Next Greater Element in Circular Array
Difficulty: MediumAccuracy: 56.97%Submissions: 48K+Points: 4
Given a circular integer array arr[], the task is to determine the next greater element (NGE) for each element in the array.

The next greater element of an element arr[i] is the first element that is greater than arr[i] when traversing circularly. If no such element exists, return -1 for that position.

Circular Property:

Since the array is circular, after reaching the last element, the search continues from the beginning until we have looked at all elements once.

Examples: 

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation:
The next greater element for 1 is 3.
The next greater element for 3 is 4.
The next greater element for 2 is 4.
The next greater element for 4 does not exist, so return -1.
Input: arr[] = [0, 2, 3, 1, 1]
Output: [2, 3, -1, 2, 2]
Explanation:
The next greater element for 0 is 2.
The next greater element for 2 is 3.
The next greater element for 3 does not exist, so return -1.
The next greater element for 1 is 2 (from circular traversal).
The next greater element for 1 is 2 (from circular traversal).
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 106

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

  class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
          int n=arr.size();
      vector<int>ans(2*n);
      
       for(int i=0; i<n; i++){
          ans[i]=arr[i];
          ans[n+i]=arr[i];
      }
      
     
       stack<int>st;
     
       vector<int>result(2*n);
      
       result[result.size()-1]=-1;
      
       st.push(ans[ans.size()-1]);
       
      for(int i=ans.size()-2; i>=0; i--){
         
          
          while(st.size() > 0 && st.top() <= ans[i]){
              st.pop();
          }
          
         if(st.size() > 0) result[i]=st.top();
         else result[i]=-1;
         
          st.push(ans[i]);
          
          
      }
     vector<int>fi(n);
     
      for(int i=0; i<n; i++){
          
          fi[i]=result[i];
          
      }
      return fi;
    }
};



-------------------------------------Leetcode--POTD-------------------------

  1353. Maximum Number of Events That Can Be Attended
Solved
Medium
Topics
premium lock icon
Companies
Hint
You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.

Return the maximum number of events you can attend.

 

Example 1:


Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.
Example 2:

Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4
 

Constraints:

1 <= events.length <= 105
events[i].length == 2
1 <= startDayi <= endDayi <= 105

  class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        int maxDay = 0;
        for (int i = 0; i < events.size(); i++) {
            maxDay = max(maxDay, events[i][1]);
        }
        priority_queue<int, vector<int>, greater<>> pq;
        sort(events.begin(), events.end());
        int ans = 0;
        for (int i = 0, j = 0; i <= maxDay; i++) {
            while (j < n && events[j][0] <= i) {
                pq.emplace(events[j][1]);
                j++;
            }
            while (!pq.empty() && pq.top() < i) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }

        return ans;
    }
};
