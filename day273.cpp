
-- -- -- -- -- -- -- -- -GFG - POTD - 26 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Remove loop in Linked List
Difficulty: MediumAccuracy: 27.66%Submissions: 494K+Points: 4
Given the head of a linked list that may contain a loop.  A loop means that the last node of the linked list is connected back to a node in the same list. The task is to remove the loop from the linked list (if it exists).

Custom Input format:

A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.

The generated output will be true if there is no loop in list and other nodes in the list remain unchanged, otherwise, false.

Examples:

Input: head = 1 -> 3 -> 4, pos = 2
Output: true
Explanation: The linked list looks like

A loop is present in the list, and it is removed.
Input: head = 1 -> 8 -> 3 -> 4, pos = 0
Output: true
Explanation: 

The Linked list does not contains any loop. 
Input: head = 1 -> 2 -> 3 -> 4, pos = 1
Output: true
Explanation: The linked list looks like 

A loop is present in the list, and it is removed.
Constraints:
1 ≤ size of linked list ≤ 105

-- -- -- -- -- -- -- -- -LeetCode - POTD - 26 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -



A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.

 

Example 1:


Input: favorite = [2,2,1,2]
Output: 3
Explanation:
The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
The maximum number of employees that can be invited to the meeting is 3. 
Example 2:

Input: favorite = [1,2,0]
Output: 3
Explanation: 
Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
The seating arrangement will be the same as that in the figure given in example 1:
- Employee 0 will sit between employees 2 and 1.
- Employee 1 will sit between employees 0 and 2.
- Employee 2 will sit between employees 1 and 0.
The maximum number of employees that can be invited to the meeting is 3.
Example 3:


Input: favorite = [3,0,1,4,1]
Output: 4
Explanation:
The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
So the company leaves them out of the meeting.
The maximum number of employees that can be invited to the meeting is 4.
 

Constraints:

n == favorite.length
2 <= n <= 105
0 <= favorite[i] <= n - 1
favorite[i] != i



class Solution {
public:
    int maximumInvitations(vector<int>& favorites) {
         int n = favorites.size();
        vector<int> inDegree(n, 0), chainLengths(n, 0);
        vector<bool> visited(n, false);

        for (int fav : favorites) {
            inDegree[fav]++;
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = true;

            int next = favorites[node];
            chainLengths[next] = chainLengths[node] + 1;
            if (--inDegree[next] == 0) {
                q.push(next);
            }
        }

        int maxCycle = 0, totalChains = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int current = i, cycleLength = 0;
                while (!visited[current]) {
                    visited[current] = true;
                    current = favorites[current];
                    cycleLength++;
                }

                if (cycleLength == 2) {
                    totalChains += 2 + chainLengths[i] + chainLengths[favorites[i]];
                } else {
                    maxCycle = max(maxCycle, cycleLength);
                }
            }
        }

        return max(maxCycle, totalChains);
    }
};