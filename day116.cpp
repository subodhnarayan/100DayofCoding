-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 27 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Maximum Difference
Difficulty: MediumAccuracy: 33.3%Submissions: 69K+Points: 4
Given an integer array arr of integers, the task is to find the maximum absolute difference between the nearest left smaller element and the nearest right smaller element of every element in array arr. If for any component of the arr, the nearest smaller element doesn't exist then consider it as 0.

Examples :

Input: arr = [2, 1, 8]
Output: 1
Explanation: left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1
Input: arr = [2, 4, 8, 7, 7, 9, 3]
Output: 4
Explanation: left smaller array ls = [0, 2, 4, 4, 4, 7, 2], right smaller rs = [0, 3, 7, 3, 3, 3, 0]. Maximum Diff of abs(ls[i] - rs[i]) = abs(7 - 3) = 4
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 <= arr.size() <= 106
1<= arr[i] <=109



class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n=arr.size();
        vector<int> ls(n,0);
        vector<int> rs(n,0);
        
    stack<int> S;
 
    // Traverse all array elements
    for (int i=0; i<n; i++)
    {
        // Keep removing top element from S while the top
        // element is greater than or equal to arr[i]
        while (!S.empty() && S.top() >= arr[i])
            S.pop();
 
        // If all elements in S were greater than arr[i]
        if (!S.empty()){
            ls[i]=S.top();
        }
            
 
        // Push this element
        S.push(arr[i]);
    }
    stack<int> St;
    for(int i=n-1; i>=0; i--)
    {
        // Keep removing top element from S while the top
        // element is greater than or equal to arr[i]
        while (!St.empty() && St.top() >= arr[i])
            St.pop();
 
        // If all elements in S were greater than arr[i]
        if (!St.empty()){
            rs[i]=St.top();
        }
 
        // Push this element
        St.push(arr[i]);
    }
    
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(abs(ls[i]-rs[i]),ans);
    }
    return ans;
    
    }
};