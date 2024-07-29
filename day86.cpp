-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFg - POTD - 29 / 07 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Row with max 1s
Difficulty: MediumAccuracy: 33.09%Submissions: 284K+Points: 4
Given a boolean 2D array, consisting of only 1's and 0's, where each row is sorted. Return the 0-based index of the first row that has the most number of 1s. If no such row exists, return -1.

Examples:

Input: arr[][] = [[0, 1, 1, 1],
               [0, 0, 1, 1],
               [1, 1, 1, 1],
               [0, 0, 0, 0]]
Output: 2
Explanation: Row 2 contains 4 1's (0-based indexing).
Input: arr[][] = [[0, 0], 
               [1, 1]]
Output: 1
Explanation: Row 1 contains 2 1's (0-based indexing).
Expected Time Complexity: O(n+m)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ number of rows, number of columns ≤ 103
0 ≤ arr[i][j] ≤ 1 


class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
        int row=arr.size();
        int col=arr[0].size();
        int index=-1;
        int ans=0;
        for(int i=0;i<row;i++){
             int count=0;
            for(int j=0;j<col;j++){
               if(arr[i][j]==1){
                   count++;
               }
            
            }
            if(count>ans){
                ans=count;
                index=i;
            }
        
        }
        return index;
    }
};
