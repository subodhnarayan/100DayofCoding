-- -- -- -- -- -- -- -- -GFG - POTD - 12 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Flood fill Algorithm
Difficulty: MediumAccuracy: 41.11%Submissions: 137K+Points: 4Average Time: 15m
You are given a 2D grid image[][] of size n*m, where each image[i][j] represents the color of a pixel in the image. Also provided a coordinate(sr, sc) representing the starting pixel (row and column) and a new color value newColor.

Your task is to perform a flood fill starting from the pixel (sr, sc), changing its color to newColor and the color of all the connected pixels that have the same original color. Two pixels are considered connected if they are adjacent horizontally or vertically (not diagonally) and have the same original color.

Examples:

Input: image[][] = [[1, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]], sr = 1, sc = 2, newColor = 2

Output: [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]]

Explanation: Starting from pixel (1, 2) with value 1, flood fill updates all connected pixels (up, down, left, right) with value 1 to 2, resulting in [[2, 2, 2, 0], [0, 2, 2, 2], [1, 0, 2, 2]].
Input: image[][] = [[1, 1, 1], [1, 1, 0], [1, 0, 1]], sr = 1, sc = 1, newColor = 2
Output: [[2, 2, 2], [2, 2, 0], [2, 0, 1]]
Explanation: From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected by a path of the same color as the starting pixel are colored with the new color.Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Input: image[][] = [[0, 1, 0], [0, 1, 0]], sr = 0, sc = 1, newColor = 0
Output: [[0, 0, 0], [0, 0, 0]]
Explanation: Starting from pixel (0, 1) with value 1, flood fill changes all 4-directionally connected pixels with value 1 to 0, resulting in [[0, 0, 0], [0, 0, 0]]
Constraints:
1 ≤ n ≤ m ≤ 500
0 ≤ image[i][j] ≤ 10
0 ≤ newColor ≤ 10
0 ≤ sr ≤ (n-1)
0 ≤ sc ≤ (m-1)
Expected Complexities
Time Complexity: O(n * m)
Auxiliary Space: O(n * m)

class Solution {
    public:
     int m, n;
      vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
      
      void dfs(vector<vector<int>>& image, int i, int j, int val,int currColor) {
          
          if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] != currColor){
              return;
          }
          image[i][j] = val;
          
          for(auto& dir : directions){
              int x = i + dir[0];
              int y = j + dir[1];
              dfs(image,x,y,val,currColor);
          }
      }
      vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                    int newColor) {
           
          m = image.size();
          n = image[0].size();
          int currColor = image[sr][sc];
          if(currColor != newColor){
              dfs(image,sr,sc,newColor,currColor); 
          }
          return image;
          
      }
  };



-- -- -- -- -- -- -- -- -LeetCode - POTD - 12 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

3272. Find the Count of Good Integers
Solved
Hard
Topics
Companies
Hint
You are given two positive integers n and k.

An integer x is called k-palindromic if:

x is a palindrome.
x is divisible by k.
An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.

Return the count of good integers containing n digits.

Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.

 

Example 1:

Input: n = 3, k = 5

Output: 27

Explanation:

Some of the good integers are:

551 because it can be rearranged to form 515.
525 because it is already k-palindromic.
Example 2:

Input: n = 1, k = 4

Output: 2

Explanation:

The two good integers are 4 and 8.

Example 3:

Input: n = 5, k = 6

Output: 2468

 

Constraints:

1 <= n <= 10
1 <= k <= 9
