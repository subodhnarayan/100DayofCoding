-- -- -- -- -- -- -- -- -GFG - POTD - 10 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

K Sum Paths
Difficulty: MediumAccuracy: 44.73%Submissions: 117K+Points: 4
Given a binary tree and an integer k, determine the number of downward-only paths where the sum of the node values in the path equals k. A path can start and end at any node within the tree but must always move downward (from parent to child).

Examples:

Input: k = 7   

Output: 3
Explanation: The following paths sum to k 
 
Input: k = 3

Output: 2
Explanation:
Path 1 : 1 -> 2 (Sum = 3)
Path 2 : 3 (Sum = 3)


Constraints:

1 ≤ number of nodes ≤ 104
-100 ≤ node value ≤ 100
-109 ≤ k ≤ 109


class Solution {
    public:
       int total = 0;
          const int mod=1e9+7;
          void solve(Node* node, int k, unordered_map<int,int> &ump, int sum){
              if(node==nullptr) return;
              sum+=node->data;
              if(ump.find(sum-k)!=ump.end()) total=(total+ump[sum-k])%mod;
              ump[sum]++;
              solve(node->left, k, ump, sum);
              solve(node->right, k, ump, sum);
              ump[sum]--;
              if(ump[sum]==0) ump.erase(sum);
          }
      int sumK(Node *root, int k) {
          // code here
           unordered_map<int,int> ump;
          ump[0]=1;
          solve(root, k, ump, 0);
          return total;
      }
  };

-- -- -- -- -- -- -- -- -LeetCode - POTD - 10 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

3174. Clear Digits
Solved
Easy
Topics
Companies
Hint
You are given a string s.

Your task is to remove all digits by doing this operation repeatedly:

Delete the first digit and the closest non-digit character to its left.
Return the resulting string after removing all digits.

 

Example 1:

Input: s = "abc"

Output: "abc"

Explanation:

There is no digit in the string.

Example 2:

Input: s = "cb34"

Output: ""

Explanation:

First, we apply the operation on s[2], and s becomes "c4".

Then we apply the operation on s[1], and s becomes "".

 

Constraints:

1 <= s.length <= 100
s consists only of lowercase English letters and digits.
The input is generated such that it is possible to delete all digits.


class Solution {
    public:
        string clearDigits(string s) {
            string stack;
            for (char c : s) {
                if (isdigit(c)) {
                    if (!stack.empty()) stack.pop_back();
                } else {
                    stack.push_back(c);
                }
            }
            return stack;
        }
    };