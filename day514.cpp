-- -- -- -- -- -- -- -- -GFG - POTD - 25 / 05 / 2025 ----------------------------------------
Pythagorean Triplet
Difficulty: MediumAccuracy: 24.77%Submissions: 240K+Points: 4Average Time: 20m
Given an array arr[], return true if there is a triplet (a, b, c) from the array (where a, b, and c are on different indexes) that satisfies a2 + b2 = c2, otherwise return false.

Examples:

Input: arr[] = [3, 2, 4, 6, 5]
Output: true
Explanation: a=3, b=4, and c=5 forms a pythagorean triplet.
Input: arr[] = [3, 8, 5]
Output: false
Explanation: No such triplet possible.
Input: arr[] = [1, 1, 1]
Output: false
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 103

Expected Complexities
Time Complexity: O(n + max(arr[i])^2)
Auxiliary Space: O(max(arr[i]))

Time Complexity: O(n + max(arr[i])^2)
Auxiliary Space: O(max(arr[i]))


class Solution {
  public:
    bool pythagoreanTriplet(vector<int>& arr) {
        // code here
       int n=arr.size();
        int maxi=*max_element(arr.begin(),arr.end());
        vector<int>elements(maxi+1,0);
        for(int i:arr){
            elements[i]++;
        }
        
        for(int i=1;i<=maxi;i++){
            for(int j=i+1;j<=maxi;j++){
                // check if i and j exists in arr
                if(elements[i] && elements[j]){
                    int a=i,b=j;
                    int right=(a*a) + (b*b);
                    int c=sqrt(right);
                    if(c<=maxi && (c*c)==right && elements[c]) 
                        return true;
                }
            }
        }
        
        return false;
    }
};



-- -- -- -- -- -- -- -- -Leetcode - POTD - 25 / 05 / 2025 ----------------------------------------

