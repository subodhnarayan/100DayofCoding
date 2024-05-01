/*Learing Topic
        Introuduction to programming flowchart &pseudocode
            Computer mememory Unit
                If -Else statement
*/

// GFG Bitonic Point questions

class Solution
{
public:
    int findMaximum(int arr[], int n)
    {
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[i - 1])
            {
                ans = arr[i];
            }
        }
        return ans;
    }
};