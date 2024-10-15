-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 15 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Subarray range with given sum
Difficulty: MediumAccuracy: 42.21%Submissions: 45K+Points: 4
Given an unsorted array of integers arr[], and a target tar, determine the number of subarrays whose elements sum up to the target value.

Examples:

Input: arr[] = [10, 2, -2, -20, 10] , tar = -10
Output: 3
Explanation: Subarrays with sum -10 are: [10, 2, -2, -20], [2, -2, -20, 10] and [-20, 10].
Input: arr[] = [1, 4, 20, 3, 10, 5] , tar = 33
Output: 1
Explanation: Subarray with sum 33 is: [20,3,10].
Expected Time Complexity: O(n)
Expected Auxilary Space: O(n)

Constraints:
1 <= arr.size() <= 106
-105 <= arr[i] <= 105
-105 <= tar <= 105


class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // int n=arr.size();
        // int count=0;
        // for(int i=0;i<n;i++){
        //         int sum=0;
        //         for(int k=i;k<n;k++){
        //             sum+=arr[k];
        //             if(sum==tar){
        //                 count++;
        //                 break;
        //             }
        //         }
        // }
        // return count;  Tc=0(n2)
        
        int n=arr.size();
        unordered_map<int,int> mp;
        int sum=0,ans=0;
        for(int x:arr){
            sum+=x;
            if(sum==tar) ans++;
            if(mp.find(sum-tar)!=mp.end()){
                ans+=mp[sum-tar];
            }
            mp[sum]++;
        }
        return ans;
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
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
/