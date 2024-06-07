// Maximum occured integer
// MediumAccuracy: 32.93%Submissions: 73K+Points: 4
// Solve today's problem-> Be the comment of the day-> Win a GfG T-Shirt!
// Daily rewards up for grabs!

// banner
// Given n integer ranges, the task is to return the maximum occurring integer in the given ranges. If more than one such integer exists, return the smallest one.
// The ranges are in two arrays l[] and r[].  l[i] consists of the starting point of the range and r[i] consists of the corresponding endpoint of the range & a maxx which is the maximum value of r[].

// For example, consider the following ranges.
// l[] = {2, 1, 3}, r[] = {5, 3, 9)
// Ranges represented by the above arrays are.
// [2, 5] = {2, 3, 4, 5}
// [1, 3] = {1, 2, 3}
// [3, 9] = {3, 4, 5, 6, 7, 8, 9}
// The maximum occurred integer in these ranges is 3.

// Examples :

// Input: n = 4, l[] = {1,4,3,1}, r[] = {15,8,5,4}, maxx = 15
// Output: 4
// Explanation: The given ranges are [1,15] [4, 8] [3, 5] [1, 4]. The smallest number that is most common or appears most times in the ranges is 4.
// Input: n = 5, l[] = {1,5,9,13,21}, r[] = {15,8,12,20,30}, maxx = 30
// Output: 5
// Explanation: The given ranges are [1, 15] [5, 8] [9, 12] [13, 20] [21, 30]. The smallest number that is most common or appears most times in the ranges is 5.
// Expected Time Complexity: O(n+maxx).
// Expected Auxiliary Space: O(maxx), maxx is maximum element in r[]

// Constraints:
// 1 ≤ n ≤ 106
// 0 ≤ l[i], r[i] ≤ 106

class Solution
{
public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx)
    {

        // vector<int> ans(maxx+1,0);
        // for(int i=0;i<n;i++){
        //     for(int j=l[i];j<=r[i];j++){
        //         ans[j]++;
        //     }
        // }

        // int m=0;
        // int nu;
        // for(int i=1;i<maxx;i++){
        //     if(m<ans[i]){
        //         m=ans[i];
        //         nu=i;
        //     }
        // }
        // return nu;   TC=O(N^2)

        vector<int> ans(maxx + 2, 0);

        for (int i = 0; i < n; i++)
        {
            ans[l[i]]++;
            ans[r[i] + 1]--;
        }
        int max = ans[0], index = 0;
        for (int i = 1; i <= maxx + 1; i++)
        {
            ans[i] += ans[i - 1];
            if (ans[i] > max)
            {
                max = ans[i];
                index = i;
            }
        }
        return index;
    }
};
