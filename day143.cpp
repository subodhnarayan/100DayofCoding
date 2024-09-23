-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 23 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Missing And Repeating
Difficulty: MediumAccuracy: 24.83%Submissions: 503K+Points: 4
Given an unsorted array arr of of positive integers. One number 'A' from set {1, 2,....,n} is missing and one number 'B' occurs twice in array. Find numbers A and B.

Examples

Input: arr[] = [2, 2]
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ n



Missing And Repeating
Difficulty: MediumAccuracy: 24.83%Submissions: 503K+Points: 4
Given an unsorted array arr of of positive integers. One number 'A' from set {1, 2,....,n} is missing and one number 'B' occurs twice in array. Find numbers A and B.

Examples

Input: arr[] = [2, 2]
Output: 2 1
Explanation: Repeating number is 2 and smallest positive missing number is 1.
Input: arr[] = [1, 3, 3] 
Output: 3 2
Explanation: Repeating number is 3 and smallest positive missing number is 2.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ n ≤ 105
1 ≤ arr[i] ≤ n

-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 23 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

2707. Extra Characters in a String
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.

Return the minimum number of extra characters left over if you break up s optimally.

 

Example 1:

Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:

Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
 

Constraints:

1 <= s.length <= 50
1 <= dictionary.length <= 50
1 <= dictionary[i].length <= 50
dictionary[i] and s consists of only lowercase English letters
dictionary contains distinct words


class Solution {
public:
    unordered_map<string, int> um;  // Dictionary words
    unordered_map<int, int> memo;   // Memoization map for storing dp results

    int solve(string& s, int ind) {
        // base condition, where recursion gets over
        if (ind >= s.size()) {
            return 0;
        }

        if (memo.find(ind) != memo.end()) {
            // Return memoized result if already computed
            return memo[ind];  
        }

        int extra = INT_MAX;
        string tmp = "";

        // Try all substrings starting from the current index
        for (int i = ind; i < s.size(); i++) {
            tmp += s[i];
            if (um.find(tmp) != um.end()) {
                // If the substring is in the dictionary, solve for the remaining part
                extra = min(extra, solve(s, i + 1));
            }
        }

        // Consider the case where the current character is counted as extra
        // basically skipping the current ind = 0
        extra = min(extra, 1 + solve(s, ind + 1));

        // Memoize the result for the current index
        memo[ind] = extra;
        
        return memo[ind];
    }
    int minExtraChar(string s, vector<string>& dict) {
       for (auto& val : dict) {
            um[val]++;
        }

        return solve(s, 0);   
    }
};