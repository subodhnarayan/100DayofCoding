-- -- -- -- -- -- -- -- -GFG - POTD - 29 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Job Sequencing Problem
Difficulty: MediumAccuracy: 34.51%Submissions: 291K+Points: 4
You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
Examples :

Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).
Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).
Constraints:
1 ≤ deadline.size() == profit.size() ≤ 105
1 ≤ deadline[i] ≤ deadline.size()
1 ≤ profit[i] ≤ 500

class Solution {
    public:
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          // code here
          const int n = deadline.size();
          int amount = 0, done = 0;
          
          vector<pair<int, int>> jobs;
          vector<int> spaces(n + 1);
          
          iota(spaces.begin(), spaces.end(), 0);
          
          for(int i = 0; i < n; i++) {
              jobs.push_back({profit[i], deadline[i]});
          }
          
          sort(jobs.begin(), jobs.end());
          
          auto can_fit = [&](auto can_fit, int dead) -> int {
              if(spaces[dead] == 0) return -1;
              if(spaces[dead] == dead) {
                  return spaces[dead] = (dead - 1);
              }
              return spaces[dead] = can_fit(can_fit, spaces[dead]);
          }; 
          
          for(int i = n - 1; i >= 0; i--) {
              int val = jobs[i].first, dead = jobs[i].second;
              if(can_fit(can_fit, dead) != -1) {
                  amount += val;
                  done++;
              }
          }
       
          return {done, amount};
      }
  };



-- -- -- -- -- -- -- -- -LeetCode - POTD - 29 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


2818. Apply Operations to Maximize Score
Solved
Hard
Topics
Companies
Hint
You are given an array nums of n positive integers and an integer k.

Initially, you start with a score of 1. You have to maximize your score by applying the following operation at most k times:

Choose any non-empty subarray nums[l, ..., r] that you haven't chosen previously.
Choose an element x of nums[l, ..., r] with the highest prime score. If multiple such elements exist, choose the one with the smallest index.
Multiply your score by x.
Here, nums[l, ..., r] denotes the subarray of nums starting at index l and ending at the index r, both ends being inclusive.

The prime score of an integer x is equal to the number of distinct prime factors of x. For example, the prime score of 300 is 3 since 300 = 2 * 2 * 3 * 5 * 5.

Return the maximum possible score after applying at most k operations.

Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [8,3,9,3,8], k = 2
Output: 81
Explanation: To get a score of 81, we can apply the following operations:
- Choose subarray nums[2, ..., 2]. nums[2] is the only element in this subarray. Hence, we multiply the score by nums[2]. The score becomes 1 * 9 = 9.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 1, but nums[2] has the smaller index. Hence, we multiply the score by nums[2]. The score becomes 9 * 9 = 81.
It can be proven that 81 is the highest score one can obtain.
Example 2:

Input: nums = [19,12,14,6,10,18], k = 3
Output: 4788
Explanation: To get a score of 4788, we can apply the following operations: 
- Choose subarray nums[0, ..., 0]. nums[0] is the only element in this subarray. Hence, we multiply the score by nums[0]. The score becomes 1 * 19 = 19.
- Choose subarray nums[5, ..., 5]. nums[5] is the only element in this subarray. Hence, we multiply the score by nums[5]. The score becomes 19 * 18 = 342.
- Choose subarray nums[2, ..., 3]. Both nums[2] and nums[3] have a prime score of 2, but nums[2] has the smaller index. Hence, we multipy the score by nums[2]. The score becomes 342 * 14 = 4788.
It can be proven that 4788 is the highest score one can obtain.
 

Constraints:

1 <= nums.length == n <= 105
1 <= nums[i] <= 105
1 <= k <= min(n * (n + 1) / 2, 109)
class Solution {
public:
    const int MOD = 1e9 + 7;
    int maximumScore(vector<int>& nums, int k) {
       
       int n = nums.size();
        vector<int> primeScores(n);

        // Calculate the prime score for each number in nums
        for (int index = 0; index < n; index++) {
            int num = nums[index];

            // Check for prime factors from 2 to sqrt(n)
            for (int factor = 2; factor <= sqrt(num); factor++) {
                if (num % factor == 0) {
                    // Increment prime score for each prime factor
                    primeScores[index]++;

                    // Remove all occurrences of the prime factor from num
                    while (num % factor == 0) num /= factor;
                }
            }

            // If num is still greater than or equal to 2, it's a prime factor
            if (num >= 2) primeScores[index]++;
        }

        // Initialize next and previous dominant index arrays
        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);

        // Stack to store indices for monotonic decreasing prime score
        stack<int> decreasingPrimeScoreStack;

        // Calculate the next and previous dominant indices for each number
        for (int index = 0; index < n; index++) {
            // While the stack is not empty and the current prime score is
            // greater than the stack's top
            while (!decreasingPrimeScoreStack.empty() &&
                   primeScores[decreasingPrimeScoreStack.top()] <
                       primeScores[index]) {
                int topIndex = decreasingPrimeScoreStack.top();
                decreasingPrimeScoreStack.pop();

                // Set the next dominant element for the popped index
                nextDominant[topIndex] = index;
            }

            // If the stack is not empty, set the previous dominant element for
            // the current index
            if (!decreasingPrimeScoreStack.empty())
                prevDominant[index] = decreasingPrimeScoreStack.top();

            // Push the current index onto the stack
            decreasingPrimeScoreStack.push(index);
        }

        // Calculate the number of subarrays in which each element is dominant
        vector<long long> numOfSubarrays(n);
        for (int index = 0; index < n; index++) {
            numOfSubarrays[index] = (long long)(nextDominant[index] - index) *
                                    (index - prevDominant[index]);
        }

        // Priority queue to process elements in decreasing order of their value
        priority_queue<pair<int, int>> processingQueue;

        // Push each number and its index onto the priority queue
        for (int index = 0; index < n; index++)
            processingQueue.push({nums[index], index});

        long long score = 1;

        // Process elements while there are operations left
        while (k > 0) {
            // Get the element with the maximum value from the queue
            auto [num, index] = processingQueue.top();
            processingQueue.pop();

            // Calculate the number of operations to apply on the current
            // element
            long long operations = min((long long)k, numOfSubarrays[index]);

            // Update the score by raising the element to the power of
            // operations
            score = (score * power(num, operations)) % MOD;

            // Reduce the remaining operations count
            k -= operations;
        }

        return score;
    }

private:
    // Helper function to compute the power of a number modulo MOD
    long long power(long long base, long long exponent) {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0) {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res; 
    }
};

