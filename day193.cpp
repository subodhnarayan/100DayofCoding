-- -- -- -- -- -- -- -- -GFG - POTD - 12 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Meeting Rooms
Difficulty: MediumAccuracy: 65.12%Submissions: 16K+Points: 4
Given an array arr[][] such that arr[i][0] is the starting time of ith meeting and arr[i][1] is the ending time of ith meeting, the task is to check if it is possible for a person to attend all the meetings such that he can attend only one meeting at a particular time.

Note: A person can attend a meeting if its starting time is greater than or equal to the previous meeting's ending time.

Examples:

Input: arr[][] = [[1, 4], [10, 15], [7, 10]]
Output: true
Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings.
Input: arr[][] = [[2, 4], [9, 12], [6, 10]]
Output: false
Explanation: It is not possible to attend the second and third meetings simultaneously.
Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 2*10



class Solution {
  public:
    bool canAttend(vector<vector<int>> &arr) {
        // map<pair<int,int>> mp;
        // int n=arr.size();
        // for(int i=0;i<n;i++){
        //     mp.insert(arr[i][0]);
        //     mp.insert(arr[i][1]);
        // }
        
        // sort(mp.begin(),mp.end());
        
        // int st=mp[0].first();
        // int end=mp[0].second();
        // int count=1;
        
        // for(int i=1;i<n;i++){
        //     if(end<=mp[i].first()){
        //         end=mp[i].second();
        //         count++;
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // if(count==n)
        // return true;
        // else
        // return false;
        
        
        int n=arr.size();
        
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n-1;i++){
            if(arr[i][1]>arr[i+1][0]){
                return false;
            }
        }
        return true;
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 12 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
