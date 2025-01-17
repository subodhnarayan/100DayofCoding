-- -- -- -- -- -- -- -- -GFG - POTD - 09 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Indexes of Subarray Sum
Difficulty: MediumAccuracy: 16.5%Submissions: 1.7MPoints: 4
Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray (a contiguous sequence of elements) whose sum equals a specified value target. You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first subarray whose sum is equal to the target.

Note: If no such array is possible then, return [-1].

Examples:

Input: arr[] = [1, 2, 3, 7, 5], target = 12
Output: [2, 4]
Explanation: The sum of elements from 2nd to 4th position is 12.
Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], target = 15
Output: [1, 5]
Explanation: The sum of elements from 1st to 5th position is 15.
Input: arr[] = [5, 3, 4], target = 2
Output: [-1]
Explanation: There is no subarray with sum 2.
Constraints:
1 <= arr.size()<= 106
0 <= arr[i] <= 103
0 <= target <= 109


class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        
        int n = arr.size();
        int st = 0, en = 1, sum = 0;
        vector<int> res;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            
            if(sum > target){
                en = i;
                
                while(st < en && sum > target){
                    sum -= arr[st];
                    st++;
                }
            }
            
            if(sum == target){
                en = i;
                res.push_back(st+1);
                res.push_back(en+1);
                return res;
            }
        }
        
        res.push_back(-1);
        return res;
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 09 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
2185. Counting Words With a Given Prefix
Solved
Easy
Topics
Companies
Hint
You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".
Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length, pref.length <= 100
words[i] and pref consist of lowercase English letters.

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        
        for(string& word: words){
            if(word.find(pref) == 0){
                count++;
            }
        }

        return count;
    }
};
