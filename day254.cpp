-- -- -- -- -- -- -- -- -GFG - POTD - 07 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Pair with given sum in a sorted array
Difficulty: EasyAccuracy: 26.04%Submissions: 83K+Points: 2
You are given an integer target and an array arr[]. You have to find number of pairs in arr[] which sums up to target. It is given that the elements of the arr[] are in sorted order.
Note: pairs should have elements of distinct indexes. 

Examples :

Input: arr[] = [-1, 1, 5, 5, 7], target = 6
Output: 3
Explanation: There are 3 pairs which sum up to 6 : {1, 5}, {1, 5} and {-1, 7}.
Input: arr[] = [1, 1, 1, 1], target = 2
Output: 6
Explanation: There are 6 pairs which sum up to 2 : {1, 1}, {1, 1}, {1, 1}, {1, 1}, {1, 1} and {1, 1}.
Input: arr[] = [-1, 10, 10, 12, 15], target = 125
Output: 0
Explanation: There is no such pair which sums up to 4.
Constraints:
-105 <= target <=105
 2 <= arr.size() <= 105
-105 <= arr[i] <= 105

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n = arr.size();
        int st = 0, en = n-1;
        int count = 0;
        
        while(st < en){
            int sum = arr[st] + arr[en];
            
            if(sum > target){
                en--;
            }
            else if(sum < target){
                st++;
            }
            else{
                
                int elem1 = arr[st];
                int c1 = 0;
                while(st <= en && arr[st] == elem1){
                    st++;
                    c1++;
                }
                
                int elem2 = arr[en];
                int c2 = 0;
                while(st <= en && arr[en] == elem2){
                    en--;
                    c2++;
                }
                
                if(elem1 == elem2){
                    count += c1*(c1-1)/2;
                }
                else{
                    count+=c1*c2;
                }
            }
        
        }
        return count;
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 07 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
1408. String Matching in an Array
Solved
Easy
Topics
Companies
Hint
Given an array of string words, return all strings in words that is a substring of another word. You can return the answer in any order.

A substring is a contiguous sequence of characters within a string

 

Example 1:

Input: words = ["mass","as","hero","superhero"]
Output: ["as","hero"]
Explanation: "as" is substring of "mass" and "hero" is substring of "superhero".
["hero","as"] is also a valid answer.
Example 2:

Input: words = ["leetcode","et","code"]
Output: ["et","code"]
Explanation: "et", "code" are substring of "leetcode".
Example 3:

Input: words = ["blue","green","bu"]
Output: []
Explanation: No string of words is substring of another string.
 

Constraints:

1 <= words.length <= 100
1 <= words[i].length <= 30
words[i] contains only lowercase English letters.
All the strings of words are unique.

class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> matchingWords;

        // Iterate through each word in the input list.
        for (int currentWordIndex = 0; currentWordIndex < words.size();
             currentWordIndex++) {
            // Compare the current word with all other words.
            for (int otherWordIndex = 0; otherWordIndex < words.size();
                 otherWordIndex++) {
                if (currentWordIndex == otherWordIndex)
                    continue;  // Skip comparing the word with itself.

                // Check if the current word is a substring of another word.
                if (isSubstringOf(words[currentWordIndex],
                                  words[otherWordIndex])) {
                    // Add it to the result list if true.
                    matchingWords.push_back(words[currentWordIndex]);
                    break;  // No need to check further for this word.
                }
            }
        }

        return matchingWords;
    }

private:
    // Helper function to check if `sub` is a substring of `main`.
    bool isSubstringOf(string &sub, string &main) {
        // Loop through possible starting indices in `main`.
        for (int startIndex = 0; startIndex < main.size(); startIndex++) {
            bool subFits = true;

            // Check if the substring matches from the current start index.
            for (int subIndex = 0; subIndex < sub.size(); subIndex++) {
                if (startIndex + subIndex >= main.size() ||
                    main[startIndex + subIndex] != sub[subIndex]) {
                    subFits = false;  // The substring doesn't match.
                    break;  // No need to continue further for this start index.
                }
            }

            if (subFits) {
                return true;  // Found a match, return true.
            }
        }

        return false;  // No match found.
    }
};
