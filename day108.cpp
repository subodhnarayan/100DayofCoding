- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 18 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


Split an array into two equal Sum subarrays
Difficulty: EasyAccuracy: 54.45%Submissions: 14K+Points: 2
Given an array of integers arr, return true if it is possible to split it in two subarrays (without reordering the elements), such that the sum of the two subarrays are equal. If it is not possible then return false.

Examples:

Input: arr = [1, 2, 3, 4, 5, 5]
Output: true
Explanation: In the above example, we can divide the array into two subarrays with eqaul sum. The two subarrays are: [1, 2, 3, 4] and [5, 5]. The sum of both the subarrays are 10. Hence, the answer is true.
Input: arr = [4, 3, 2, 1]
Output: false
Explanation: In the above example, we cannot divide the array into two subarrays with eqaul sum. Hence, the answer is false.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1<=arr.size()<=105 
1<=arr[i]<=106


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        // If total sum is odd, it's not possible to split into two equal parts
        if (totalSum % 2 != 0) return false;
        
        int halfSum = totalSum / 2;
        int currentSum = 0;
        
        for (int i = 0; i < arr.size(); ++i) {
            currentSum += arr[i];
            
            // If we find a prefix sum that equals half of the total sum
            if (currentSum == halfSum) {
                return true;
            }
        }
        
        // If no such split is found
        return false;
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends




- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 18 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


264. Ugly Number II
Solved
Medium
Topics
Companies
Hint
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
 

Constraints:

1 <= n <= 1690




class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1; // The first ugly number is 1
        
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; ++i) {
            // Calculate the next ugly number
            int next2 = dp[i2] * 2;
            int next3 = dp[i3] * 3;
            int next5 = dp[i5] * 5;
            dp[i] = min({next2, next3, next5});
            
            // Update the pointers
            if (dp[i] == next2) ++i2;
            if (dp[i] == next3) ++i3;
            if (dp[i] == next5) ++i5;
        }
        
        return dp[n-1];
    }
};




