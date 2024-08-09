-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 9 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Maximize Array Value After Rearrangement
Difficulty: EasyAccuracy: 18.93%Submissions: 265K+Points: 2
Given an array arr of n integers. Your task is to write a program to find the maximum value of ∑arr[i]*i, where i = 0, 1, 2,., n-1. You are allowed to rearrange the elements of the array.

Note: Since the output could be large, print the answer modulo 109+7.

Examples :

Input : arr[] = [5, 3, 2, 4, 1]
Output : 40
Explanation: If we arrange the array as 1 2 3 4 5 then we can see that the minimum index will multiply with minimum number and maximum index will multiply with maximum number. So, 1*0 + 2*1 + 3*2 + 4*3 + 5*4 = 0+2+6+12+20 = 40 mod(109+7) = 40

Input : arr[] = [1, 2, 3]
Output : 8
Expected Time Complexity: O(nlog(n))
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size ≤ 105
1 ≤ arri ≤ 105

class Solution {
  public:
    int Maximize(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        long sum=0;
        long mod=1000000007;
        for(int i=0;i<arr.size();i++)
        {
            arr[i]=((arr[i]%mod)*i)%mod;
            sum=((sum%mod)+arr[i])%mod;
        }
        return sum;
    }
};



840. Magic Squares In Grid
Solved
Medium
Topics
Companies
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

Example 1:


Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.
Example 2:

Input: grid = [[8]]
Output: 0
 

Constraints:

row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15


