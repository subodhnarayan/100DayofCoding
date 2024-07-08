// GFG 8/7/2024
//  Search in Rotated Sorted Array
//  Difficulty: MediumAccuracy: 37.64%Submissions: 216K+Points: 4
//  Given a sorted (in ascending order) and rotated array arr of distinct elements which may be rotated at some point and given an element key, the task is to find the index of the given element key in the array arr. The whole array arr is given as the range to search.

// Rotation shifts elements of the array by a certain number of positions, with elements that fall off one end reappearing at the other end.

// Note:- 0-based indexing is followed & returns -1 if the key is not present.

// Examples :

// Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 10
// Output: 5
// Explanation: 10 is found at index 5.
// Input: arr[] = [3, 5, 1, 2], key = 6
// Output: -1
// Explanation: There is no element that has value 6.
// Expected Time Complexity: O(log n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 106
// 1 ≤ key ≤ 105

class Solution
{
public:
    int search(vector<int> &arr, int key)
    {
        // int n=arr.size();
        // for(int i=0;i<n;i++){
        //     if(arr[i]==key){
        //         return i;
        //     }
        // }
        // return -1;  TC=0(N)

        // Another approach
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }

            // checking left is sorted or not cheking ascending order
            if (arr[start] <= arr[mid])
            {
                // checkingt key in right half
                if (arr[start] <= key && key < arr[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            // checking right side is sorted or not  in descending order
            else
            {
                // checkingt key in right half
                if (arr[mid] < key && key <= arr[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};
