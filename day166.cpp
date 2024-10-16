-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 16 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


Two Swaps
Difficulty: EasyAccuracy: 49.85%Submissions: 34K+Points: 2
Given a permutation of some of the first natural numbers in an array arr[], determine if the array can be sorted in exactly two swaps. A swap can involve the same pair of indices twice.

Return true if it is possible to sort the array with exactly two swaps, otherwise return false.

Examples:

Input: arr = [4, 3, 2, 1]
Output: true
Explanation: First, swap arr[0] and arr[3]. The array becomes [1, 3, 2, 4]. Then, swap arr[1] and arr[2]. The array becomes [1, 2, 3, 4], which is sorted.
Input: arr = [4, 3, 1, 2]
Output: false
Explanation: It is not possible to sort the array with exactly two swaps.
Constraints:
1 ≤ arr.size() ≤ 106
1 ≤ arr[i] ≤ arr.size()


class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
              bool ascending=1;

        bool descending =1;

        for(int i=1;i<arr.size()-1;i++){

            if(arr[i]>arr[i+1]){

                ascending=0;

            }

            if(arr[i]<arr[i+1]){

                descending=0;

            }

        }

        return ascending||descending;
    }
};



-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 17 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

1405. Longest Happy String
Solved
Medium
Topics
Companies
Hint
A string s is called happy if it satisfies the following conditions:

s only contains the letters 'a', 'b', and 'c'.
s does not contain any of "aaa", "bbb", or "ccc" as a substring.
s contains at most a occurrences of the letter 'a'.
s contains at most b occurrences of the letter 'b'.
s contains at most c occurrences of the letter 'c'.
Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: a = 1, b = 1, c = 7
Output: "ccaccbcc"
Explanation: "ccbccacc" would also be a correct answer.
Example 2:

Input: a = 7, b = 1, c = 0
Output: "aabaa"
Explanation: It is the only correct answer in this case.
 

Constraints:

0 <= a, b, c <= 100
a + b + c > 0



class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
          int currA = 0, currB = 0, currC = 0;
        int maxLen = a + b + c, i = 0;
        std::string result; // Using std::string instead of StringBuilder
        
        while (i < maxLen) {
            if ((currA != 2 && a >= b && a >= c) || (a > 0 && (currB == 2 || currC == 2))) {
                result += 'a';
                currA++;
                currB = 0;
                currC = 0;
                a--;
            } 
            else if ((currB != 2 && b >= a && b >= c) || (b > 0 && (currA == 2 || currC == 2))) {
                result += 'b';
                currB++;
                currA = 0;
                currC = 0;
                b--;
            } 
            else if ((currC != 2 && c >= a && c >= b) || (c > 0 && (currA == 2 || currB == 2))) {
                result += 'c';
                currC++;
                currA = 0;
                currB = 0;
                c--;
            }
            i++;
        }
        
        return result;
    }
};