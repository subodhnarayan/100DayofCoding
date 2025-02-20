-- -- -- -- -- -- -- -- -GFG - POTD - 19 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Find median in a stream
Difficulty: HardAccuracy: 30.34%Submissions: 137K+Points: 8Average Time: 45m
Given a data stream arr[] where integers are read sequentially, the task is to determine the median of the elements encountered so far after each new integer is read.

There are two cases for median on the basis of data set size.

1. If the data set has an odd number then the middle one will be consider as median.
2. If the data set has an even number then there is no distinct middle value and the median will be the arithmetic mean of the two middle values.

Examples:

Input:  arr[] = [5, 15, 1, 3, 2, 8]
Output: [5.0, 10.0, 5.0, 4.0, 3.0, 4.0] 
Explanation: 
After reading 1st element of stream – 5 -> median = 5.0
After reading 2nd element of stream – 5, 15 -> median = (5+15)/2 = 10.0 
After reading 3rd element of stream – 5, 15, 1 -> median = 5.0
After reading 4th element of stream – 5, 15, 1, 3 ->  median = (3+5)/2 = 4.0
After reading 5th element of stream – 5, 15, 1, 3, 2 -> median = 3.0
After reading 6th element of stream – 5, 15, 1, 3, 2, 8 ->  median = (3+5)/2 = 4.0
Input: arr[] = [2, 2, 2, 2]
Output: [2.0, 2.0, 2.0, 2.0]
Explanation: 
After reading 1st element of stream – 2 -> median = 2.0
After reading 2nd element of stream – 2, 2 -> median = (2+2)/2 = 2.0
After reading 3rd element of stream – 2, 2, 2 -> median = 2.0
After reading 4th element of stream – 2, 2, 2, 2 ->  median = (2+2)/2 = 2.0
Constraints:
1 <= arr.size() <= 105
1 <= x <= 10





class Solution {
    public:
      vector<double> getMedian(vector<int> &arr) {
          // vector<double> ans;
          // vector<int> res;
          // for(int i=0;i<arr.size();i++){
          //     res.push_back(arr[i]);
          //     int n=res.size();
          //     sort(res.begin(),res.end());
          //     if(n%2==1){
          //         ans.push_back(res[(n/2)]/1.0);
          //     }
          //     else{
          //         ans.push_back((res[(n/2)-1]+res[n/2])/2.0);
          //     }
          // }
          
          // return ans;
          
      vector<double> ans;
      priority_queue<int> leftMaxHeap;  // Max-heap for left half
      priority_queue<int, vector<int>, greater<int>> rightMinHeap; // Min-heap for right half
  
      for (int num : arr) {
          if (leftMaxHeap.empty() || num <= leftMaxHeap.top()) {
              leftMaxHeap.push(num);
          } else {
              rightMinHeap.push(num);
          }
  
          // Balance the heaps
          if (leftMaxHeap.size() > rightMinHeap.size() + 1) {
              rightMinHeap.push(leftMaxHeap.top());
              leftMaxHeap.pop();
          } else if (rightMinHeap.size() > leftMaxHeap.size()) {
              leftMaxHeap.push(rightMinHeap.top());
              rightMinHeap.pop();
          }
  
          // Find median
          if (leftMaxHeap.size() > rightMinHeap.size()) {
              ans.push_back(leftMaxHeap.top());
          } else {
              ans.push_back((leftMaxHeap.top() + rightMinHeap.top()) / 2.0);
          }
      }
  
      return ans;
      }
  };

-- -- -- -- -- -- -- -- -LeetCode - POTD - 19 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


