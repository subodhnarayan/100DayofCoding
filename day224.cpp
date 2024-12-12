-- -- -- -- -- -- -- -- -GFG - POTD - 12 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Number of occurrence
Difficulty: EasyAccuracy: 59.34%Submissions: 268K+Points: 2
Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

Examples :

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.
Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ target ≤ 106

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // int count=0;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]==target){
        //         count++;
        //     }
        // }
        // return count;
        int n=arr.size();
        int find=-1;
        int lind=-1;
        int start=0;
        int end=n-1;
        
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]>=target){
                if(arr[mid]==target){
                find=mid;
                }
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        start=0;
        end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]<=target){
                if(arr[mid]==target){
                lind=mid;
                }
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        if(find==-1 || lind==-1) return 0;
        
        return lind-find+1;
        
    }
};
-- -- -- -- -- -- -- -- -Leetcode - POTD - 12 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -



