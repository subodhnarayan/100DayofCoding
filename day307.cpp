Get Min from Stack
Difficulty: MediumAccuracy: 22.59%Submissions: 264K+Points: 4Average Time: 30m
Given q queries, You task is to implement the following four functions for a stack:

push(x) – Insert an integer x onto the stack.
pop() – Remove the top element from the stack.
peek() - Return the top element from the stack. If the stack is empty, return -1.
getMin() – Retrieve the minimum element from the stack in O(1) time. If the stack is empty, return -1.
Each query can be one of the following:

1 x : Push x onto the stack.
2 : Pop the top element from the stack.
3: Return the top element from the stack. If the stack is empty, return -1.
4: Return the minimum element from the stack.
Examples:

Input: q = 7, queries = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]
Output: [3, 2, 1]
Explanation: 
push(2): Stack is [2]
push(3): Stack is [2, 3]
peek(): Top element is 3
pop(): Removes 3, stack is [2]
getMin(): Minimum element is 2
push(1): Stack is [2, 1]
getMin(): Minimum element is 1
Input: q = 4, queries = [[1, 4], [1, 2], [4], [3]]
Output: [2, 2]
Explanation: 
push(4): Stack is [4]
push(2): Stack is [4, 2]
getMin(): Minimum element is 2
peek(): Top element is 2
Input: q = 5, queries = [[1, 10], [4], [1, 5], [4], [2]]
Output: [10, 5]
Explanation: 
push(10): Stack is [10]
getMin(): Minimum element is 10
push(5): Stack is [10, 5]
getMin(): Minimum element is 5
pop(): Removes 5, stack is [10]
Constraints:
1 <= q <= 105
0 <= values on the stack <= 109

Time Complexity: O(1)Auxiliary Space: O(1)


class Solution {
    public:
     
     stack<long long> st;
      long long m; // Stores the minimum value
      Solution() {
         m = INT_MAX;
      }
      // Add an element to the top of Stack
      void push(int x) {
         if (st.empty()) {
              m = x;
              st.push(0);  // Push 0 to indicate it's the first element
          } else {
              long long y = (long long)x - m; // Prevent overflow
              st.push(y);
              if (y < 0) {
                  m = x;  // Update min if needed
              }
          }
          
      }
  
      // Remove the top element from the Stack
      void pop() {
           if (st.empty()) return;
          
          long long y = st.top();
          st.pop();
  
          if (y < 0) {
              m = m - y; // Restore previous min
          }
             
  
      }
  
      // Returns top element of the Stack
      int peek() {
           if (st.empty()) return -1;
  
          long long y = st.top();
          return (y < 0) ? m : (m + y);
          
      }
  
      // Finds minimum element of Stack
      int getMin() {
          if (st.empty()) return -1;
          return m;
      }
  };






873. Length of Longest Fibonacci Subsequence
Solved
Medium
Topics
Companies
A sequence x1, x2, ..., xn is Fibonacci-like if:

n >= 3
xi + xi+1 == xi+2 for all i + 2 <= n
Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.

A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].

 

Example 1:

Input: arr = [1,2,3,4,5,6,7,8]
Output: 5
Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
Example 2:

Input: arr = [1,3,7,11,12,14,18]
Output: 3
Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].
 

Constraints:

3 <= arr.length <= 1000
1 <= arr[i] < arr[i + 1] <= 109