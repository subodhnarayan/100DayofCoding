-- -- -- -- -- -- -- -- -GFG - POTD - 16 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

K-th element of two Arrays
Difficulty: MediumAccuracy: 37.4%Submissions: 298K+Points: 4
Given two sorted arrays a[] and b[] and an element k, the task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: a[] = [2, 3, 6, 7, 9], b[] = [1, 4, 8, 10], k = 5
Output: 6
Explanation: The final combined sorted array would be [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element of this array is 6.
Input: a[] = [100, 112, 256, 349, 770], b[] = [72, 86, 113, 119, 265, 445, 892], k = 7
Output: 256
Explanation: Combined sorted array is [72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892]. The 7th element of this array is 256.
Constraints:

1 <= a.size(), b.size() <= 106
1 <= k <= a.size() + b.size()
0 <= a[i], b[i] < 10


class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
         int s1 = a.size();
        int s2 = b.size();
        int i = 0;
        int j = 0;
        int ans = -1;
        while ( i < s1 && j < s2 ) {
            if ( a[ i ] < b[ j ] )
                ans = a[i++];
            else
                ans = b[j++];
            if ( --k == 0 ) return ans;
        }
        while ( i++ < s1 ) {
            if ( --k == 0 ) return a[ i - 1 ];
        }
        while ( j++ < s2 ) {
            if ( --k == 0 ) return b[ j - 1 ];
        }
        return -1;
    }
};



-- -- -- -- -- -- -- -- -Leetcode - POTD - 16 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


3264. Final Array State After K Multiplication Operations I
Solved
Easy
Topics
Companies
Hint
You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. In each operation:

Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.

 

Example 1:

Input: nums = [2,1,3,5,6], k = 5, multiplier = 2

Output: [8,4,6,5,6]

Explanation:

Operation	Result
After operation 1	[2, 2, 3, 5, 6]
After operation 2	[4, 2, 3, 5, 6]
After operation 3	[4, 4, 3, 5, 6]
After operation 4	[4, 4, 6, 5, 6]
After operation 5	[8, 4, 6, 5, 6]
Example 2:

Input: nums = [1,2], k = 3, multiplier = 4

Output: [16,8]

Explanation:

Operation	Result
After operation 1	[4, 2]
After operation 2	[4, 8]
After operation 3	[16, 8]
 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100
1 <= k <= 10
1 <= multiplier <= 5


class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
          vector<pair<int, int>> heap;
        for (int i = 0; i < nums.size(); i++) {
            heap.push_back({nums[i], i});
        }

        make_heap(heap.begin(), heap.end(), greater<>());

        while (k--) {
            pop_heap(heap.begin(), heap.end(), greater<>());
            auto [value, i] = heap.back();
            heap.pop_back();

            nums[i] *= multiplier;
            heap.push_back({nums[i], i});
            push_heap(heap.begin(), heap.end(), greater<>());
        }

        return nums;
    }
};
