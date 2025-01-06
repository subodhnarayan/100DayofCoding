
-- -- -- -- -- -- -- -- -GFG - POTD - 06 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Sum Pair closest to target
Difficulty: EasyAccuracy: 44.75%Submissions: 41K+Points: 2
Given an array arr[] and a number target, find a pair of elements (a, b) in arr[], where a<=b whose sum is closest to target.
Note: Return the pair in sorted order and if there are multiple such pairs return the pair with maximum absolute difference. If no such pair exists return an empty array.

Examples:

Input: arr[] = [10, 30, 20, 5], target = 25
Output: [5, 20]
Explanation: As 5 + 20 = 25 is closest to 25.
Input: arr[] = [5, 2, 7, 1, 4], target = 10
Output: [2, 7]
Explanation: As (4, 7) and (2, 7) both are closest to 10, but absolute difference of (2, 7) is 5 and (4, 7) is 3. Hence, [2, 7] has maximum absolute difference and closest to target. 
Input: arr[] = [10], target = 10
Output: []
Explanation: As the input array has only 1 element, return an empty array.
Constraints:
1 <= arr.size() <= 2*105
0 <= target<= 2*105
0 <= arr[i] <= 105


Topic Tags
ArraysData Structurestwo-pointer-algorithm

Expected Complexities
Time Complexity: O(n log n)Auxiliary Space: O(1)


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
           int n = arr.size();
        if (n < 2) {
            return {}; 
        }
       
        sort(arr.begin(), arr.end());

        
        pair<int, int> closestPair;
        int closestDiff = INT_MAX; 

       
        int i = 0, j = n - 1;
        while (i < j) {
            
            int sum=arr[i]+arr[j];
            
            if(closestDiff>abs(sum-target)){
                closestDiff=abs(sum-target);
                closestPair=make_pair(arr[i],arr[j]);
            }
            
            if(sum>target){
                j--;
            }
            else{
                i++;
            }
            
            
        }

        return {closestPair.first, closestPair.second};
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends


-- -- -- -- -- -- -- -- -Leetcode - POTD - 06 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -