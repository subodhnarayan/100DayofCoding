-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFg - POTD - 3 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

The Celebrity Problem
Difficulty: MediumAccuracy: 38.33%Submissions: 268K+Points: 4
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[0 1 0],
                [0 0 0], 
                [0 1 0]]
Output: 1
Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 
Input: mat[][] = [[0 1],
                [1 0]]
Output: -1
Explanation: The two people at the party both know each other. None of them is a celebrity.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(1)

Constraints:
1 <= mat.size()<= 3000
0 <= mat[i][j]<= 1

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
         int n = mat.size();
    vector<int> knows_me(n, 0), i_know(n, 0);
 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j])
            {
                knows_me[j]++;
                i_know[i]++;
            }
        }
    }
 

    int celebrity = -1;
    for (int i = 0; i < n; i++)
    {
        if (knows_me[i] == n - 1 && i_know[i] == 0){
            celebrity = i;
            break; // as we know there will be one celebrity always. Two or more is not possible 
             }
    }
 

    return celebrity;
    }
};

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFg - POTD - 3 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

1460. Make Two Arrays Equal by Reversing Subarrays
Solved
Easy
Topics
Companies
Hint
You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty subarray of arr and reverse it. You are allowed to make any number of steps.

Return true if you can make arr equal to target or false otherwise.

 

Example 1:

Input: target = [1,2,3,4], arr = [2,4,1,3]
Output: true
Explanation: You can follow the next steps to convert arr to target:
1- Reverse subarray [2,4,1], arr becomes [1,4,2,3]
2- Reverse subarray [4,2], arr becomes [1,2,4,3]
3- Reverse subarray [4,3], arr becomes [1,2,3,4]
There are multiple ways to convert arr to target, this is not the only way to do so.
Example 2:

Input: target = [7], arr = [7]
Output: true
Explanation: arr is equal to target without any reverses.
Example 3:

Input: target = [3,7,9], arr = [3,7,11]
Output: false
Explanation: arr does not have value 9 and it can never be converted to target.
 

Constraints:

target.length == arr.length
1 <= target.length <= 1000
1 <= target[i] <= 1000
1 <= arr[i] <= 1000


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> cnt1(1001);
        vector<int> cnt2(1001);
        for (int& v : target) {
            ++cnt1[v];
        }
        for (int& v : arr) {
            ++cnt2[v];
        }
        return cnt1 == cnt2;
    }
};