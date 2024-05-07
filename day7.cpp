// Reverse words in a given string

// Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

// Example 1:

// Input:
// S = i.like.this.program.very.much
// Output: much.very.program.this.like.i
// Explanation: After reversing the whole
// string(not individual words), the input
// string becomes
// much.very.program.this.like.i

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        int n = S.size();
        string ans = "";
        string word = "";
        for (int i = 0; i < n; i++)
        {
            if (S[i] != '.')
            {
                word += S[i];
            }
            else
            {
                if (!word.empty())
                {
                    ans = word + "." + ans;
                    word = "";
                }
            }
        }
        if (!word.empty())
        {
            ans = word + "." + ans;
        }
        ans.pop_back();
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends