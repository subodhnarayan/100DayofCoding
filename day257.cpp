-- -- -- -- -- -- -- -- -GFG - POTD - 10 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Count distinct elements in every window
Difficulty: EasyAccuracy: 41.83%Submissions: 137K+Points: 2
Given an integer array arr[] and a number k. Find the count of distinct elements in every window of size k in the array.

Examples:

Input: arr[] = [1, 2, 1, 3, 4, 2, 3], k = 4
Output:  [3, 4, 4, 3]
Explanation: Window 1 of size k = 4 is 1 2 1 3. Number of distinct elements in this window are 3. 
Window 2 of size k = 4 is 2 1 3 4. Number of distinct elements in this window are 4.
Window 3 of size k = 4 is 1 3 4 2. Number of distinct elements in this window are 4.
Window 4 of size k = 4 is 3 4 2 3. Number of distinct elements in this window are 3.
Input: arr[] = [4, 1, 1], k = 2
Output: [2, 1]
Explanation: Window 1 of size k = 2 is 4 1. Number of distinct elements in this window are 2. 
Window 2 of size k = 2 is 1 1. Number of distinct elements in this window is 1. 
Input: arr[] = [1, 1, 1, 1, 1], k = 3
Output: [1, 1, 1]
Constraints:
1 <= k <= arr.size() <= 105
1 <= arr[i] <= 105


class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
         vector<int> res;
        unordered_map<int, int> freqMap; // To store frequency of elements in the current window
        int n = arr.size();

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            freqMap[arr[i]]++;
        }
    
        // Store the count of distinct elements for the first window
        res.push_back(freqMap.size());

        // Slide the window from start to end
        for (int i = k; i < n; i++) {
            // Add new element to the window
            freqMap[arr[i]]++;

            // Remove the element going out of the window
            if (--freqMap[arr[i - k]] == 0) {
                freqMap.erase(arr[i - k]);
            }

            // Store the count of distinct elements for the current window
            res.push_back(freqMap.size());
        }

        return res;
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 10 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
916. Word Subsets
Solved
Medium
Topics
Companies
You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

 

Example 1:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]
Example 2:

Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]
 

Constraints:

1 <= words1.length, words2.length <= 104
1 <= words1[i].length, words2[i].length <= 10
words1[i] and words2[i] consist only of lowercase English letters.
All the strings of words1 are unique.


class Solution {
public:
    vector<string> wordSubsets(vector<string>& mainWords, vector<string>& requiredWords) {
        int maxCharFreq[26] = {0};
        int tempCharFreq[26];
        
        for (const auto& word : requiredWords) {
            memset(tempCharFreq, 0, sizeof tempCharFreq);//To Set Temp freq all to zero 
//You can do vector<int> tempCharFreq(26,0);
            for (char ch : word) {
                tempCharFreq[ch - 'a']++;
            }
            for (int i = 0; i < 26; ++i) {
                maxCharFreq[i] = max(maxCharFreq[i], tempCharFreq[i]);
            }
        }
        
        vector<string> universalWords;
        
        for (const auto& word : mainWords) {
            memset(tempCharFreq, 0, sizeof tempCharFreq);
            for (char ch : word) {
                tempCharFreq[ch - 'a']++;
            }
            bool isUniversal = true;
            for (int i = 0; i < 26; ++i) {
                if (maxCharFreq[i] > tempCharFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }
            if (isUniversal) {
                universalWords.emplace_back(word);
            }
        }
        
        return universalWords;
    }
};
