-- -- -- -- -- -- -- -- -GFG - POTD - 08 / 06 / 2025 ----------------------------------------
Sum-string
Difficulty: HardAccuracy: 50.56%Submissions: 40K+Points: 8
Given a string s consisting of digits, determine whether it can be classified as a sum-string.

A sum-string is a string that can be split into more than two non-empty substrings such that:


The rightmost substring is equal to the sum of the two substrings immediately before it (interpreted as integers).

This condition must apply recursively to the substrings before it.

The rightmost substring (and any number in the sum) must not contain leading zeroes, unless the number is exactly '0'.

Examples:

Input: s = "12243660"
Output: true
Explanation: The string can be split as {"12", "24", "36", "60"} where each number is the sum of the two before it:
36 = 12 + 24, and 60 = 24 + 36. Hence, it is a sum-string.
Input: s = "1111112223"
Output: true
Explanation: Split the string as {"1", "111", "112", "223"}, where:
112 = 1 + 111 and 223 = 111 + 112. Hence, it follows the sum-string rule.
Input: s = "123456"
Output: false
Explanation: There is no valid split of the string such that each part satisfies the sum-string property recursively.
Constraints:
1 ≤ s.size() ≤ 100
String consists of characters from '0' to '9'.

Expected Complexities
Time Complexity: O(n^3)
Auxiliary Space: O(n)


class Solution {
  public:
  bool ans = false;
  
    string add(string a, string b){
        string res;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int n = a.length();
        int m = b.length();
        
        int len = max(n, m);
        int carry = 0;
        
        for(int i = 0; i < len; i++){
            int sum = 0;
            if(i < n) sum += (a[i] - '0');
            if(i < m) sum += (b[i] - '0');
            sum += carry;
            
            res.push_back('0' + (sum % 10));
        
            carry = (sum/10);
        }
        
        if(carry != 0) res.push_back('0' + carry);
        
        reverse(res.begin(), res.end());
        return res;
    }
  
    void rec(int i, vector<string>& store, string& s) {
        if(ans) return;  
        if(i == s.size()) {
            if(store.size() >= 3) ans = true;
            return;
        }
    
        for(int j = 1; j + i <= s.size(); j++) {
            string t = s.substr(i, j);
            if(t.size() > 1 && t[0] == '0') continue;  
            store.push_back(t);
    
            int sz = store.size();
            
            if(sz < 3 || add(store[sz - 2], store[sz - 3]) == store[sz - 1]) {
                rec(i + j, store, s);
            }
    
            store.pop_back();  
        }
    }

    bool isSumString(string &s) {
        // code here
        ans = false;
        vector <string> store;
        rec(0, store, s);
        return ans;
        
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 08 / 06 / 2025 ----------------------------------------

386. Lexicographical Numbers
Solved
Medium
Topics
premium lock icon
Companies
Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

You must write an algorithm that runs in O(n) time and uses O(1) extra space. 

 

Example 1:

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
Example 2:

Input: n = 2
Output: [1,2]
 

Constraints:

1 <= n <= 5 * 104

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> lexicographicalNumbers;
        int currentNumber = 1;

        // Generate numbers from 1 to n
        for (int i = 0; i < n; ++i) {
            lexicographicalNumbers.push_back(currentNumber);

            // If multiplying the current number by 10 is within the limit, do
            // it
            if (currentNumber * 10 <= n) {
                currentNumber *= 10;
            } else {
                // Adjust the current number by moving up one digit
                while (currentNumber % 10 == 9 || currentNumber >= n) {
                    currentNumber /= 10;  // Remove the last digit
                }
                currentNumber += 1;  // Increment the number
            }
        }

        return lexicographicalNumbers;
    }
};
