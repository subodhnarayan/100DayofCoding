-- -- -- -- -- -- -- -- -GFG - POTD - 05 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Sort 0s, 1s and 2s
Difficulty: EasyAccuracy: 50.58%Submissions: 725K+Points: 2
Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.

Examples:

Input: arr[] = [0, 1, 2, 0, 1, 2]
Output: [0, 0, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.
Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
Explanation: 0s 1s and 2s are segregated into ascending order.
Constraints:
1 <= arr.size() <= 106
0 <= arr[i] <= 2


class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int countZero = 0;
        int countOne = 0;
        int countTwo = 0;
        
        for(int i=0; i<arr.size(); i++) {
            
            if(arr[i] == 0) countZero++;
            else if(arr[i] == 1) countOne++;
            else countTwo++;
        }
        
        for(int i=0; i<arr.size(); i++) {
            if(countZero != 0) {
                arr[i] = 0;
                countZero--;
            }
            else if(countOne != 0) {
                arr[i] = 1;
                countOne--;
            }
            else {
                arr[i]=2;
                countTwo--;
            }
        }
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 05 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


