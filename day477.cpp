-- -- -- -- -- -- -- -- -GFG - POTD - 18 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Implement Trie
Difficulty: MediumAccuracy: 65.68%Submissions: 72K+Points: 4Average Time: 30m
Implement Trie class and complete insert(), search() and isPrefix() function for the following queries :

Type 1 : (1, word), calls insert(word) function and insert word in the Trie
Type 2 : (2, word), calls search(word) function and check whether word exists in Trie or not.
Type 3 : (3, word), calls isPrefix(word) function and check whether word exists as a prefix of any string in Trie or not.
Examples :

Input: query[][] = [[1, "abcd"], [1, "abc"], [1, "bcd"], [2, "bc"], [3, "bc"], [2, "abc"]]
Output: [false, true, true]
Explanation: string "bc" does not exist in the trie, "bc" exists as prefix of the word "bcd" in the trie, and "abc" also exists in the trie.
Input: query[][] = [[1, "gfg"], [1, "geeks"], [3, "fg"], [3, "geek"], [2, "for"]]
Output: [false, true, false]
Explanation: The string "for" is not present in the trie, "fg" is not a valid prefix, while "geek" is a valid prefix of the word "geeks" in the trie.
Constraints:
1 ≤ query.size() ≤ 104
1 ≤ word.size() ≤ 103

class Node{
    public:
    Node* children[26];
    bool flag; // end of word flag
    
    Node(){
        flag = false;
        for(int i=0;i<26; i++){
            children[i] = nullptr;
        }
    }
};
class Trie {
    Node* root;
  public:

    Trie() {
        // implement Trie
         root = new Node();
    }

    void insert(string &word) {
        // insert word into Trie
         Node* node = root;
        for(char c: word){
            int index = c - 'a';
            if(node->children[index] == nullptr){
                node->children[index] = new Node();
            }
            node = node->children[index];
        }
        node->flag = true;
    }

    bool search(string &word) {
        // search word in the Trie
        Node* curr = root;
        for(char ch:word){
            int index = ch-'a';
            if(curr->children[index] == nullptr){
                return false;
            }        
            curr = curr->children[index];
        }
        
        return curr->flag;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
         Node* curr = root;
        for(char ch:word){
            int index = ch-'a';
            if(curr->children[index] == nullptr){
                return false;
            }        
            curr = curr->children[index];
        }
        
        return true;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 18 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

38. Count and Say
Solved
Medium
Topics
Companies
Hint
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15" and replace "1" with "11". Thus the compressed string becomes "23321511".

Given a positive integer n, return the nth element of the count-and-say sequence.

 

Example 1:

Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
Example 2:

Input: n = 1

Output: "1"

Explanation:

This is the base case.

 

Constraints:

1 <= n <= 30
 

Follow up: Could you solve it iteratively?
