-- -- -- -- -- -- -- -- -GFG - POTD - 05 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Find the number of islands
Difficulty: MediumAccuracy: 42.12%Submissions: 234K+Points: 4Average Time: 20m
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:

Input: grid[][] = [['L', 'L', 'W', 'W', 'W'], ['W', 'L', 'W', 'W', 'L'], ['L', 'W', 'W', 'L', 'L'], ['W', 'W', 'W', 'W', 'W'], ['L', 'W', 'L', 'L', 'W']]
Output: 4
Explanation:
The image below shows all the 4 islands in the grid.
 
Input: grid[][] = [['W', 'L', 'L', 'L', 'W', 'W', 'W'], ['W', 'W', 'L', 'L', 'W', 'L', 'W']]
Output: 2
Expanation:
The image below shows 2 islands in the grid.
 
Constraints:
1 ≤ n, m ≤ 500
grid[i][j] = {'L', 'W'}

class Solution {
    public:
      int row,col;
     void islandHelper(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j)
      {
          if(i>=row||i<0||j>=col||j<0||grid[i][j]=='W'||vis[i][j]==1)return ;
          vis[i][j] = 1;
          islandHelper(grid,vis,i+1,j);
          islandHelper(grid,vis,i-1,j);
          islandHelper(grid,vis,i,j+1);
          islandHelper(grid,vis,i,j-1);
          islandHelper(grid,vis,i+1,j+1);
          islandHelper(grid,vis,i+1,j-1);
          islandHelper(grid,vis,i-1,j+1);
          islandHelper(grid,vis,i-1,j-1);
      }
      int countIslands(vector<vector<char>>& grid) {
          // Code here
          row = grid.size();
          col = grid[0].size();
          vector<vector<int>>vis(row,vector<int>(col,0));
          int islands = 0;
          for(int i =0 ;i<row;i++)
          {
              for(int j = 0;j<col;j++)
              {
                  if(!vis[i][j]&&grid[i][j]=='L')
                  {
                      islands++;
                      islandHelper(grid,vis,i,j);
                  }
              }
          }
          return islands;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 05 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------



1863. Sum of All Subset XOR Totals
Solved
Easy
Topics
Companies
Hint
The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
Given an array nums, return the sum of all XOR totals for every subset of nums. 

Note: Subsets with the same elements should be counted multiple times.

An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

 

Example 1:

Input: nums = [1,3]
Output: 6
Explanation: The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6
Example 2:

Input: nums = [5,1,6]
Output: 28
Explanation: The 8 subsets of [5,1,6] are:
- The empty subset has an XOR total of 0.
- [5] has an XOR total of 5.
- [1] has an XOR total of 1.
- [6] has an XOR total of 6.
- [5,1] has an XOR total of 5 XOR 1 = 4.
- [5,6] has an XOR total of 5 XOR 6 = 3.
- [1,6] has an XOR total of 1 XOR 6 = 7.
- [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
Example 3:

Input: nums = [3,4,5,6,7,8]
Output: 480
Explanation: The sum of all XOR totals for every subset is 480.
 

Constraints:

1 <= nums.length <= 12
1 <= nums[i] <= 20


class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int total = 0;
            for (int num : nums) {
                total |= num;  // Step 1: Compute bitwise OR of all numbers
            }
            return total * (1 << (nums.size() - 1));  // Step 2: Multiply by 2^(n-1)
        }
    };