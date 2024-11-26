-- -- -- -- -- -- -- -- -GFG - POTD - 26 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -



Max Circular Subarray Sum
Difficulty: HardAccuracy: 29.37%Submissions: 125K+Points: 8
Given an array of integers arr[] in a circular fashion. Find the maximum subarray sum that we can get if we assume the array to be circular.

Examples:

Input: arr[] = [8, -8, 9, -9, 10, -11, 12]
Output: 22
Explanation: Starting from the last element of the array, i.e, 12, and moving in a circular fashion, we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.
Input: arr[] = [10, -3, -4, 7, 6, 5, -4, -1]
Output: 23
Explanation: Maximum sum of the circular subarray is 23. The subarray is [7, 6, 5, -4, -1, 10].
Input: arr[] = [-1, 40, -14, 7, 6, 5, -4, -1] 
Output: 52
Explanation: Circular Subarray [7, 6, 5, -4, -1, -1, 40] has the maximum sum, which is 52.
Constraints:
1 <= arr.size() <= 105
-104 <= arr[i] <= 104


class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int n=arr.size();
        int maxi1=0,sum1=0,total=0;
        for(int i=0;i<n;i++){
            sum1+=arr[i];
            total+=arr[i];
            if(sum1>maxi1) maxi1=max(sum1,maxi1);
            if(sum1<0) sum1=0;
        }
        
        int maxi2=0,sum2=0;
        for(int i=0;i<n;i++){
            sum2+=arr[i];
            maxi2=min(maxi2,sum2);
            if(sum2>0) sum2=0;
        }
        
        return max(maxi1,total-maxi2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends


-- -- -- -- -- -- -- -- -Leetcode - POTD - 26 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


