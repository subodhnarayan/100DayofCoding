-- -- -- -- -- -- -- -- -GFG - POTD - 12 / 05 / 2025 ----------------------------------------
Meeting Rooms III
Difficulty: HardAccuracy: 59.33%Submissions: 11K+Points: 8
You are given an integer n representing the number of rooms numbered from 0 to n - 1. Additionally, you are given a 2D integer array meetings[][] where meetings[i] = [starti, endi] indicates that a meeting is scheduled during the half-closed time interval [starti, endi). All starti values are unique.

Meeting Allocation Rules:

When a meeting starts, assign it to the available room with the smallest number.
If no rooms are free, delay the meeting until the earliest room becomes available. The delayed meeting retains its original duration.
When a room becomes free, assign it to the delayed meeting with the earliest original start time.
Determine the room number that hosts the most meetings. If multiple rooms have the same highest number of meetings, return the smallest room number among them.

Examples:

Input: n = 2, meetings[][] = [[0, 6], [2, 3], [3, 7], [4, 8], [6, 8]]
Output: 1
Explanation: Time 0: Both rooms available. [0,6] starts in room 0.
Time 2: Room 0 busy until 6. Room 1 available. [2,3] starts in room 1.
Time 3: Room 1 frees up. [3,7] starts in room 1.
Time 4: Both rooms busy. [4,8] is delayed.
Time 6: Room 0 frees up. Delayed [4,8] starts in room 0 [6,10).
Time 6: [6,8] arrives but both rooms busy. It’s delayed.
Time 7: Room 1 frees up. Delayed [6,8] starts in room 1 [7,9).
Meeting counts: [2, 3]
Input: n = 4, meetings[][] = [[0, 8], [1, 4], [3, 4], [2, 3]
Output: 2
Explanation: Time 0: All rooms available. [0,8] starts in room 0.
Time 1: Room 0 busy until 8. Rooms 1, 2, 3 available. [1,4] starts in room 1.
Time 2: Rooms 0 and 1 busy. Rooms 2, 3 available. [2,3] starts in room 2.
Time 3: Room 2 frees up. [3,4] starts in room 2.
Meeting counts: [1, 1, 2, 0]
Constraints:

1 ≤ n ≤ 104
1 ≤ meetings.size() ≤ 104
meetings[i].size() == 2
0 ≤ starti < endi ≤ 104
Expected Complexities
Time Complexity: O(mlogm + mlogn)
Auxiliary Space: O(n)

class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        // code here
          int m = meetings.size();
        sort(meetings.begin(), meetings.end());
        
        vector <int> freq(n+1, 0);
        priority_queue <int, vector <int>, greater <int>> room;
        priority_queue <pair <int,int>, vector <pair <int,int>>, greater <pair <int,int>>> pq;
        
        for(int i = 0; i < n; i++) room.push(i);
        
        for(int i = 0; i < m; i++){
            int st = meetings[i][0];
            int end = meetings[i][1];
            int duration = end - st;
            
            while(!pq.empty() && st >= pq.top().first) {
                int y = pq.top().second;
                pq.pop();
                room.push(y);
            }
            
            if(room.empty()){
                int x = pq.top().first;
                int y = pq.top().second;
                pq.pop();
                
                pq.push(make_pair(x + duration, y));
                freq[y]++;
            }
            else{
                int book = room.top();
                room.pop();
                
                pq.push(make_pair(meetings[i][1], book));
                freq[book]++;
            }
        }
        
        int roomNum = 0;
        int mx = 0;
        for(int i = 0; i < n; i++){
            if(freq[i] > mx){
                mx = freq[i];
                roomNum = i;
            }
        }
        
        return roomNum;
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 13 / 05 / 2025 ----------------------------------------

2094. Finding 3-Digit Even Numbers
Solved
Easy
Topics
Companies
Hint
You are given an integer array digits, where each element is a digit. The array may contain duplicates.

You need to find all the unique integers that follow the given requirements:

The integer consists of the concatenation of three elements from digits in any arbitrary order.
The integer does not have leading zeros.
The integer is even.
For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.

Return a sorted array of the unique integers.

 

Example 1:

Input: digits = [2,1,3,0]
Output: [102,120,130,132,210,230,302,310,312,320]
Explanation: All the possible integers that follow the requirements are in the output array. 
Notice that there are no odd integers or integers with leading zeros.
Example 2:

Input: digits = [2,2,8,8,2]
Output: [222,228,282,288,822,828,882]
Explanation: The same digit can be used as many times as it appears in digits. 
In this example, the digit 8 is used twice each time in 288, 828, and 882. 
Example 3:

Input: digits = [3,7,5]
Output: []
Explanation: No even integers can be formed using the given digits.
 

Constraints:

3 <= digits.length <= 100
0 <= digits[i] <= 9

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> st;
        int n=digits.size();
        sort(digits.begin(),digits.end());
        for(int i=0;i<n;i++){
            if(digits[i]==0) continue;
                for(int j=0;j<n;j++){
                    if(i==j) continue;
                      for(int k=0;k<n;k++){
                            if(i==k || j==k) continue;
                            if (digits[k] % 2 != 0) continue;
                            int num=digits[i]*100+digits[j]*10+digits[k];
                            st.insert(num);
                        }
                }
        }
        return vector<int>(st.begin(),st.end());
    }
};