-- -- -- -- -- -- -- -- -GFG - POTD - 16 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Largest subarray of 0's and 1's
Difficulty: EasyAccuracy: 32.96%Submissions: 107K+Points: 2
Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

Examples:

Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
Output: 6
Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.
Input: arr[] = [0, 0, 1, 1, 0]
Output: 4
Explnation: arr[0...3] or arr[1...4] is the longest subarray with two 0s and two 1s.
Input: arr[] = [0]
Output: 0
Explnation: There is no subarray with an equal number of 0s and 1s.
Constraints:
1 <= arr.size() <= 105
0 <= arr[i] <= 1

class Solution {
  public:
    int maxLen(vector<int> &arr) {
         // Your code here
        unordered_map<int,int>m;
        int n = arr.size();
        int sum = 0;
        int ans = 0;
        m[0] = -1;
        for(int i=0;i<n;i++){
            if(arr[i]==0)sum--;
            else sum++;
            if(m.find(sum)!=m.end()){
                ans = max(ans,i-m[sum]);
            }
            if(m.find(sum)==m.end()){
                m[sum] = i;
            }
        }
        return ans;
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 16 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
2425. Bitwise XOR of All Pairings
Solved
Medium
Topics
Companies
Hint
You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).

Return the bitwise XOR of all integers in nums3.

 

Example 1:

Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13
Explanation:
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.
Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 0
Explanation:
All possible pairs of bitwise XORs are nums1[0] ^ nums2[0], nums1[0] ^ nums2[1], nums1[1] ^ nums2[0],
and nums1[1] ^ nums2[1].
Thus, one possible nums3 array is [2,5,1,6].
2 ^ 5 ^ 1 ^ 6 = 0, so we return 0.
 

Constraints:

1 <= nums1.length, nums2.length <= 105
0 <= nums1[i], nums2[j] <= 109

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // Initialize XOR results for both arrays
        int xor1 = 0;
        int xor2 = 0;

        // Get lengths of both arrays
        int len1 = nums1.size();
        int len2 = nums2.size();

        // If nums2 length is odd, each element in nums1 appears odd times in
        // final result
        if (len2 % 2 != 0) {
            for (int num : nums1) {
                xor1 ^= num;
            }
        }

        // If nums1 length is odd, each element in nums2 appears odd times in
        // final result
        if (len1 % 2 != 0) {
            for (int num : nums2) {
                xor2 ^= num;
            }
        }

        // Return XOR of both results
        return xor1 ^ xor2;
    }
};
