-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 20 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Facing the sun
Difficulty: EasyAccuracy: 45.54%Submissions: 72K+Points: 2
Given an array height representing the heights of buildings. You have to count the buildings that will see the sunrise (Assume the sun rises on the side of the array starting point).
Note: The height of the building should be strictly greater than the height of the buildings left in order to see the sun.


Examples :

Input: height = [7, 4, 8, 2, 9]
Output: 3
Explanation: As 7 is the first element, it can see the sunrise. 4 can't see the sunrise as 7 is hiding it. 8 can see. 2 can't see the sunrise. 9 also can see
the sunrise.
Input: height = [2, 3, 4, 5]
Output: 4
Explanation: As 2 is the first element, it can see the sunrise.  3 can see the sunrise as 2 is not hiding it. Same for 4 and 5, they also can see the sunrise.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ height.size() ≤ 106
1 ≤ heighti ≤ 108


class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
       int ans=1;
       int max=height[0];
       for(int i=1;i<height.size();i++){
           
           if(height[i]>height[i-1] && height[i]>max){
               max=height[i];
               ans++;
           }
       }
       return ans;
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 19 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

214. Shortest Palindrome
Solved
Hard
Topics
Companies
You are given a string s. You can convert s to a 
palindrome
 by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.

 

Example 1:

Input: s = "aacecaaa"
Output: "aaacecaaa"
Example 2:

Input: s = "abcd"
Output: "dcbabcd"
 

Constraints:

0 <= s.length <= 5 * 104
s consists of lowercase English letters only.


class Solution {
public:
      int kmp(const string &txt, const string &patt) {
       string newString = patt + '#' + txt;
        vector<int> pi(newString.length(), 0);
        int i = 1, k = 0;
        while (i < newString.length()) {
            if (newString[i] == newString[k]) {
                k++;
                pi[i] = k;
                i++;
            } else {
                if (k > 0) {
                    k = pi[k - 1];
                } else {
                    pi[i] = 0;
                    i++;
                }
            }
        }
        return pi.back();
    }
    string shortestPalindrome(string s) {
          int count = kmp(string(s.rbegin(), s.rend()), s);
        return string(s.rbegin(), s.rend()).substr(0, s.length() - count) + s;
    }
};