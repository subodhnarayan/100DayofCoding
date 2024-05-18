Find the Highest number
            EasyAccuracy : 46.89 %
        Submissions : 62K +
    Points : 2 In need of more Geekbits
    ? Win from a pool of 3500 + Geekbits via DSA - based Coding Contest every sunday !

          banner Given an integer array a[] of size n,
    find the highest element of the array.The array will either be strictly increasing or strictly increasing and then strictly decreasing.

                                                                                          Note
    : a[i] != a[i + 1]

                      Example 1 :

    Input : 11 1 2 3 4 5 6 5 4 3 2 1 Output : 6 Explanation : Highest element of array a[] is 6. Example 2 :

    Input : 5 1 2 3 4 5 Output : 5 Explanation : Highest element of array a[] is 5.

                                                 Find the Highest number
                                                     EasyAccuracy : 46.89 %
                                                 Submissions : 62K +
                  Points : 2 In need of more Geekbits
    ? Win from a pool of 3500 + Geekbits via DSA - based Coding Contest every sunday !

          banner Given an integer array a[] of size n,
    find the highest element of the array.The array will either be strictly increasing or strictly increasing and then strictly decreasing.

                                                                                          Note
    : a[i] != a[i + 1]

          Example 1 :

    Input : 11 1 2 3 4 5 6 5 4 3 2 1 Output : 6 Explanation : Highest element of array a[] is 6. Example 2 :

    Input : 5 1 2 3 4 5 Output : 5 Explanation : Highest element of array a[] is 5.

                                                 class Solution
{
public:
    int findPeakElement(vector<int> &arr)
    {
        int hig = arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] > hig)
            {
                hig = arr[i];
            }
            else
            {
                break;
            }
        }
        return hig;
    }
};