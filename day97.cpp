-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 7 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

K-th element of two Arrays
Difficulty: MediumAccuracy: 37.4%Submissions: 255K+Points: 4
Given two sorted arrays arr1 and arr2 and an element k. The task is to find the element that would be at the kth position of the combined sorted array.

Examples :

Input: k = 5, arr1[] = [2, 3, 6, 7, 9], arr2[] = [1, 4, 8, 10]
Output: 6
Explanation: The final combined sorted array would be - 1, 2, 3, 4, 6, 7, 8, 9, 10. The 5th element of this array is 6.
Input: k = 7, arr1[] = [100, 112, 256, 349, 770], arr2[] = [72, 86, 113, 119, 265, 445, 892]
Output: 256
Explanation: Combined sorted array is - 72, 86, 100, 112, 113, 119, 256, 265, 349, 445, 770, 892. 7th element of this array is 256.
Expected Time Complexity: O(log(n) + log(m))
Expected Auxiliary Space: O(log (n))

Constraints:
1 <= k<= arr1.size()+arr2.size()
1 <= arr1.size(), arr2.size() <= 106
0 <= arr1[i], arr2[i] < 108

class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
         int i1=0;
        int i2=0;
        while(i1<arr1.size() && i2<arr2.size()){
            long smaller=arr1[i1]<=arr2[i2]?arr1[i1++]:arr2[i2++];
            k--;
            if(k==0){
                return smaller;
            }
        }
        while (i1 < arr1.size()) {
            long smaller = arr1[i1++];
            k--;
            if (k == 0) {
                return smaller;
            }
        }
        while (i2 < arr2.size()) {
            long smaller = arr2[i2++];
            k--;
            if (k == 0) {
                return smaller;
            }
        }
        return -1;
    }
};




-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 7 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

273. Integer to English Words
Solved
Hard
Topics
Companies
Hint
Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

Constraints:

0 <= num <= 231 - 1