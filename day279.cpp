-- -- -- -- -- -- -- -- -GFG - POTD - 01 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Word Search
Difficulty: MediumAccuracy: 32.69%Submissions: 66K+Points: 4
You are given a two-dimensional mat[][] of size n*m containing English alphabets and a string word. Check if the word exists on the mat. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.

Examples :

Input: mat[][] = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
Output: true
Explanation:

The letter cells which are used to construct the "GEEK" are colored.
Input: mat[][] = [['T', 'E', 'U'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
Output: false
Explanation:

It is impossible to construct the string word from the mat using each cell only once.
Input: mat[][] = [['A', 'B', 'A'], ['B', 'A', 'B']], word = "AB"
Output: true
Explanation:

There are multiple ways to construct the word "AB".
Constraints:
1 ≤ n, m ≤ 6
1 ≤ L ≤ 15
mat and word consists of only lowercase and uppercase English letters.

Time Complexity: O(n * m * 3^L)Auxiliary Space: O(n * m)

class Solution {
  public:
    bool solve(vector<vector<char>> &mat,int i,int j,int n,int m,int index,string &word){
        if(mat[i][j]!=word[index]) return false;
        
        if(index==word.length()-1) return true;
        
        char ch=mat[i][j];
        mat[i][j]='$';
         
        bool found=false;
        if(i>0 and !found){
            found=solve(mat,i-1,j,n,m,index+1,word);//Top
        }
        if(i<n-1 and !found){
            found=solve(mat,i+1,j,n,m,index+1,word);//Down
        }
        if(j>0 and !found) {
            found=solve(mat,i,j-1,n,m,index+1,word);//Left
        }
        if(j<m-1 and !found){
            found=solve(mat,i,j+1,n,m,index+1,word);//Right
        }
        mat[i][j]=ch;
        return found;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==word[0]){
                    if( solve(mat,i,j,mat.size(),mat[i].size(),0,word)){
                        return true;
                    }
                }
            }
        }   
        return false;
    }
};


-- -- -- -- -- -- -- -- -LeetCode - POTD - 01 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

3151. Special Array I
Solved
Easy
Topics
Companies
Hint
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

 

Example 1:

Input: nums = [1]

Output: true

Explanation:

There is only one element. So the answer is true.

Example 2:

Input: nums = [2,1,4]

Output: true

Explanation:

There is only two pairs: (2,1) and (1,4), and both of them contain numbers with different parity. So the answer is true.

Example 3:

Input: nums = [4,3,1,6]

Output: false

Explanation:

nums[1] and nums[2] are both odd. So the answer is false.

 

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100


class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
          // Iterate through indexes 0 to n - 1
        for (int index = 0; index < nums.size() - 1; index++) {
            // Compare the parities of the current and next number
            if ((nums[index] & 1) ^ (nums[index + 1] & 1) == 0) {
                // If the two adjacent numbers have the same parity, return
                // false
                return false;
            }
        }

        // Return true if no pair of adjacent numbers with the same parity are
        // found
        return true;
    }
};