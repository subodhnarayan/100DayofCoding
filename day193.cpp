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


2070. Most Beautiful Item for Each Query
Solved
Medium
Topics
Companies
Hint
You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.

You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.

Return an array answer of the same length as queries where answer[j] is the answer to the jth query.

 

Example 1:

Input: items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
Output: [2,4,5,5,6,6]
Explanation:
- For queries[0]=1, [1,2] is the only item which has price <= 1. Hence, the answer for this query is 2.
- For queries[1]=2, the items which can be considered are [1,2] and [2,4]. 
  The maximum beauty among them is 4.
- For queries[2]=3 and queries[3]=4, the items which can be considered are [1,2], [3,2], [2,4], and [3,5].
  The maximum beauty among them is 5.
- For queries[4]=5 and queries[5]=6, all items can be considered.
  Hence, the answer for them is the maximum beauty of all items, i.e., 6.
Example 2:

Input: items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
Output: [4]
Explanation: 
The price of every item is equal to 1, so we choose the item with the maximum beauty 4. 
Note that multiple items can have the same price and/or beauty.  
Example 3:

Input: items = [[10,1000]], queries = [5]
Output: [0]
Explanation:
No item has a price less than or equal to 5, so no item can be chosen.
Hence, the answer to the query is 0.
 

Constraints:

1 <= items.length, queries.length <= 105
items[i].length == 2
1 <= pricei, beautyi, queries[j] <= 109