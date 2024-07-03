// Extract the Number from the String
// Difficulty: EasyAccuracy: 12.06%Submissions: 56K+Points: 2
// Given a sentence containing several words and numbers. Find the largest number among them which does not contain 9. If no such number exists, return -1.

// Note: Numbers and words are separated by spaces only. It is guaranteed that there are no leading zeroes in the answer.

// Examples :

// Input: sentence="This is alpha 5057 and 97"
// Output: 5057
// Explanation: 5057 is the only number that does not have a 9.
// Input: sentence="Another input 9007"
// Output: -1
// Explanation: Since there is no number that does not contain a 9,output is -1.
// Expected Time Complexity: O(n)
// Expected Auxillary Space: O(n)

// Constraints:
// 1<=n<=106
// 1<=answer<=1018

class Solution
{
public:
    long long ExtractNumber(string sen)
    {
        long long maxNumber = -1; // Initialize the maximum number as -1
        long long currentNumber = 0;
        bool hasNumber = false;

        int n = sen.size();
        for (int i = 0; i <= n; ++i)
        {
            if (i < n && isdigit(sen[i]))
            {
                currentNumber = currentNumber * 10 + (sen[i] - '0');
                hasNumber = true;
            }
            else
            {
                if (hasNumber)
                {
                    // We have completed a number, now check if it contains '9'
                    bool containsNine = false;
                    long long temp = currentNumber;
                    while (temp > 0)
                    {
                        int rem = temp % 10;
                        if (rem == 9)
                        {
                            containsNine = true;
                            break;
                        }
                        temp /= 10;
                    }
                    if (!containsNine)
                    {
                        if (currentNumber > maxNumber)
                        {
                            maxNumber = currentNumber;
                        }
                    }
                    // Reset for the next number
                    currentNumber = 0;
                    hasNumber = false;
                }
            }
        }

        return maxNumber;
    }
};