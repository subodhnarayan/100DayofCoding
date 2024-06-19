// Find maximum volume of a cuboid
// Difficulty: EasyAccuracy: 53.16%Submissions: 24K+Points: 2
// You are given a perimeter & the area. Your task is to return the maximum volume that can be made in the form of a cuboid from the given perimeter and surface area.
// Note: Round off to 2 decimal places and for the given parameters, it is guaranteed that an answer always exists.

// Examples

// Input: perimeter = 22, area = 15
// Output: 3.02
// Explanation: The maximum attainable volume of the cuboid is 3.02
// Input: perimeter = 20, area = 5
// Output: 0.33
// Explanation: The maximum attainable volume of the cuboid is 0.33
// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)
// Constraints :
// 1 ≤ perimeter ≤ 109
// 1 ≤ area ≤ 109

class Solution
{
public:
    double maxVolume(double perimeter, double area)
    {
        double peri = perimeter;
        double ar = area;

        double len = (peri / 2 - sqrt(peri * peri / 4 - 6 * ar)) / 6;

        double ans = len * len * (peri / 4 - 2 * len);

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
//