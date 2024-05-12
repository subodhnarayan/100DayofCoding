// Minimum steps to destination
// MediumAccuracy: 31.77%Submissions: 34K+Points: 4
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via GfG Weekly this sunday!

// banner
// Given an infinite number line. You start at 0 and can go either to the left or to the right. The condition is that in the ith move, you must take i steps. Given a destination d, find the minimum number of steps required to reach that destination.

// Example 1:

// Input: d = 2
// Output: 3
// Explaination: The steps takn are +1, -2 and +3.
// Example 2:

// Input: d = 10
// Output: 4
// Explaination: The steps are +1, +2, +3 and +4.

class Solution
{
public:
    int minSteps(int d)
    {
        int sum = 0;
        int steps = 0;
        while (sum != d)
        {
            sum += steps;
            if (sum == d)
            {
                return steps;
            }

            else if (sum > d)
            {
                int temp = sum - d;
                if (temp % 2 == 0)
                    break;
            }
            ++steps;
        }
        return steps;
    }
};