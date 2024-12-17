-- -- -- -- -- -- -- -- -GFG - POTD - 17 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Aggressive Cows
Difficulty: MediumAccuracy: 59.57%Submissions: 91K+Points: 4
You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
Constraints:
2 <= stalls.size() <= 106
0 <= stalls[i] <= 108
1 <= k <= stalls.size()


class Solution {
  public:
  
  bool isP(int diff, int n, int k, vector<int> &arr){
        int cnt=1;
        int prev=arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]-prev>=diff){
                cnt++;
                if(cnt==k) return 1;
                prev=arr[i];
            }else{
                continue;
            }
        }
        return 0;
    }
  
 
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int lo=0;
        int hi=stalls[n-1]-stalls[0];
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isP(mid, n, k, stalls)){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return lo-1;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
     return solve(stalls.size(), k, stalls);
    }
};





-- -- -- -- -- -- -- -- -Leetcode - POTD - 17 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


2182. Construct String With Repeat Limit
Solved
Medium
Topics
Companies
Hint
You are given a string s and an integer repeatLimit. Construct a new string repeatLimitedString using the characters of s such that no letter appears more than repeatLimit times in a row. You do not have to use all characters from s.

Return the lexicographically largest repeatLimitedString possible.

A string a is lexicographically larger than a string b if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b. If the first min(a.length, b.length) characters do not differ, then the longer string is the lexicographically larger one.

 

Example 1:

Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
Explanation: We use all of the characters from s to construct the repeatLimitedString "zzcccac".
The letter 'a' appears at most 1 time in a row.
The letter 'c' appears at most 3 times in a row.
The letter 'z' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "zzcccac".
Note that the string "zzcccca" is lexicographically larger but the letter 'c' appears more than 3 times in a row, so it is not a valid repeatLimitedString.
Example 2:

Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
Explanation: We use only some of the characters from s to construct the repeatLimitedString "bbabaa". 
The letter 'a' appears at most 2 times in a row.
The letter 'b' appears at most 2 times in a row.
Hence, no letter appears more than repeatLimit times in a row and the string is a valid repeatLimitedString.
The string is the lexicographically largest repeatLimitedString possible so we return "bbabaa".
Note that the string "bbabaaa" is lexicographically larger but the letter 'a' appears more than 2 times in a row, so it is not a valid repeatLimitedString.
 

Constraints:

1 <= repeatLimit <= s.length <= 105
s consists of lowercase English letters.


class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        sort(s.rbegin(), s.rend());

        string result;
        int freq = 1;
        int pointer = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (!result.empty() && result.back() == s[i]) {
                if (freq < repeatLimit) {
                    result += s[i];
                    freq++;
                } else {
                    pointer = max(pointer, i + 1);
                    while (pointer < s.size() && s[pointer] == s[i]) {
                        pointer++;
                    }

                    if (pointer < s.size()) {
                        result += s[pointer];
                        swap(s[i], s[pointer]);
                        freq = 1;
                    } else {
                        break;
                    }
                }
            } else {
                result += s[i];
                freq = 1;
            }
        }

        return result;
    }
};