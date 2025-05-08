-- -- -- -- -- -- -- -- -GFG - POTD - 08 / 05 / 2025 -----------------------------------
Missing element of AP
Difficulty: MediumAccuracy: 34.32%Submissions: 70K+Points: 4
Given a sorted array arr[] that represents an Arithmetic Progression (AP) with exactly one missing element, find the missing number.

Note: An element will always exist that, upon inserting into a sequence forms Arithmetic progression. If the given sequence already forms a valid complete AP, return the (n+1)-th element that would come next in the sequence.

Examples:

Input: arr[] = [2, 4, 8, 10, 12, 14]
Output: 6
Explanation: Actual AP should be 2, 4, 6, 8, 10, 12, 14.
Input: arr[] = [1, 6, 11, 16, 21, 31]
Output: 26
Explanation: Actual AP should be 1, 6, 11, 16, 21, 26, 31.
Input: arr[] = [4, 7, 10, 13, 16]
Output: 19
Explanation: Since the sequence already forms a valid AP, the next element after 16 in the sequence would be 19. Therefore, the output is 19.
Constraints:
2 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 2*107

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)

class Solution {
    public:
      int findMissing(vector<int> &arr) {
          // code here
           int n = arr.size();
          bool neg = arr[0] > arr[1]; // Check if AP is decreasing
          
          // Edge Case: If array has only 2 elements
          if(n == 2) {
              int rem = arr[1] - arr[0];
              return (rem + arr[1]); // Next element in AP
          }
          
          map<int,int> mp; // Store frequency of differences
          
          // Calculate all differences between consecutive elements
          for(int i = 1; i < n; ++i) {
              mp[abs(arr[i] - arr[i-1])]++;
          }
          
          // The correct difference is the smallest (since the wrong difference is larger)
          int diff = mp.begin()->first;
          
          // Traverse the array to find where the difference is not 'diff'
          for(int i = 0; i < n-1; ++i) {
              if((arr[i] + (neg ? -1 : 1)*diff) != arr[i+1]) {
                  return (arr[i] + (neg ? -1 : 1)*diff); // Missing element
              }
          }
          
          // If no missing element found, return the next element after the last one
          return (arr[n-1] + (neg ? -1 : 1)*diff);
      }
  };
-- -- -- -- -- -- -- -- -Leetcode - POTD - 08 / 05 / 2025 -----------------------------------


