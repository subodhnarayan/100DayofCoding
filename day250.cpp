-- -- -- -- -- -- -- -- -GFG - POTD - 03 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Count all triplets with given sum in sorted array
Difficulty: MediumAccuracy: 48.57%Submissions: 31K+Points: 4
Given a sorted array arr[] and a target value, the task is to count triplets (i, j, k) of valid indices, such that arr[i] + arr[j] + arr[k] = target and i < j < k.

Examples:

Input: arr[] = [-3, -1, -1, 0, 1, 2], target = -2
Output: 4
Explanation: Two triplets that add up to -2 are:
arr[0] + arr[3] + arr[4] = (-3) + 0 + (1) = -2
arr[0] + arr[1] + arr[5] = (-3) + (-1) + (2) = -2
arr[0] + arr[2] + arr[5] = (-3) + (-1) + (2) = -2
arr[1] + arr[2] + arr[3] = (-1) + (-1) + (0) = -2
Input: arr[] = [-2, 0, 1, 1, 5], target = 1
Output: 0
Explanation: There is no triplet whose sum is equal to 1. 
Constraints:
3 ≤ arr.size() ≤ 104
-105 ≤ arr[i], target ≤ 105

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            int p1 = i + 1;
            int p2 = n - 1;

            while (p1 < p2) {
                int sum = arr[i] + arr[p1] + arr[p2];

                if (sum == target) {
                    count++;
                    int tp1 = p1 + 1;
                    int tp2 = p2 - 1;

                    // Count duplicates for arr[p1]
                    while (tp1 < p2 && arr[tp1] == arr[p1]) { 
                        count++; 
                        tp1++; 
                    }

                    // Count duplicates for arr[p2]
                    while (tp2 > p1 && arr[tp2] == arr[p2]) { 
                        count++; 
                        tp2--; 
                    }

                    p1++;
                    p2--;
                } else if (sum < target) {
                    p1++;
                } else {
                    p2--;
                }
            }
        }

        return count;
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 03 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
1930. Unique Length-3 Palindromic Subsequences
Solved
Medium
Topics
Companies
Hint
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
 

Example 1:

Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
Example 2:

Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
Example 3:

Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")
 

Constraints:

3 <= s.length <= 105
s consists of only lowercase English letters.


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;
        for (char c : s) {
            letters.insert(c);
        }
        
        int ans = 0;
        for (char letter : letters) {
            int i = -1;
            int j = 0;
            
            for (int k = 0; k < s.size(); k++) {
                if (s[k] == letter) {
                    if (i == -1) {
                        i = k;
                    }
                    
                    j = k;
                }
            }
            
            unordered_set<char> between;
            for (int k = i + 1; k < j; k++) {
                between.insert(s[k]);
            }
            
            ans += between.size();
        }
        
        return ans;
    }
};



  
