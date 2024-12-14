-- -- -- -- -- -- -- -- -GFG - POTD - 14 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Search in Rotated Sorted Array
Difficulty: MediumAccuracy: 37.64%Submissions: 242K+Points: 4
Given a sorted and rotated array arr[] of distinct elements, the task is to find the index of a target key. Return -1 if the key is not found.

Examples :

Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 3
Output: 8
Explanation: 3 is found at index 8.
Input: arr[] = [3, 5, 1, 2], key = 6
Output: -1
Explanation: There is no element that has value 6.
Input: arr[] = [33, 42, 72, 99], key = 42
Output: 1
Explanation: 42 is found at index 1.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106
1 ≤ key ≤ 106


Time Complexity: O(log n)Auxiliary Space: O(1)

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        //brute force approach
    //     for(int i=0;i<arr.size();i++){
    //     if(arr[i]==key){
    //         return i;
    //     }
    // }
    // return -1; tc=0(N)
    
    int start=0;
    int end=arr.size()-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(arr[mid]==key) return mid;
        if(arr[start]<=arr[mid]){
            if(arr[start]<=key && key<=arr[mid]){
               end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        else{
            if(arr[mid]<=key && key<=arr[end]){
               start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    return -1;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 14 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


Code
Testcase
Test Result
Test Result
33. Search in Rotated Sorted Array
Solved
Medium
Topics
Companies
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:

Input: nums = [1], target = 0
Output: -1
 

Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104


class Solution {
public:
    int search(vector<int>& nums, int target) {
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]==target){
        //         return i;
        //     }
        // }
        // return -1;  //TC=O(N)

        int n=nums.size();
        int low=0;
        int high=n-1;
        int ind=-1;
        while(low<=high){
            int mid=(low+high)/2; 

            if(nums[mid]==target) return mid;

            //left side sorted
            if(nums[mid]>=nums[low]){
             if(nums[low]<=target and target<=nums[mid]){
                high=mid-1;
             }
             else{
                low=mid+1;
             }
            }
            //right side sorted
            else{
                 if(nums[mid]<=target and target<=nums[high]){
                low=mid+1;
             }
             else{
                high=mid-1;
             }
            }
        }
        return -1;
    }
};

