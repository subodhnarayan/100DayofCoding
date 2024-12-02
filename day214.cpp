-- -- -- -- -- -- -- -- -GFG - POTD - 02 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -




-- -- -- -- -- -- -- -- -Leetcode - POTD - 02 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

1455. Check If a Word Occurs As a Prefix of Any Word in a Sentence
Solved
Easy
Topics
Companies
Hint
Given a sentence that consists of some words separated by a single space, and a searchWord, check if searchWord is a prefix of any word in sentence.

Return the index of the word in sentence (1-indexed) where searchWord is a prefix of this word. If searchWord is a prefix of more than one word, return the index of the first word (minimum index). If there is no such word return -1.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: sentence = "i love eating burger", searchWord = "burg"
Output: 4
Explanation: "burg" is prefix of "burger" which is the 4th word in the sentence.
Example 2:

Input: sentence = "this problem is an easy problem", searchWord = "pro"
Output: 2
Explanation: "pro" is prefix of "problem" which is the 2nd and the 6th word in the sentence, but we return 2 as it's the minimal index.
Example 3:

Input: sentence = "i am tired", searchWord = "you"
Output: -1
Explanation: "you" is not a prefix of any word in the sentence.
 

Constraints:

1 <= sentence.length <= 100
1 <= searchWord.length <= 10
sentence consists of lowercase English letters and spaces.
searchWord consists of lowercase English letters.

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        istringstream stream(sentence);
        string word;
        int index = 1; // 1-based index
        
        while (stream >> word) {
            // Check if the word starts with the searchWord
            if (word.find(searchWord) == 0) {
                return index;
            }
            index++;
        }
        
        // Return -1 if no word starts with the searchWord
        return -1;
    }
};