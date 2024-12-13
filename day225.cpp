-- -- -- -- -- -- -- -- -GFG - POTD - 13 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Sorted and Rotated Minimum
Difficulty: EasyAccuracy: 40.57%Submissions: 128K+Points: 2
A sorted array of distinct elements arr[] is rotated at some unknown point, the task is to find the minimum element in it. 

Examples:

Input: arr[] = [5, 6, 1, 2, 3, 4]
Output: 1
Explanation: 1 is the minimum element in the array.
Input: arr[] = [3, 1, 2]
Output: 1
Explanation: Here 1 is the minimum element.
Input: arr[] = [4, 2, 3]
Output: 2
Explanation: Here 2 is the minimum element.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ 109



class Solution {
  public:
    int findMin(vector<int>& arr) {
        //brute force
        // int n=arr.size();
        // int ans=INT_MAX;
        // for(int i=0;i<n;i++){
        //     ans=min(arr[i],ans);
        // }
        // return ans;  TC=O(N)
        
        int n=arr.size();
        int start=0;
        int end=n-1;
        int ans=INT_MAX;
        while(start<end){
            int mid=(start+end)/2;
            //left side sorted
            if(arr[end]<arr[mid]){
                start=mid+1;
            }
            else{
                end=mid;
            }
        }
        return arr[start];
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 13 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


2593. Find Score of an Array After Marking All Elements

You are given an array nums consisting of positive integers.

Starting with score = 0, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.

 

Example 1:

Input: nums = [2,1,3,4,5,2]
Output: 7
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
- 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
- 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
Our score is 1 + 2 + 4 = 7.
Example 2:

Input: nums = [2,3,5,1,3,2]
Output: 5
Explanation: We mark the elements as follows:
- 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
- 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
- 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
Our score is 1 + 2 + 2 = 5.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106


class Solution {
public:
    long long findScore(vector<int>& nums) {
        long score = 0;
        int n = nums.size();

        // Processing alternating elements
        for (int i = 0; i < n; i += 2) 
        {
            // Store the starting index for the current segment
            int i0 = i;

            // Find the last element in decreasing segment
            while (i + 1 < n && nums[i] > nums[i + 1])
                // Just keep moving to the next element if it's smaller
                ++i;

            // Add the elements of the current decreasing segment to the score
            for (int j = i; j >= i0; j -= 2)
                // Add every alternate element in this segment to the score
                score += nums[j];
        }

        // Marking adjacent elements and summing scores
        vector<bool> marked(n, false);
        long sorted = 0;

        // Loop through each element in the nums array
        for (int i = 0; i < n; ++i) 
        {
            // If the current element is not marked, process it
            if (!marked[i]) 
            {
                // Add the current elements value to the score
                // Actually, I don't need this
                sorted += nums[i];

                // Mark the left neighbor
                if (i - 1 >= 0) 
                {
                    marked[i - 1] = true;
                }
                // Mark the right neighbor
                if (i + 1 < n) 
                {
                    marked[i + 1] = true;
                }
            }
        }
        // Return the total score accumulated
        return score;
    }
};