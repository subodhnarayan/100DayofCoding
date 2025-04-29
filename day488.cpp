-- -- -- -- -- -- -- -- -GFG - POTD - 30 / 04 / 2025 -----------------------------------

Sort a linked list of 0s, 1s and 2s
Difficulty: MediumAccuracy: 60.75%Submissions: 244K+Points: 4Average Time: 30m
Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

Examples:

Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2

Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2

Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
Input: head = 2 → 2 → 0 → 1

Output: 0 → 1 → 2 → 2

Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be 0 → 1 → 2 → 2.
Constraints:
1 ≤ no. of nodes ≤ 106
0 ≤ node->data ≤ 2

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)


class Solution {
    public:
      Node* segregate(Node* head) {
          // code here
          vector<int> mp(3, 0);
          Node* start = head;
          while(start)
          {
              mp[start->data]++;
              start = start->next;
          }
          start = head;
          int num_0 = mp[0], num_1 = mp[1], num_2 = mp[2];
          
          for(int i = 0; i < num_0; i++)
          {
              start->data = 0;
              start = start->next;
          }
          for(int i = 0; i < num_1; i++)
          {
              start->data = 1;
              start = start->next;
          }
          for(int i = 0; i < num_2; i++)
          {
              start->data = 2;
              start = start->next;
          }
          return head;
      }
  };


-- -- -- -- -- -- -- -- -Leetcode - POTD - 30 / 04 / 2025 -----------------------------------

2962. Count Subarrays Where Max Element Appears at Least K Times
Solved
Medium
Topics
Companies
You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105



class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
             int maxElement = *max_element(nums.begin(), nums.end());
            vector<int> indexesOfMaxElements;
            long long ans = 0;
    
            for (int index = 0; index < nums.size(); index++) {
                if (nums[index] == maxElement) {
                    indexesOfMaxElements.push_back(index);
                }
    
                int freq = indexesOfMaxElements.size();
                if (freq >= k) {
                    ans += indexesOfMaxElements[freq - k] + 1;
                }
            }
    
            return ans;
        }
};
