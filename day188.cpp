-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 17 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Split array in three equal sum subarrays
Difficulty: MediumAccuracy: 52.9%Submissions: 16K+Points: 4
Given an array, arr[], determine if arr can be split into three consecutive parts such that the sum of each part is equal. If possible, return any index pair(i, j) in an array such that sum(arr[0..i]) = sum(arr[i+1..j]) = sum(arr[j+1..n-1]), otherwise return an array {-1,-1}.

Note: Since multiple answers are possible, return any of them. The driver code will print true if it is correct otherwise, it will print false.

Examples :

Input:  arr[] = [1, 3, 4, 0, 4]
Output: true
Explanation: [1, 2] is valid pair as sum of subarray arr[0..1] is equal to sum of subarray arr[2..3] and also to sum of subarray arr[4..4]. The sum is 4, so driver code prints true.
Input: arr[] = [2, 3, 4]
Output: false
Explanation: No three subarrays exist which have equal sum.
Input: arr[] = [0, 1, 1]
Output: false
Constraints:
3 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106

class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        // code here
         int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        
        if(sum%3!=0) return {-1,-1};
        
        int temp=0;
        int count=0;
        
        vector<int>index(2,-1);
        
        for(int i=0;i<arr.size();i++){
            
            temp+=arr[i];
    
            if(count ==0 && temp==sum/3){
                count++;
                temp=0;
                index[0]=i;
            }
            
            if(count==1 && temp==sum/3 && i<arr.size()-1){
                index[1]=i;
                return index;
            }
        }
        
        return {-1,-1};
    }
};