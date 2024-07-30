-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFg - POTD - 30 / 07 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Rat in a Maze Problem - I
Difficulty: MediumAccuracy: 35.75%Submissions: 274K+Points: 4
Consider a rat placed at (0, 0) in a square matrix mat of order n* n. It has to reach the destination at (n - 1, n - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell. In case of no path, return an empty list. The driver will output "-1" automatically.

Examples:

Input: mat[][] = [[1, 0, 0, 0],
                [1, 1, 0, 1], 
                [1, 1, 0, 0],
                [0, 1, 1, 1]]
Output: DDRDRR DRDDRR
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0],
                [1, 0]]
Output: -1
Explanation: No path exists and destination cell is blocked.
Expected Time Complexity: O(3n^2)
Expected Auxiliary Space: O(l * x)
Here l = length of the path, x = number of paths.

Constraints:
2 ≤ n ≤ 5
0 ≤ mat[i][j] ≤ 1


class Solution {
  public:
   void help(vector<vector<int>> &mat,int n,int i,int j,vector<string> &ans,string str){
       if(i<0 || j<0 || i==n || j==n || mat[i][j]==0 ){
           return;
       }
       if(i==n-1 and j==n-1){
           ans.push_back(str);
       }
       mat[i][j]=0;
       help(mat,n,i-1,j,ans,str+'U');
       help(mat,n,i+1,j,ans,str+'D');
       help(mat,n,i,j+1,ans,str+'R');
       help(mat,n,i,j-1,ans,str+'L');
       mat[i][j]=1;
       
   }
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        help(mat,mat.size(),0,0,ans,"");
        return ans;
    }
};

