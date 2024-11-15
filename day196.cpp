-- -- -- -- -- -- -- -- -GFG - POTD - 15 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Second Largest
Difficulty: EasyAccuracy: 26.72%Submissions: 790K+Points: 2
Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

Note: The second largest element should not be equal to the largest element.

Examples:

Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
Explanation: The largest element of the array is 35 and the second largest element is 34.
Input: arr[] = [10, 5, 10]
Output: 5
Explanation: The largest element of the array is 10 and the second largest element is 5.
Input: arr[] = [10, 10, 10]
Output: -1
Explanation: The largest element of the array is 10 and the second largest element does not exist.
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105


class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        
        int n=arr.size();
        int flar=-1;
        int slar=-1;
        
        for(int i=0;i<n;i++){
            if(arr[i]>flar){
                slar=flar;
                flar=arr[i];
            }
            else if(arr[i]>slar && arr[i]!=flar){
                slar=arr[i];
            }
        }
        return slar;
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 15 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

1574. Shortest Subarray to be Removed to Make Array Sorted
Solved
Medium
Topics
Companies
Hint
Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.

Return the length of the shortest subarray to remove.

A subarray is a contiguous subsequence of the array.

 

Example 1:

Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].
Example 2:

Input: arr = [5,4,3,2,1]
Output: 4
Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].
Example 3:

Input: arr = [1,2,3]
Output: 0
Explanation: The array is already non-decreasing. We do not need to remove any elements.
 

Constraints:

1 <= arr.length <= 105
0 <= arr[i] <= 109