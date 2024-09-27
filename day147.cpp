

K Sized Subarray Maximum
Difficulty: MediumAccuracy: 26.04%Submissions: 343K+Points: 4
Given an array arr[] and an integer k. Find the maximum for each and every contiguous subarray of size k.

Examples:

Input: k = 3, arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6]
Output: [3, 3, 4, 5, 5, 5, 6] 
Explanation: 
1st contiguous subarray = [1 2 3] max = 3
2nd contiguous subarray = [2 3 1] max = 3
3rd contiguous subarray = [3 1 4] max = 4
4th contiguous subarray = [1 4 5] max = 5
5th contiguous subarray = [4 5 2] max = 5
6th contiguous subarray = [5 2 3] max = 5
7th contiguous subarray = [2 3 6] max = 6

Input: k = 4, arr[] = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13]
Output: [10, 10, 10, 15, 15, 90, 90]
Explanation: 
1st contiguous subarray = [8 5 10 7], max = 10
2nd contiguous subarray = [5 10 7 9], max = 10
3rd contiguous subarray = [10 7 9 4], max = 10
4th contiguous subarray = [7 9 4 15], max = 15
5th contiguous subarray = [9 4 15 12], max = 15
6th contiguous subarray = [4 15 12 90], max = 90
7th contiguous subarray = {15 12 90 13}, max = 90
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(k)

Constraints:
1 ≤ sizeof(arr) ≤ 106
1 ≤ k ≤ sizeof(arr)
0 ≤ arr[i] ≤ 109


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
    //   vector<int> ans;
    //   int n=arr.size();
    //   for(int i=0;i<n-k+1;i++){
    //       int cn=0;
    //       for(int j=i;j<i+k;j++){
    //           cn=max(arr[j],cn);
    //       }
    //       ans.push_back(cn);
    //   }
    //   return ans;
    
    
      int n = arr.size();
        int i = 0, j = 1, maxi = 0;
        vector<int> ans;
        
        while(i < k) {
            if(arr[i] > maxi) maxi = arr[i];
            i++;
        }
        ans.push_back(maxi);
        
        while(i < n) {
            if(arr[j-1]==maxi)
                maxi = *max_element(arr.begin()+j,arr.begin()+i+1);
            else if(arr[i]>maxi) 
                maxi = arr[i];
            ans.push_back(maxi);
            i++; j++;
        }
        
        return ans;
    
    }
};





731. My Calendar II
Solved
Medium
Topics
Companies
Hint
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.

A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end), the range of real numbers x such that start <= x < end.

Implement the MyCalendarTwo class:

MyCalendarTwo() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.
 

Example 1:

Input
["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
[[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
Output
[null, true, true, true, false, true, true]

Explanation
MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
myCalendarTwo.book(10, 20); // return True, The event can be booked. 
myCalendarTwo.book(50, 60); // return True, The event can be booked. 
myCalendarTwo.book(10, 40); // return True, The event can be double booked. 
myCalendarTwo.book(5, 15);  // return False, The event cannot be booked, because it would result in a triple booking.
myCalendarTwo.book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
myCalendarTwo.book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.
 

Constraints:

0 <= start < end <= 109
At most 1000 calls will be made to book.



class MyCalendarTwo {
public:
    map<int, int> eventCount;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        eventCount[start]++;
        eventCount[end]--;

        int ongoingEvents = 0;
        for (auto &[time, change] : eventCount) {
            ongoingEvents += change;
            if (ongoingEvents >= 3) {
                eventCount[start]--;
                eventCount[end]++;
                return false;
            }
        }
        return true;
    }
};
