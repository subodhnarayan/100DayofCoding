// Pattern Printing
// Input
// N = 3
// Output:
// * ** ***
// Explanation:
// First, print 1 asterisk then space after
// that print 2 asterisk and space after that
// print 3 asterisk now stop as N is 3.

class Solution
{
public:
    void printPattern(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << "*";
            }
            cout << " ";
        }
    }
};
