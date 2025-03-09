-- -- -- -- -- -- -- -- -GFG - POTD - 09 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
Palindrome SubStrings
Difficulty: MediumAccuracy: 45.8%Submissions: 40K+Points: 4Average Time: 30m
Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2. 

Examples

Input: s = "abaab"
Output: 3
Explanation: All palindromic substrings are : "aba" , "aa" , "baab".
Input: s = "aaa"
Output: 3
Explanation: All palindromic substrings are : "aa", "aa", "aaa".
Input: s = "abbaeae"
Output: 4
Explanation: All palindromic substrings are : "bb" , "abba" , "aea", "eae".
Constraints:
2 ≤ s.size() ≤ 103
string contains only lowercase english characters

Expected Complexities
Time Complexity: O(n^2)Auxiliary Space: O(n^2)


class Solution {
  public:
    int check(int left, int right, string &s){
        int count = 0;
        while(left>=0 && right <s.size()){
            if(s[left] == s[right]){
                count++;
                left--;
                right++;
            }
            else{
                break;
            }
        }
        
        return count;
    }
    int countPS(string &s) {
        // code here
        int oddCount =0, evenCount = 0;
        int n = s.size();
        //Odd palindrome count
        for(int i=0; i<n; i++){
            oddCount += check(i-1, i+1, s);
        }
        
        //Even palindrome count
        for(int i=0; i<n; i++){
            evenCount += check(i-1, i, s);
        }
        
        return oddCount + evenCount;
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 09 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
3208. Alternating Groups II
Solved
Medium
Topics
Companies
Hint
There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

 

Example 1:

Input: colors = [0,1,0,1,0], k = 3

Output: 3

Explanation:



Alternating groups:



Example 2:

Input: colors = [0,1,0,0,1,0,1], k = 6

Output: 2

Explanation:



Alternating groups:



Example 3:

Input: colors = [1,1,0,1], k = 4

Output: 0

Explanation:



 

Constraints:

3 <= colors.length <= 105
0 <= colors[i] <= 1
3 <= k <= colors.length


class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int res = 0;
        int left = 0;
        int n = colors.size();
        for(int right = 1; right<(n + k -1); right++){
            if(colors[(right-1)%n] == colors[right%n]){
                left = right;
            }
            if(right - left + 1 == k ){
                res++;
                left++;
            }
        }
        return res;
    }
};
