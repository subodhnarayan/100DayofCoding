//GFG POTD 19/7/2024
Count Smaller elements
// Difficulty: HardAccuracy: 38.16%Submissions: 64K+Points: 8
// Given an array arr containing non-negative integers. Count and return an array ans where ans[i] denotes the number of smaller elements on right side of arr[i].

// Examples:

// Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
// Output: [6, 1, 1, 1, 0, 1, 0]
// Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.
// Input: arr[] = [1, 2, 3, 4, 5]
// Output: [0, 0, 0, 0, 0]
// Explanation: There are 0 smaller elements right after 1. There are 0 smaller elements right after 2. And so on.
// Expected Time Complexity: O(n*logn)
// Expected Auxiliary Space: O(n)

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i]  ≤ 108


class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        vector<int> ans;
        vector<int> temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            int tar=arr[i];
            int start=0;
            int end=temp.size()-1;
            int ind=-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                if(temp[mid]==tar){
                    ind=mid;
                    end=mid-1;
                }
                else if(temp[mid]<tar){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        
            ans.push_back(ind);
            temp.erase(temp.begin() + ind);
        }
        return ans;
        
    }
};

LEETCODE POTD 19/7/2024

1380. Lucky Numbers in a Matrix
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

// Example 1:

// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
// Output: [15]
// Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
// Example 2:

// Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
// Output: [12]
// Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
// Example 3:

// Input: matrix = [[7,8],[1,2]]
// Output: [7]
// Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= n, m <= 50
// 1 <= matrix[i][j] <= 105.
// All elements in the matrix are distinct.



class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int> rowMins(rows, INT_MAX);
        vector<int> colMaxs(cols, INT_MIN);
        for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rowMins[i] = std::min(rowMins[i], matrix[i][j]);
        }
    }
    
    // Compute the maximum element in each column
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            colMaxs[j] = std::max(colMaxs[j], matrix[i][j]);
        }
    }
    
    std::vector<int> luckyNumbers;
    
    // Check if any row minimum is also a column maximum
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == rowMins[i] && matrix[i][j] == colMaxs[j]) {
                luckyNumbers.push_back(matrix[i][j]);
            }
        }
    }
    
    return luckyNumbers;
    }
};