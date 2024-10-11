-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 11 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Reorganize The Array
Difficulty: EasyAccuracy: 31.25%Submissions: 48K+Points: 2
Given an array of elements arr[] with indices ranging from 0 to arr.size() - 1, your task is to write a program that rearranges the elements of the array such that arr[i] = i. If an element i is not present in the array, -1 should be placed at the corresponding index.

Examples:

Input: arr[] = [-1, -1, 6, 1, 9, 3, 2, -1, 4, -1]
Output: [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]
Explanation: Here We can see there are 10 elements. So, the sorted array will look like [0, 1, 2, 3, 4, 5, 6, 7, 8, 9] but in our array we are not having 0, 5, 7 and 8. So, at there places we will be printing -1 and otherplaces will be having elements.
Input: arr[] = [2, 0, 1]
Output: [0, 1, 2]
Explanation: Here We can see all the elements are present so no -1 is returned in array.
Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
0 ≤ arr.size() ≤ 105
-1 ≤ arr[i] ≤ arr.size()-1


class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        // int n=arr.size();
        // unordered_set<int> st;
        // for(int i=0;i<n;i++){
        //     st.insert(arr[i]);
        // }
        // vector<int> ans(n);
        // for(int i=0;i<ans.size();i++){
        //     if(st.find(i)!=st.end())
        //     {
        //         ans[i]=i;
        //     }
        //     else{
        //         ans[i]=-1;
        //     }
        // }
        // return ans;
        
        
        //another approach
        int n=arr.size();
          vector<int> ans(n,-1);
          for(int i=0;i<n;i++){
              if(arr[i]!=-1){
            ans[arr[i]]=arr[i];
              }
        }
         return ans;
    }
};

-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 11 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


1942. The Number of the Smallest Unoccupied Chair
Solved
Medium
Topics
Companies
Hint
There is a party where n friends numbered from 0 to n - 1 are attending. There is an infinite number of chairs in this party that are numbered from 0 to infinity. When a friend arrives at the party, they sit on the unoccupied chair with the smallest number.

For example, if chairs 0, 1, and 5 are occupied when a friend comes, they will sit on chair number 2.
When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

You are given a 0-indexed 2D integer array times where times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, and an integer targetFriend. All arrival times are distinct.

Return the chair number that the friend numbered targetFriend will sit on.

 

Example 1:

Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
Output: 1
Explanation: 
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.
Since friend 1 sat on chair 1, we return 1.
Example 2:

Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
Output: 2
Explanation: 
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.
 

Constraints:

n == times.length
2 <= n <= 104
times[i].length == 2
1 <= arrivali < leavingi <= 105
0 <= targetFriend <= n - 1
Each arrivali time is distinct.


class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
       int n = times.size();
        
    // Create a list of pairs {arrivalTime, friendIndex} to track arrival times
    vector<pair<int, int>> arrivals;
    for (int i = 0; i < n; ++i) {
        arrivals.push_back({times[i][0], i}); // {arrival time, friend index}
    }
        
    // Sort friends based on their arrival times
    sort(arrivals.begin(), arrivals.end());

    // Min-Heap to track available chairs, initially all chairs [0, 1, 2, ..., n-1] are available
    priority_queue<int, vector<int>, greater<int>> availableChairs;
    for (int i = 0; i < n; ++i) {
        availableChairs.push(i); // All chairs start as available
    }

    // Min-Heap to track when chairs are freed, storing {leave time, chair number}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> leavingQueue;
        
    // Iterate through each friend based on arrival
    for (auto& arrival : arrivals) {
        int arrivalTime = arrival.first;    // Friend's arrival time
        int friendIndex = arrival.second;   // Friend's index
            
        // Free up chairs for friends who have already left by the current arrival time
        while (!leavingQueue.empty() && leavingQueue.top().first <= arrivalTime) {
            availableChairs.push(leavingQueue.top().second); // Free the chair
            leavingQueue.pop();
        }
            
        // Assign the smallest available chair to the current friend
        int chair = availableChairs.top(); 
        availableChairs.pop(); // Remove that chair from available chairs
            
        // If this is the target friend, return their chair number
        if (friendIndex == targetFriend) {
            return chair;
        }
            
        // Mark the chair as being used until the friend's departure time
        leavingQueue.push({times[friendIndex][1], chair}); // {departure time, chair}
    }
        
    return -1; // This line should never be reached if input is val
    }
};



