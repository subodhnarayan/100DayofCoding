-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 28 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Remove duplicates in array
Difficulty: EasyAccuracy: 35.86%Submissions: 53K+Points: 2
Given an array arr consisting of positive integer numbers, remove all duplicate numbers.

Example:

Input: arr[] = [2, 2, 3, 3, 7, 5] 
Output: [2, 3, 7, 5]
Explanation: After removing the duplicates 2 and 3 we get 2 3 7 5.
Input: arr[] = [2, 2, 5, 5, 7, 7] 
Output: [2, 5, 7]
Input: arr[] = [8, 7] 
Output: [8, 7]
Constraints:
1<= arr.size() <=106
2<= arr[i] <=100

class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        unordered_set<int> st;
        int n=arr.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(st.find(arr[i])==st.end())
             ans.push_back(arr[i]);
            st.insert(arr[i]);
           
        }
        // for(int &it:arr){
        //     if(st.find(it)==st.end())
        //     st.insert(it);
        //     ans.push_back(it);
        // }

        return ans;
    }
};