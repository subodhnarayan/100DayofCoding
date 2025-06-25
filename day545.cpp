-- -- -- -- -- -- -- -- -GFG - POTD - 25 / 06 / 2025 ----------------------------------------

Check if frequencies can be equal
Difficulty: MediumAccuracy: 16.67%Submissions: 134K+Points: 4
Given a string s consisting only lowercase alphabetic characters, check whether it is possible to remove at most one character such that the  frequency of each distinct character in the string becomes same. Return true if it is possible; otherwise, return false.

Examples:

Input: s = "xyyz"
Output: true 
Explanation: Removing one 'y' will make frequency of each distinct character to be 1.
Input: s = "xyyzz"
Output: true
Explanation: Removing one 'x' will make frequency of each distinct character to be 2.
Input: s = "xxxxyyzz"
Output: false
Explanation: Frequency can not be made same by removing at most one character.
Constraints:
1 ≤ s.size() ≤ 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int> mp(26, 0);
        for(char ch : s) mp[ch - 'a']++;
        unordered_set<int> ss;
        int mx = 0, mn = 100000;
        unordered_map<int, int> freq;
        for(int i = 0 ; i < 26 ; i++) {
            if(mp[i] != 0) {
                ss.insert(mp[i]);
                freq[mp[i]]++;
                mx = max(mx, mp[i]);
                mn = min(mn, mp[i]);
            }
        }
        if(ss.size() > 2) return false;
        if((mx == mn) || (mn == 1 && freq[mn] == 1) || (freq[mx] == 1 && mx - mn == 1)) return true;
        return false;
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 25 / 06 / 2025 ----------------------------------------



2040. Kth Smallest Product of Two Sorted Arrays
Solved
Hard
Topics
premium lock icon
Companies
Hint
Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.
 

Example 1:

Input: nums1 = [2,5], nums2 = [3,4], k = 2
Output: 8
Explanation: The 2 smallest products are:
- nums1[0] * nums2[0] = 2 * 3 = 6
- nums1[0] * nums2[1] = 2 * 4 = 8
The 2nd smallest product is 8.
Example 2:

Input: nums1 = [-4,-2,0,3], nums2 = [2,4], k = 6
Output: 0
Explanation: The 6 smallest products are:
- nums1[0] * nums2[1] = (-4) * 4 = -16
- nums1[0] * nums2[0] = (-4) * 2 = -8
- nums1[1] * nums2[1] = (-2) * 4 = -8
- nums1[1] * nums2[0] = (-2) * 2 = -4
- nums1[2] * nums2[0] = 0 * 2 = 0
- nums1[2] * nums2[1] = 0 * 4 = 0
The 6th smallest product is 0.
Example 3:

Input: nums1 = [-2,-1,0,1,2], nums2 = [-3,-1,2,4,5], k = 3
Output: -6
Explanation: The 3 smallest products are:
- nums1[0] * nums2[4] = (-2) * 5 = -10
- nums1[0] * nums2[3] = (-2) * 4 = -8
- nums1[4] * nums2[0] = 2 * (-3) = -6
The 3rd smallest product is -6.
 

Constraints:

1 <= nums1.length, nums2.length <= 5 * 104
-105 <= nums1[i], nums2[j] <= 105
1 <= k <= nums1.length * nums2.length
nums1 and nums2 are sorted.



class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2,
                                 long long k) {
        int n1 = nums1.size(), n2 = nums2.size();
        int pos1 = 0, pos2 = 0;
        while (pos1 < n1 && nums1[pos1] < 0) {
            pos1++;
        }
        while (pos2 < n2 && nums2[pos2] < 0) {
            pos2++;
        }
        long long left = -1e10, right = 1e10;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long count = 0;
            for (int i1 = 0, i2 = pos2 - 1; i1 < pos1 && i2 >= 0;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i1++;
                } else {
                    count += pos1 - i1;
                    i2--;
                }
            }
            for (int i1 = pos1, i2 = n2 - 1; i1 < n1 && i2 >= pos2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i2--;
                } else {
                    count += i2 - pos2 + 1;
                    i1++;
                }
            }
            for (int i1 = 0, i2 = pos2; i1 < pos1 && i2 < n2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i2++;
                } else {
                    count += n2 - i2;
                    i1++;
                }
            }
            for (int i1 = pos1, i2 = 0; i1 < n1 && i2 < pos2;) {
                if (static_cast<long long>(nums1[i1]) * nums2[i2] > mid) {
                    i1++;
                } else {
                    count += n1 - i1;
                    i2++;
                }
            }
            if (count < k) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};