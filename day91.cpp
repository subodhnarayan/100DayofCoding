 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFg - POTD - 1 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

 Spirally traversing a matrix
Difficulty: MediumAccuracy: 35.2%Submissions: 269K+Points: 4
You are given a rectangular matrix, and your task is to return an array while traversing the matrix in spiral form.

Examples:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12],
                  [13, 14, 15,16]]
Output: [1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10]
Explanation:

Input: matrix[][] = [[1, 2, 3, 4],
                  [5, 6, 7, 8],
                  [9, 10, 11, 12]]
Output: [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
Explanation: Applying same technique as shown above, output for the 2nd testcase will be 1 2 3 4 8 12 11 10 9 5 6 7.
Expected Time Complexity: O(n2)
Expected Auxiliary Space: O(n2)

Constraints:
1 <= matrix.size(), matrix[0].size() <= 100
0 <= matrix[i][j]<= 100


class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
         vector<int> ans;
    if (matrix.empty() || matrix[0].empty()) {
        return ans;
    }

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (left <= right && top <= bottom) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; ++i) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // Traverse from top to bottom along the right column
        if (top <= bottom) {
            for (int i = top; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            right--;
        }

        // Traverse from right to left along the bottom row
        if (left <= right && top <= bottom) {
            for (int i = right; i >= left; --i) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse from bottom to top along the left column
        if (left <= right && top <= bottom) {
            for (int i = bottom; i >= top; --i) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
    }
};

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 1 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

2678. Number of Senior Citizens
Solved
Easy
Topics
Companies
Hint
You are given a 0-indexed array of strings details. Each element of details provides information about a given passenger compressed into a string of length 15. The system is such that:

The first ten characters consist of the phone number of passengers.
The next character denotes the gender of the person.
The following two characters are used to indicate the age of the person.
The last two characters determine the seat allotted to that person.
Return the number of passengers who are strictly more than 60 years old.

 

Example 1:

Input: details = ["7868190130M7522","5303914400F9211","9273338290F4010"]
Output: 2
Explanation: The passengers at indices 0, 1, and 2 have ages 75, 92, and 40. Thus, there are 2 people who are over 60 years old.
Example 2:

Input: details = ["1313579440F2036","2921522980M5644"]
Output: 0
Explanation: None of the passengers are older than 60.
 

Constraints:

1 <= details.length <= 100
details[i].length == 15
details[i] consists of digits from '0' to '9'.
details[i][10] is either 'M' or 'F' or 'O'.
The phone numbers and seat numbers of the passengers are distinct.

class Solution {
public:
    int countSeniors(vector<string>& details) {
       int n=details.size();
       int count=0;
       for(int i=0;i<n;i++){
        string str=details[i];
        int age=(str[11]-'0')*10+(str[12]-'0');
        if((age)>60){
            count++;
        }
        
       }
       return count;
    }
};