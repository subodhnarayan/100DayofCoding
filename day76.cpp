//GFG POTD 19/7/2024
Count Smaller elements
// Difficulty: HardAccuracy: 38.16%Submissions: 64K+Points: 8
// Given an array arr containing non-negative integers. Count and return an array ans where ans[i] denotes the number of smaller elements on right side of arr[i].

// Examples:

// Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
// Output: [6, 1, 1, 1, 0, 1, 0]
// Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.
// Input: arr[] = [1, 2, 3, 4, 5]
// Output: [0, 0, 0, 0, 0]
// Explanation: There are 0 smaller elements right after 1. There are 0 smaller elements right after 2. And so on.
// Expected Time Complexity: O(n*logn)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i]  ≤ 108


class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        vector<int> ans;
        vector<int> temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            int tar=arr[i];
            int start=0;
            int end=temp.size()-1;
            int ind=-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(temp[mid]==tar){
                    ind=mid;
                    end=mid-1;
                }
                else if(temp[mid]<tar){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        
            ans.push_back(ind);
            temp.erase(temp.begin() + ind);
        }
        return ans;
        
    }
};