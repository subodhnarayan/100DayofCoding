-- -- -- -- -- -- -- -- -GFG - POTD - 30 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Gas Station
Difficulty: MediumAccuracy: 34.79%Submissions: 193K+Points: 4Average Time: 20m
There are some gas stations along a circular route. You are given two integer arrays gas[] denoted as the amount of gas present at each station and cost[] denoted as the cost of travelling to the next station. You have a car with an unlimited gas tank. You begin the journey with an empty tank from one of the gas stations. Return the index of the starting gas station if it's possible to travel around the circuit without running out of gas at any station in a clockwise direction. If there is no such starting station exists, return -1.
Note: If a solution exists, it is guaranteed to be unique.

Examples:

Input: gas[] = [4, 5, 7, 4], cost[]= [6, 6, 3, 5]
Output: 2
Explanation: It is possible to travel around the circuit from station at index 2. Amount of gas at station 2 is (0 + 7) = 7.
Travel to station 3. Available gas = (7 – 3 + 4) = 8.
Travel to station 0. Available gas = (8 – 5 + 4) = 7.
Travel to station 1. Available gas = (7 – 6 + 5) = 6.
Return to station 2. Available gas = (6 – 6) = 0.
Input: gas[] = [1, 2, 3, 4, 5], cost[] = [3, 4, 5, 1, 2]
Output: 3
Explanation: It is possible to travel around the circuit from station at index 3. Amount of gas at station 3 is (0 + 4) = 4.
Travel to station 4. Available gas = 4 – 1 + 5 = 8.
Travel to station 0. Available gas = 8 – 2 + 1 = 7.
Travel to station 1. Available gas= 7 – 3 + 2 = 6.
Travel to station 2. Available gas = 6 – 4 + 3 = 5.
Travel to station 3. The cost is 5. The gas is just enough to travel back to station 3.
Input: gas[] = [3, 9], cost[] = [7, 6]
Output: -1
Explanation: There is no gas station to start with such that you can complete the circuit.
Constraints:
1 ≤ gas.size(), cost.size() ≤ 106
1 ≤ gas[i], cost[i] ≤ 103

Time Complexity: O(n)Auxiliary Space: O(1)

 int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
         int n = gas.size();
        int totalGas = 0, totalCost = 0;
        
        // Step 1: Check if total gas is enough to cover total cost
        for(int i = 0; i < n; ++i) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalCost > totalGas) return -1; // Not possible to complete the circuit
        
        int total = 0, ans = 0;
        
        // Step 2: Find the optimal starting station
        for(int i = 0; i < n; ++i) {
            total += (gas[i] - cost[i]); // Update current gas balance
            if(total < 0) { // If deficit, reset and try next station
                ans = (i + 1) % n; // Next station is the new candidate
                total = 0; // Reset gas balance
            }
        }
        
        return ans; // The correct starting index
}


-- -- -- -- -- -- -- -- -LeetCode - POTD - 30 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


763. Partition Labels
Solved
Medium
Topics
Companies
Hint
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
 

Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.

class Solution {
public:
    vector<int> partitionLabels(string s) {
         unordered_map<char, int> last_occurrence;
        for (int i = 0; i < s.size(); i++) {
            last_occurrence[s[i]] = i;
        }

        vector<int> result;
        int start = 0, end = 0;

        for (int i = 0; i < s.size(); i++) {
            end = max(end, last_occurrence[s[i]]);
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return result;
    }
};
