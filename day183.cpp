-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 2 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Kth distance
Difficulty: EasyAccuracy: 48.69%Submissions: 27K+Points: 2
Given an unsorted array arr and a number k which is smaller than the size of the array. Return true if the array contains any duplicate within k distance throughout the array else false.

Examples:

Input: arr[] = [1, 2, 3, 4, 1, 2, 3, 4] and k = 3
Output: false
Explanation: All duplicates are more than k distance away.
Input: arr[] = [1, 2, 3, 1, 4, 5] and k = 3
Output: true
Explanation: 1 is repeated at distance 3.
Input: arr[] = [6, 8, 4, 1, 8, 5, 7] and k = 3
Output: true
Explanation: 8 is repeated at distance 3.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ k < arr.size()
1 ≤ arr[i] ≤ 105


class Solution {
  public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        // Handle the case where the array has only one element
        if (arr.size() == 1) {
            return arr[0] == k;
        }

        // Iterate through each element in the array
        for (size_t i = 0; i < arr.size(); ++i) {
            std::unordered_set<int> set;

            // Check the next k elements
            for (size_t j = i; j <= i + k && j < arr.size(); ++j) {
                if (set.find(arr[j]) != set.end()) {
                    return true; // Duplicate found within k distance
                }
                set.insert(arr[j]);
            }
        }

        return false; // No duplicates found within k distance
    }
};

-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -LeetCode - POTD - 2 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
2490. Circular Sentence
Solved
Easy
Topics
Companies
Hint
A sentence is a list of words that are separated by a single space with no leading or trailing spaces.

For example, "Hello World", "HELLO", "hello world hello world" are all sentences.
Words consist of only uppercase and lowercase English letters. Uppercase and lowercase English letters are considered different.

A sentence is circular if:

The last character of a word is equal to the first character of the next word.
The last character of the last word is equal to the first character of the first word.
For example, "leetcode exercises sound delightful", "eetcode", "leetcode eats soul" are all circular sentences. However, "Leetcode is cool", "happy Leetcode", "Leetcode" and "I like Leetcode" are not circular sentences.

Given a string sentence, return true if it is circular. Otherwise, return false.

 

Example 1:

Input: sentence = "leetcode exercises sound delightful"
Output: true
Explanation: The words in sentence are ["leetcode", "exercises", "sound", "delightful"].
- leetcode's last character is equal to exercises's first character.
- exercises's last character is equal to sound's first character.
- sound's last character is equal to delightful's first character.
- delightful's last character is equal to leetcode's first character.
The sentence is circular.

Example 2:

Input: sentence = "eetcode"
Output: true
Explanation: The words in sentence are ["eetcode"].
- eetcode's last character is equal to eetcode's first character.
The sentence is circular.
Example 3:

Input: sentence = "Leetcode is cool"
Output: false
Explanation: The words in sentence are ["Leetcode", "is", "cool"].
- Leetcode's last character is not equal to is's first character.
The sentence is not circular.
 

Constraints:
1 <= sentence.length <= 500
sentence consist of only lowercase and uppercase English letters and spaces.
The words in sentence are separated by a single space.
There are no leading or trailing spaces.'

class Solution {
public:
    bool isCircularSentence(string sentence) {
        // Get the length of the sentence
        int n = sentence.size();

        // First check: Compare first and last character of sentence
        // For a circular sentence, they must match
        if(sentence[0] != sentence[n-1]) return false;

        // Iterate through the sentence, starting from index 1 to n-2
        // We don't need to check first and last characters again
        for(int i=1; i<n-1; i++){
            // When we find a space character
            if(sentence[i] == ' '){
                // Check if the character before space (last char of current word)
                // matches the character after space (first char of next word)
                if(sentence[i-1] != sentence[i+1]) return false;
            }
        }

        // If we made it through all checks, the sentence is circular
        return true;
    }
};