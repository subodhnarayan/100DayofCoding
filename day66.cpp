//GFG POTD 9/7/2024
// Closest Three Sum
// Difficulty: MediumAccuracy: 17.65%Submissions: 68K+Points: 4
// Given an array, arr of integers, and another number target, find three integers in the array such that their sum is closest to the target. Return the sum of the three integers.

// Note: If there are multiple solutions, return the maximum one.

// Examples :

// Input: arr[] = [-7, 9, 8, 3, 1, 1], target = 2
// Output: 2
// Explanation: There is only one triplet present in the array where elements are -7,8,1 whose sum is 2.
// Input: arr[] = [5, 2, 7, 5], target = 13
// Output: 14
// Explanation: There is one triplet with sum 12 and other with sum 14 in the array. Triplet elements are 5, 2, 5 and 2, 7, 5 respectively. Since abs(13-12) ==abs(13-14) maximum triplet sum will be preferred i.e 14.
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(1)

// Constraints:
// 3 ≤ arr.size() ≤ 103
// -105 ≤ arr[i] ≤ 105
// 1 ≤ target ≤ 105

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        int n = arr.size();
    std::sort(arr.begin(), arr.end());  // Step 1: Sort the array
    int closest_sum = INT_MAX / 2;  // Initialize closest_sum to a very large value

    for (int i = 0; i < n - 2; ++i) {  // We need at least three numbers
        int start = i + 1;
        int end = n - 1;

        while (start < end) {  // Step 2: Two-pointer technique
            int current_sum = arr[i] + arr[start] + arr[end];

            // Update the closest_sum if current_sum is closer to the target
            if (std::abs(current_sum - target) < std::abs(closest_sum - target)) {
                closest_sum = current_sum;
            } else if (std::abs(current_sum - target) == std::abs(closest_sum - target)) {
                // If the absolute difference is the same, choose the maximum sum
                closest_sum = std::max(closest_sum, current_sum);
            }

            // Move pointers based on comparison with target
            if (current_sum < target) {
                ++start;
            } else if (current_sum > target) {
                --end;
            } else {
                // If current_sum is exactly equal to target, return the sum
                return current_sum;
            }
        }
    }

    return closest_sum;  // Return the closest sum fou
        
    }
};