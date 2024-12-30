-- -- -- -- -- -- -- -- -GFG - POTD - 30 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Union of Arrays with Duplicates
Difficulty: EasyAccuracy: 42.22%Submissions: 400K+Points: 2
Given two arrays a[] and b[], the task is to find the number of elements in the union between these two arrays.

The Union of the two arrays can be defined as the set containing distinct elements from both arrays. If there are repetitions, then only one element occurrence should be there in the union.

Note: Elements of a[] and b[] are not necessarily distinct.

Examples

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3]
Output: 5
Explanation: Union set of both the arrays will be 1, 2, 3, 4 and 5. So count is 5.
Input: a[] = [85, 25, 1, 32, 54, 6], b[] = [85, 2] 
Output: 7
Explanation: Union set of both the arrays will be 85, 25, 1, 32, 54, 6, and 2. So count is 7.
Input: a[] = [1, 2, 1, 1, 2], b[] = [2, 2, 1, 2, 1] 
Output: 2
Explanation: We need to consider only distinct. So count of elements in union set will be 2.
Constraints:
1 ≤ a.size(), b.size() ≤ 106
0 ≤ a[i], b[i] ≤ 105



class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        set<int> st;
        for(int i=0;i<a.size();i++){
            st.insert(a[i]);
        }
        for(int i=0;i<b.size();i++){
            st.insert(b[i]);
        }
        return st.size();
    }
    
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 30 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


2466. Count Ways To Build Good Strings
Solved
Medium
Topics
Companies
Hint
Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

 

Example 1:

Input: low = 3, high = 3, zero = 1, one = 1
Output: 8
Explanation: 
One possible valid good string is "011". 
It can be constructed as follows: "" -> "0" -> "01" -> "011". 
All binary strings from "000" to "111" are good strings in this example.
Example 2:

Input: low = 2, high = 3, zero = 1, one = 2
Output: 5
Explanation: The good strings are "00", "11", "000", "110", and "011".
 

Constraints:

1 <= low <= high <= 105
1 <= zero, one <= low