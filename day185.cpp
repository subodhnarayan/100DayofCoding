-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 4 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Find All Triplets with Zero Sum
Difficulty: EasyAccuracy: 50.36%Submissions: 23K+Points: 2
Given an array arr[], find all possible indices [i, j, k] of triplets [arr[i], arr[j], arr[k]] in the array whose sum is equal to zero. Return indices of triplets in any order and all the returned triplets indices should also be internally sorted, i.e., for any triplet indices [i, j, k], the condition i < j < k should hold.

Note: Try to solve this using the O(n2) approach.

Examples:

Input: arr[] = [0, -1, 2, -3, 1]
Output: [[0, 1, 4], [2, 3, 4]]
Explanation: Triplets with sum 0 are:
arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0
arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0
Input: arr[] = [1, -2, 1, 0, 5]
Output: [[0, 1, 2]]
Explanation: Only triplet which satisfies the condition is arr[0] + arr[1] + arr[2] = 1 + (-2) + 1 = 0
Input: arr[] = [2, 3, 1, 0, 5]
Output: [[]]
Explanation: There is no triplet with sum 0.
Constraints:
3 <= arr.size() <= 103
-104 <= arr[i] <= 104


class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &nums) {
        vector<vector<int>> res;
        
        for(int i=0;i<nums.size();i++)
        {
            unordered_map<int,unordered_set<int>> mp;
            
            for(int j=i+1;j<nums.size();j++)
            mp[nums[j]].insert(j);
            
            for(int j=i+1;j<nums.size();j++)
                if(mp.find(((-1) * nums[i])-nums[j])!=mp.end())
                    for(auto it : mp[((-1) * nums[i])-nums[j]])
                        if(it>i && it>j)
                            res.push_back({i,j,it});
        }

        return res;
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 4 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Given a string word, compress it using the following algorithm:

Begin with an empty string comp. While word is not empty, use the following operation:
Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
Append the length of the prefix followed by c to comp.
Return the string comp.

 

Example 1:

Input: word = "abcde"

Output: "1a1b1c1d1e"

Explanation:

Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.

For each prefix, append "1" followed by the character to comp.

Example 2:

Input: word = "aaaaaaaaaaaaaabb"

Output: "9a5a2b"

Explanation:

Initially, comp = "". Apply the operation 3 times, choosing "aaaaaaaaa", "aaaaa", and "bb" as the prefix in each operation.

For prefix "aaaaaaaaa", append "9" followed by "a" to comp.
For prefix "aaaaa", append "5" followed by "a" to comp.
For prefix "bb", append "2" followed by "b" to comp.
 

Constraints:

1 <= word.length <= 2 * 105
word consists only of lowercase English letters.

class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cnt = 1, n = word.size();
        char ch = word[0];
        for(int i=1;i<n;i++){
            if(word[i] == ch && cnt < 9)cnt++;
            else{
                comp.push_back(cnt+'0');
                comp.push_back(ch);
                ch = word[i];
                cnt = 1;
            }
        }
        comp.push_back(cnt+'0');
        comp.push_back(ch);
        return comp;
    }
};