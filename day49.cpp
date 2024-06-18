// Number of Rectangles in a Circle
// Difficulty: MediumAccuracy: 60.22%Submissions: 16K+Points: 4
// Given a circular sheet of radius, r. Find the total number of rectangles with integral length and width that can be cut from the sheet that can fit on the circle, one at a time.

// Examples :

// Input: r=1
// Output: 1
// Explanation: Only 1 rectangle of dimensions 1x1.
// Input: r=2
// Output: 8
// Explanation: The 8 possible rectangles are
// (1x1)(1x2)(1x3)(2x1)(2x2)(2x3)(3x1)(3x2).
// Expected Time Complexity: O(r2)
// Expected Auxillary Space: O(1)

// Constraints:
// 1<=r<=1000

class Solution
{
public:
    int rectanglesInCircle(int r)
    {
        double A = 4 * r * r;
        int count = 0;
        for (int i = 1; i <= 2 * r; i++)
        {
            for (int j = 1; j <= 2 * r; j++)
            {
                if (double(i * i) + double(j * j) <= A)
                {
                    count++;
                }
            }
        }
        return count;
    }
};

