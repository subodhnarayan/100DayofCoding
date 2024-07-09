// GFG POTD 9/7/2024
//  Closest Three Sum
//  Difficulty: MediumAccuracy: 17.65%Submissions: 68K+Points: 4
//  Given an array, arr of integers, and another number target, find three integers in the array such that their sum is closest to the target. Return the sum of the three integers.

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

class Solution
{
public:
    int threeSumClosest(vector<int> arr, int target)
    {
        int n = arr.size();
        std::sort(arr.begin(), arr.end()); // Step 1: Sort the array
        int closest_sum = INT_MAX / 2;     // Initialize closest_sum to a very large value

        for (int i = 0; i < n - 2; ++i)
        { // We need at least three numbers
            int start = i + 1;
            int end = n - 1;

            while (start < end)
            { // Step 2: Two-pointer technique
                int current_sum = arr[i] + arr[start] + arr[end];

                // Update the closest_sum if current_sum is closer to the target
                if (std::abs(current_sum - target) < std::abs(closest_sum - target))
                {
                    closest_sum = current_sum;
                }
                else if (std::abs(current_sum - target) == std::abs(closest_sum - target))
                {
                    // If the absolute difference is the same, choose the maximum sum
                    closest_sum = std::max(closest_sum, current_sum);
                }

                // Move pointers based on comparison with target
                if (current_sum < target)
                {
                    ++start;
                }
                else if (current_sum > target)
                {
                    --end;
                }
                else
                {
                    // If current_sum is exactly equal to target, return the sum
                    return current_sum;
                }
            }
        }

        return closest_sum; // Return the closest sum fou
    }
};

// Leetcode POTD 9/7/2024

// 1701. Average Waiting Time
// Solved
// Medium
// Topics
// Companies
// Hint
// There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:

// arrivali is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
// timei is the time needed to prepare the order of the ith customer.
// When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. The chef prepares food for customers in the order they were given in the input.

// Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.

// Example 1:

// Input: customers = [[1,2],[2,5],[4,3]]
// Output: 5.00000
// Explanation:
// 1) The first customer arrives at time 1, the chef takes his order and starts preparing it immediately at time 1, and finishes at time 3, so the waiting time of the first customer is 3 - 1 = 2.
// 2) The second customer arrives at time 2, the chef takes his order and starts preparing it at time 3, and finishes at time 8, so the waiting time of the second customer is 8 - 2 = 6.
// 3) The third customer arrives at time 4, the chef takes his order and starts preparing it at time 8, and finishes at time 11, so the waiting time of the third customer is 11 - 4 = 7.
// So the average waiting time = (2 + 6 + 7) / 3 = 5.
// Example 2:

// Input: customers = [[5,2],[5,4],[10,3],[20,1]]
// Output: 3.25000
// Explanation:
// 1) The first customer arrives at time 5, the chef takes his order and starts preparing it immediately at time 5, and finishes at time 7, so the waiting time of the first customer is 7 - 5 = 2.
// 2) The second customer arrives at time 5, the chef takes his order and starts preparing it at time 7, and finishes at time 11, so the waiting time of the second customer is 11 - 5 = 6.
// 3) The third customer arrives at time 10, the chef takes his order and starts preparing it at time 11, and finishes at time 14, so the waiting time of the third customer is 14 - 10 = 4.
// 4) The fourth customer arrives at time 20, the chef takes his order and starts preparing it immediately at time 20, and finishes at time 21, so the waiting time of the fourth customer is 21 - 20 = 1.
// So the average waiting time = (2 + 6 + 4 + 1) / 4 = 3.25.

// Constraints:

// 1 <= customers.length <= 105
// 1 <= arrivali, timei <= 104
// arrivali <= arrivali+1

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        int N = customers.size();
        double serviceTime = customers[0][0] + customers[0][1];
        double totalWait = serviceTime - customers[0][0];

        for (int i = 1; i < N; i++)
        {
            if (serviceTime < customers[i][0])
                serviceTime = customers[i][0];
            serviceTime += customers[i][1];
            totalWait += (serviceTime - customers[i][0]);
        }
        return totalWait / N;
    }
};