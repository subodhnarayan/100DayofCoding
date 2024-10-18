-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 18 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Single Number
Difficulty: EasyAccuracy: 41.64%Submissions: 43K+Points: 2
Given an array arr[] of positive integers where every element appears even times except for one. Find that number occurring an odd number of times.

Examples:

Input: arr[] = [1, 1, 2, 2, 2]
Output: 2
Explanation: In the given array all element appear two times except 2 which appears thrice.
Input: arr[] = [8, 8, 7, 7, 6, 6, 1]
Output: 1
Explanation: In the given array all element appear two times except 1 which appears once.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arri ≤ 105


class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // unordered_map<int,int> mp;
        // for(int i=0;i<arr.size();i++){
        //     mp[arr[i]]++;
        // }
        
        // for(auto a:mp){
        //     if(a.second%2==1){
        //         return a.first;
        //     }
        // }
        
        // return -1;
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            ans=ans^arr[i];
        }
        return ans;
    }
};