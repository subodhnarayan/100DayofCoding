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

