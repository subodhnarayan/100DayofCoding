-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 27 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Triplet Family
Difficulty: BasicAccuracy: 50.0%Submissions: 33K+Points: 1
Given an array arr of integers. Find whether three numbers are such that the sum of two elements equals the third element.

Example:

Input: arr[] = [1, 2, 3, 4, 5]
Output: true
Explanation: The pair (1, 2) sums to 3.
Input: arr[] = [5, 3, 4]
Output: false
Explanation: No triplets satisfy the condition.
Expected Time Complexity: O(n2)
Expected Auxilary Space: O(1)

Constraints:
1 <= arr.size() <= 103
0 <= arr[i] <= 105

class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=n-1;i>=0;i--){
            int j=0,k=i-1;
            while(j<k){
                int sum=arr[j]+arr[k];
                if(arr[i]==sum) return true;
                else if(arr[i]>sum) j++;
                else k--;
            }
        }
        return false;
        
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 27 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --




