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



-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 15 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- ----

2938. Separate Black and White Balls
Solved
Medium
Topics
Companies
Hint
There are n balls on a table, each ball has a color black or white.

You are given a 0-indexed binary string s of length n, where 1 and 0 represent black and white balls, respectively.

In each step, you can choose two adjacent balls and swap them.

Return the minimum number of steps to group all the black balls to the right and all the white balls to the left.

 

Example 1:

Input: s = "101"
Output: 1
Explanation: We can group all the black balls to the right in the following way:
- Swap s[0] and s[1], s = "011".
Initially, 1s are not grouped together, requiring at least 1 step to group them to the right.
Example 2:

Input: s = "100"
Output: 2
Explanation: We can group all the black balls to the right in the following way:
- Swap s[0] and s[1], s = "010".
- Swap s[1] and s[2], s = "001".
It can be proven that the minimum number of steps needed is 2.
Example 3:

Input: s = "0111"
Output: 0
Explanation: All the black balls are already grouped to the right.
 

Constraints:

1 <= n == s.length <= 105
s[i] is either '0' or '1'.



class Solution {
public:
    long long minimumSteps(string s) {
    //     int n=s.size();
    //     long long ans=0;
    //     int left=0;
    //     int right=n-1;
    //     while (left < right) {
    //     // Find the next '1' from the left
    //     while (left < right && s[left] == '0') {
    //         left++;
    //     }
    //     // Find the next '0' from the right
    //     while (left < right && s[right] == '1') {
    //         right--;
    //     }
    //     // If valid '1' on left and '0' on right, swap them
    //     if (left < right) {
    //         swap(s[left], s[right]);
    //         ans++;  // Increment the swap count
    //         left++;
    //         right--;
    //     }
    // }

    // return ans;  // Return the number of swaps

    // This will not work

    int black=0;
    long long swap=0;
    for(char x:s){
        if(x=='0'){
            swap+=black;
        }
        else{
            black++;
        }
    }
    return swap;
 }
};