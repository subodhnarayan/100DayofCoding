-- -- -- -- -- -- -- -- -GFG - POTD - 12 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Number of occurrence
Difficulty: EasyAccuracy: 59.34%Submissions: 268K+Points: 2
Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

Examples :

Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
Output: 4
Explanation: target = 2 occurs 4 times in the given array so the output is 4.
Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
Output: 0
Explanation: target = 4 is not present in the given array so the output is 0.
Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
Output: 3
Explanation: target = 12 occurs 3 times in the given array so the output is 3.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 106
1 ≤ target ≤ 106

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // int count=0;
        // for(int i=0;i<arr.size();i++){
        //     if(arr[i]==target){
        //         count++;
        //     }
        // }
        // return count;
        int n=arr.size();
        int find=-1;
        int lind=-1;
        int start=0;
        int end=n-1;
        
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]>=target){
                if(arr[mid]==target){
                find=mid;
                }
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        start=0;
        end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]<=target){
                if(arr[mid]==target){
                lind=mid;
                }
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        if(find==-1 || lind==-1) return 0;
        
        return lind-find+1;
        
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 12 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -



2558. Take Gifts From the Richest Pile
Solved
Easy
Topics
Companies
Hint
You are given an integer array gifts denoting the number of gifts in various piles. Every second, you do the following:

Choose the pile with the maximum number of gifts.
If there is more than one pile with the maximum number of gifts, choose any.
Leave behind the floor of the square root of the number of gifts in the pile. Take the rest of the gifts.
Return the number of gifts remaining after k seconds.

 

Example 1:

Input: gifts = [25,64,9,4,100], k = 4
Output: 29
Explanation: 
The gifts are taken in the following way:
- In the first second, the last pile is chosen and 10 gifts are left behind.
- Then the second pile is chosen and 8 gifts are left behind.
- After that the first pile is chosen and 5 gifts are left behind.
- Finally, the last pile is chosen again and 3 gifts are left behind.
The final remaining gifts are [5,8,9,4,3], so the total number of gifts remaining is 29.
Example 2:

Input: gifts = [1,1,1,1], k = 4
Output: 4
Explanation: 
In this case, regardless which pile you choose, you have to leave behind 1 gift in each pile. 
That is, you can't take any pile with you. 
So, the total gifts remaining are 4.
 

Constraints:

1 <= gifts.length <= 103
1 <= gifts[i] <= 109
1 <= k <= 103