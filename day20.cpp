// Modular Exponentiation for large numbers
// MediumAccuracy: 52.56%Submissions: 49K+Points: 4
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// Implement pow(x, n) % M.
// In other words, for a given value of x, n, and M, find  (xn) % M.

// Example 1:

// Input:
// x = 3, n = 2, m = 4
// Output:
// 1
// Explanation:
// 32 = 9. 9 % 4 = 1.
// Example 2:

// Input:
// x = 2, n = 6, m = 10
// Output:
// 4
// Explanation:
// 26 = 64. 64 % 10 = 4.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long int PowMod(long long int x, long long int n, long long int M)
    {
        long long int ans = 1;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                ans = (ans * x) % M;
            }
            x = (x * x) % M;
            n = n / 2;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long int x, n, m;
        cin >> x >> n >> m;
        Solution ob;
        long long int ans = ob.PowMod(x, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends