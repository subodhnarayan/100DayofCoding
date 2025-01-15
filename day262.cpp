-- -- -- -- -- -- -- -- -GFG - POTD - 15 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Longest Subarray with Sum K
Difficulty: MediumAccuracy: 24.64%Submissions: 552K+Points: 4
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Only subarray with sum = 15 is [-5, 8, -14, 2, 4] of length 5.
Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
-109 ≤ k ≤ 109


class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map<int, int> prefixSum;
        int sum = 0;
        int ansLength = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];//-5,3,-11,-9,-5,7
            
           
            if (sum == k) {
                
                ansLength = max(ansLength, i + 1);//1
            }
            
          
            if (prefixSum.find(sum - k) != prefixSum.end()) {
                
                ansLength = max(ansLength, i - prefixSum[sum - k]);
            }
            
            
            if (prefixSum.find(sum) == prefixSum.end()) {
                prefixSum[sum] = i;
            }
        }
        
        return ansLength;
    }
};

-- -- -- -- -- -- -- -- -LeetCode - POTD - 15 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
2429. Minimize XOR
Solved
Medium
Topics
Companies
Hint
Given two positive integers num1 and num2, find the positive integer x such that:

x has the same number of set bits as num2, and
The value x XOR num1 is minimal.
Note that XOR is the bitwise XOR operation.

Return the integer x. The test cases are generated such that x is uniquely determined.

The number of set bits of an integer is the number of 1's in its binary representation.

 

Example 1:

Input: num1 = 3, num2 = 5
Output: 3
Explanation:
The binary representations of num1 and num2 are 0011 and 0101, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 3 = 0 is minimal.
Example 2:

Input: num1 = 1, num2 = 12
Output: 3
Explanation:
The binary representations of num1 and num2 are 0001 and 1100, respectively.
The integer 3 has the same number of set bits as num2, and the value 3 XOR 1 = 2 is minimal.
 

Constraints:

1 <= num1, num2 <= 109

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // Initialize result to num1. We will modify result.
        int result = num1;

        int targetSetBitsCount = __builtin_popcount(num2);
        int setBitsCount = __builtin_popcount(result);

        // Start with the least significant bit (bit 0).
        int currentBit = 0;

        // Add bits to result if it has fewer set bits than the target.
        while (setBitsCount < targetSetBitsCount) {
            // If the current bit in result is not set (0), set it to 1.
            if (!isSet(result, currentBit)) {
                setBit(result, currentBit);
                setBitsCount++;
            }
            // Move to the next bit.
            currentBit++;
        }

        // Remove bits from result if it has more set bits than the target.
        while (setBitsCount > targetSetBitsCount) {
            // If the current bit in result is set (1), unset it (make it 0).
            if (isSet(result, currentBit)) {
                unsetBit(result, currentBit);
                setBitsCount--;
            }
            // Move to the next bit.
            currentBit++;
        }

        return result;
    }

private:
    // Helper function to check if the given bit position in x is set (1).
    bool isSet(int x, int bit) { return x & (1 << bit); }

    // Helper function to set the given bit position in x to 1.
    void setBit(int &x, int bit) { x |= (1 << bit); }

    // Helper function to unset the given bit position in x (set it to 0).
    void unsetBit(int &x, int bit) { x &= ~(1 << bit); }
};
