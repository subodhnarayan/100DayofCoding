- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 14 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


Alternate positive and negative numbers
Difficulty: EasyAccuracy: 33.86%Submissions: 185K+Points: 2
Given an unsorted array arr containing both positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.
Note: Array should start with a positive number and 0 (zero) should be considered a positive element.

Examples:

Input: arr[] = [9, 4, -2, -1, 5, 0, -5, -3, 2]
Output: 9 -2 4 -1 5 -5 0 -3 2
Explanation: Positive elements : [9,4,5,0,2]
Negative elements : [-2,-1,-5,-3]
As we need to maintain the relative order of postive elements and negative elements we will pick each element from the positive and negative and will store them. If any of the positive and negative numbersare completed. we will continue with the remaining signed elements.
The output is 9,-2,4,-1,5,-5,0,-3,2.
Input: arr[] = [-5, -2, 5, 2, 4, 7, 1, 8, 0, -8]
Output: 5 -5 2 -2 4 -8 7 1 8 0
Explanation : Positive elements : [5,2,4,7,1,8,0]
Negative elements : [-5,-2,-8]
The output is 5, -5, 2, -2, 4, -8, 7, 1, 8, 0.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ arr.size() ≤ 107
-106 ≤ arr[i] ≤ 107



class Solution {
  public:

    void rearrange(vector<int> &arr) {
        int n=arr.size();
        vector<int> ps;
        vector<int> ng;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                ps.push_back(arr[i]);
            }
            else{
                ng.push_back(arr[i]);
            }
        }
        
        int i=0;
        int j=0;
        int k=0;
        while(i<ps.size() && j<ng.size()){
               arr[k]=ps[i];
               i++;
               k++;
               arr[k]=ng[j];
               j++;
               k++;
           }
           
        
        
        while(i<ps.size()){
            arr[k]=ps[i];
            i++,k++;
        }
        
        while(j<ng.size()){
            arr[k]=ng[j];
            j++,k++;
        }
        
        
        
        
    
    }
};


- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 14 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

2419. Longest Subarray With Maximum Bitwise AND
Solved
Medium
Topics
Companies
Hint
You are given an integer array nums of size n.

Consider a non-empty subarray from nums that has the maximum possible bitwise AND.

In other words, let k be the maximum value of the bitwise AND of any subarray of nums. Then, only subarrays with a bitwise AND equal to k should be considered.
Return the length of the longest such subarray.

The bitwise AND of an array is the bitwise AND of all the numbers in it.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,2,3,3,2,2]
Output: 2
Explanation:
The maximum possible bitwise AND of a subarray is 3.
The longest subarray with that value is [3,3], so we return 2.
Example 2:

Input: nums = [1,2,3,4]
Output: 1
Explanation:
The maximum possible bitwise AND of a subarray is 4.
The longest subarray with that value is [4], so we return 1.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106

