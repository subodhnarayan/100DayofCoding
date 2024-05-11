// Juggler Sequence
// EasyAccuracy: 52.04%Submissions: 34K+Points: 2
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via GfG Weekly this sunday!

// banner
// Juggler Sequence is a series of integers in which the first term starts with a positive integer number a and the remaining terms are generated from the immediate previous term using the below recurrence relation:

// Juggler Formula

// Given a number n, find the Juggler Sequence for this number as the first term of the sequence until it becomes 1.

// Example 1:

// Input: n = 9
// Output: 9 27 140 11 36 6 2 1
// Explaination: We start with 9 and use
// above formula to get next terms.

class Solution
{
public:
    vector<long long> jugglerSequence(long long n)
    {
        vector<long long> ans;
        ans.push_back(n);
        while (n > 1)
        {
            if (n % 2 == 0)
            {
                n = pow(n, 0.5);
                ans.push_back(n);
            }
            else
            {
                n = pow(n, 1.5);
                ans.push_back(n);
            }
        }
        return ans;
    }
};