-- -- -- -- -- -- -- -- -GFG - POTD - 14 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Nearly sorted
Difficulty: MediumAccuracy: 75.25%Submissions: 60K+Points: 4
Given an array arr[], where each element is at most k away from its target position, you need to sort the array optimally.
Note: You need to change the given array arr[] in place.

Examples:

Input: arr[] = [6, 5, 3, 2, 8, 10, 9], k = 3
Output: [2, 3, 5, 6, 8, 9, 10]
Explanation: The sorted array will be 2 3 5 6 8 9 10
Input: arr[]= [1, 4, 5, 2, 3, 6, 7, 8, 9, 10], k = 2
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Explanation: The sorted array will be 1 2 3 4 5 6 7 8 9 10
DO NOT use the direct library sort() function for this question.

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ k < arr.size()
1 ≤ arri ≤ 106



class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code
         priority_queue<int, vector<int>,
        greater<int>> minH;
        int j = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(minH.size() == k) {
                minH.push(arr[i]);
                arr[j++] = minH.top();
                minH.pop();
            }
            else minH.push(arr[i]);
        }
        while(minH.size() > 0) {
            arr[j++] = minH.top();
            minH.pop();
        }
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 14 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
