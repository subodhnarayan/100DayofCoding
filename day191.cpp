-- -- -- -- -- -- -- -- -GFG - POTD - 10 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Union of Two Sorted Arrays with Distinct Elements
Difficulty: EasyAccuracy: 55.4%Submissions: 22K+Points: 2
Given two sorted arrays a[] and b[], where each array contains distinct elements , the task is to return the elements in the union of the two arrays in sorted order.

Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.
Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 3, 4, 5], b[] = [1, 2, 3, 4]
Output: 1 2 3 4 5
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1], b[] = [2]
Output: 1 2
Explanation: Distinct elements including both the arrays are: 1 2.
Constraints:
1  <=  a.size(), b.size()  <=  105
-109  <=  a[i] , b[i]  <=  109

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        // return vector with correct order of elements
        vector<int> ans;
    int i = 0, j = 0;
    
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            if (ans.empty() || ans.back() != a[i]) {  // Avoid duplicates
                ans.push_back(a[i]);
            }
            i++;
        }
        else if (a[i] > b[j]) {
            if (ans.empty() || ans.back() != b[j]) {  // Avoid duplicates
                ans.push_back(b[j]);
            }
            j++;
        }
        else { // a[i] == b[j]
            if (ans.empty() || ans.back() != a[i]) {  // Avoid duplicates
                ans.push_back(a[i]);
            }
            i++;
            j++;
        }
    }
    
    // Add remaining elements from array a, if any
    while (i < a.size()) {
        if (ans.empty() || ans.back() != a[i]) {
            ans.push_back(a[i]);
        }
        i++;
    }

    // Add remaining elements from array b, if any
    while (j < b.size()) {
        if (ans.empty() || ans.back() != b[j]) {
            ans.push_back(b[j]);
        }
        j++;
    }
    
    return ans;
    }
};