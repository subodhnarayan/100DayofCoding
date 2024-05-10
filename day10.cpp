// Combination Sum II
// MediumAccuracy: 49.5%Submissions: 27K+Points: 4
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via GfG Weekly this sunday!

// banner
// Given an array of integers arr, the length of the array n, and an integer k, find all the unique combinations in arr where the sum of the combination is equal to k. Each number can only be used once in a combination.
// Return the combinations in the lexicographically sorted order, where each combination is in non-decreasing order.

// Example 1:

// Input:
// n = 5, k = 7
// arr[] = { 1, 2, 3, 3, 5 }
// Output:
// { { 1, 3, 3 }, { 2, 5 } }
// Explanation:
// 1 + 3 + 3 = 7
// 2 + 5 = 7

class Solution
{
public:
    void solve(vector<int> &arr, int n, int k, int idx, int sum, vector<int> &v, set<vector<int>> &st)
    {
        if (sum == k)
        {
            st.insert(v);
            return;
        }

        if (idx == n)
            return;

        solve(arr, n, k, idx + 1, sum, v, st);
        if (sum < k)
        {
            v.push_back(arr[idx]);
            solve(arr, n, k, idx + 1, sum + arr[idx], v, st);
            v.pop_back();
        }
    }
    vector<vector<int>> CombinationSum2(vector<int> arr, int n, int k)
    {
        vector<int> temp;
        set<vector<int>> st;
        sort(arr.begin(), arr.end());
        solve(arr, n, k, 0, 0, temp, st);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};
