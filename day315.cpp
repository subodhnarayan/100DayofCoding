-- -- -- -- -- -- -- -- -GFG - POTD - 07 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
Longest Palindromic Subsequence
Difficulty: MediumAccuracy: 56.57%Submissions: 101K+Points: 4
Given a string s, return the length of the longest palindromic subsequence.

A subsequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements.

A palindromic sequence is a sequence that reads the same forward and backward.

Examples:

Input: s = "bbabcbcab"
Output: 7
Explanation: Subsequence "babcbab" is the longest subsequence which is also a palindrome.
Input: s = "abcd"
Output: 1
Explanation: "a", "b", "c" and "d" are palindromic and all have a length 1.
Input: s = "agbdba"
Output: 5
Explanation: The longest palindromic subsequence is "abdba", which has a length of 5. The characters in this subsequence are taken from the original string "agbdba", and they maintain the order of the string while forming a palindrome.
Constraints:
1 ≤ s.size() ≤ 1000
The string contains only lowercase letters.

Time Complexity: O(n^2)Auxiliary Space: O(n^2)


class Solution {
  public:int dp[1001][1001];
    int solve(int i, int j, string &s){
        if (i > j) return 0;
        if (i == j) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        int op1 = 0, op2 = 0, op3 = 0;
        if (s[i] == s[j]){
            op1 = 2 + solve(i+1, j-1, s);
        }
        else{
            op2 = solve(i+1, j, s);
            op3 = solve(i, j-1, s);
        }
        
        dp[i][j] = max({op1,op2,op3});
        return dp[i][j];
    }
  
    int longestPalinSubseq(string &s) {
        // code here
        memset(dp, -1 , sizeof(dp));
        return solve(0, s.length(), s);
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 07 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
2523. Closest Prime Numbers in Range
Solved
Medium
Topics
Companies
Hint
Given two positive integers left and right, find the two integers num1 and num2 such that:

left <= num1 < num2 <= right .
Both num1 and num2 are prime numbers.
num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

 

Example 1:

Input: left = 10, right = 19
Output: [11,13]
Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
Since 11 is smaller than 17, we return the first pair.
Example 2:

Input: left = 4, right = 6
Output: [-1,-1]
Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
 

Constraints:

1 <= left <= right <= 106

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int upperLimit = right;
        // Step 1: Get all prime numbers up to 'right' using sieve
        vector<int> sieveArray = sieve(upperLimit);

        vector<int>
            primeNumbers;  // Store all primes in the range [left, right]
        for (int num = left; num <= right; num++) {
            // If number is prime add to the primeNumbers list
            if (sieveArray[num] == 1) {
                primeNumbers.push_back(num);
            }
        }

        // Step 2: Find the closest prime pair
        if (primeNumbers.size() < 2)
            return vector<int>{-1, -1};  // Less than two primes available

        int minDifference = INT_MAX;
        vector<int> closestPair(2, -1);  // setting initial values

        for (int index = 1; index < primeNumbers.size(); index++) {
            int difference = primeNumbers[index] - primeNumbers[index - 1];
            if (difference < minDifference) {
                minDifference = difference;
                closestPair[0] = primeNumbers[index - 1];
                closestPair[1] = primeNumbers[index];
            }
        }

        return closestPair;
    }

private:
    vector<int> sieve(int upperLimit) {
        // Initiate an int array to mark prime numbers
        vector<int> sieve(upperLimit + 1,
                          1);  // Assuming all numbers as prime initially

        // 0 and 1 are not prime
        sieve[0] = 0;
        sieve[1] = 0;

        for (int number = 2; number * number <= upperLimit; number++) {
            if (sieve[number] == 1) {
                // Mark all multiples of 'number' as non-prime
                for (int multiple = number * number; multiple <= upperLimit;
                     multiple += number) {
                    sieve[multiple] = 0;
                }
            }
        }
        return sieve;
    }
};
