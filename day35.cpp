// Binary representation of next number
// EasyAccuracy: 50.0%Submissions: 28K+Points: 2
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// Given a binary representation in the form of a string(s) of a number n, the task is to find a binary representation of n+1.

// Note: Output binary string should not contain leading zeros.

// Example 1:

// Input: s = "10"
// Output: 11
// Explanation: "10" is the binary representation of 2 and binary representation of 3 is "11"
// Example 2:

// Input: s = "111"
// Output: 1000
// Explanation: "111" is the binary representation of 7 and binary representation of 8 is "1000"
// Your Task:
// You don't need to read input or print anything. Complete the function binaryNextNumber()which takes s as input parameter and returns the string.

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n) to store resultant string

// Constraints:
// 1 <= n <= 105

class Solution
{
public:
    string binaryNextNumber(string s)
    {
        string ans;
        int j = 0;
        while ((s[j] - '0') == 0 && j < s.size())
        {
            j++;
        }
        int carry = 1;
        for (int i = s.size() - 1; i >= j; i--)
        {
            int n = s[i] - '0';
            int sum = n + carry;
            if (sum == 2)
            {
                carry = 1;
                ans = "0" + ans;
            }
            else if (sum == 1)
            {
                carry = 0;
                ans = "1" + ans;
            }
            else
            {
                carry = 0;
                ans = "0" + ans;
            }
        }
        if (carry == 1)
        {
            ans = "1" + ans;
        }
        return ans;
    }
};