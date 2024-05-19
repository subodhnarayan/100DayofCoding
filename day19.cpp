class Solution
{
public:
    int findClosest(int n, int k, int arr[])
    {

        int min = INT_MAX;
        int target = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (abs(arr[i] - k) < min)
            {
                target = arr[i];
                min = abs(arr[i] - k);
            }
        }
        return target;
    }
}