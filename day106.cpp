

- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 14 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


Code
Testcase
Test Result
Test Result
624. Maximum Distance in Arrays
Solved
Medium
Topics
Companies
You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

 

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.
Example 2:

Input: arrays = [[1],[1]]
Output: 0
Constraints:

m == arrays.length
2 <= m <= 105
1 <= arrays[i].length <= 500
-104 <= arrays[i][j] <= 104
arrays[i] is sorted in ascending order.
There will be at most 105 integers in all the arrays.



#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // Initialize the result as 0
        int result = 0;
        
        // Initialize minVal and maxVal using the first array's first and last elements
        int minVal = arrays[0].front();
        int maxVal = arrays[0].back();
        
        // Iterate through the arrays starting from the second array
        for (int i = 1; i < arrays.size(); i++) {
            // Update the result with the maximum of the current result and the distances
            result = max(result, abs(arrays[i].back() - minVal));
            result = max(result, abs(maxVal - arrays[i].front()));
            
            // Update minVal and maxVal with the current array's first and last elements
            minVal = min(minVal, arrays[i].front());
            maxVal = max(maxVal, arrays[i].back());
        }
        
        return result;
    }
};



Maximize The Cut Segments
Difficulty: MediumAccuracy: 24.29%Submissions: 222K+Points: 4
Given an integer n denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum. Return the maximum number of cut segments possible.

Note: if no segment can be cut then return 0.

Examples:

Input: n = 4, x = 2, y = 1, z = 1
Output: 4
Explanation: Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
Input: n = 5, x = 5, y = 3, z = 2
Output: 2
Explanation: Here total length is 5, and
the cut lengths are 5, 3 and 2. We can
make two segments of lengths 3 and 2.
Expected Time Complexity : O(n)
Expected Auxiliary Space: O(n)

Constraints
1 <= n, x, y, z <= 104


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> dp(n+1, -1);

    // Base case: No cuts can be made in length 0
    dp[0] = 0;

    // Iterate over all lengths from 1 to n
    for (int i = 1; i <= n; i++) {
        // Check for each cut length x, y, z if a cut can be made
        if (i >= x && dp[i - x] != -1) {
            dp[i] = max(dp[i], dp[i - x] + 1);
        }
        if (i >= y && dp[i - y] != -1) {
            dp[i] = max(dp[i], dp[i - y] + 1);
        }
        if (i >= z && dp[i - z] != -1) {
            dp[i] = max(dp[i], dp[i - z] + 1);
        }
    }

    // If no cuts can be made for length n, return 0, otherwise return dp[n]
    return dp[n] == -1 ? 0 : dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends