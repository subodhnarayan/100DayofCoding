-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 17 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

 Minimize the Heights II
Difficulty: MediumAccuracy: 15.06%Submissions: 600K+Points: 4
Given an array arr[] denoting heights of N towers and a positive integer K.

For each tower, you must perform exactly one of the following operations exactly once.

Increase the height of the tower by K
Decrease the height of the tower by K
Find out the minimum possible difference between the height of the shortest and tallest towers after you have modified each tower.

You can find a slight modification of the problem here.
Note: It is compulsory to increase or decrease the height by K for each tower. After the operation, the resultant array should not contain any negative integers.

Examples :

Input: k = 2, arr[] = {1, 5, 8, 10}
Output: 5
Explanation: The array can be modified as {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}.The difference between the largest and the smallest is 8-3 = 5.
Input: k = 3, arr[] = {3, 9, 12, 16, 20}
Output: 11
Explanation: The array can be modified as {3+k, 9+k, 12-k, 16-k, 20-k} -> {6, 12, 9, 13, 17}.The difference between the largest and the smallest is 17-6 = 11. 
Expected Time Complexity: O(n*logn)
Expected Auxiliary Space: O(n)

Constraints
1 ≤ k ≤ 107
1 ≤ n ≤ 105
1 ≤ arr[i] ≤ 107


class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
           int n = arr.size();
        if (n == 1) return 0;  // No height difference if there's only one element
        
        // Sort the array
        std::sort(arr.begin(), arr.end());

        // Initial difference without any adjustment
        int minDiff = arr[n-1] - arr[0];

        // Iterate through the sorted array and calculate the possible minimum difference
        for (int i = 1; i < n; ++i) {
            if (arr[i] < k) continue; // Skip if adjusting will make height negative

            // Adjust the minimum and maximum values after modification
            int minValue = std::min(arr[0] + k, arr[i] - k); // Adjust minimum height
            int maxValue = std::max(arr[n-1] - k, arr[i-1] + k); // Adjust maximum height

            // Update the minimum difference
            minDiff = std::min(minDiff, maxValue - minValue);
        }

        return minDiff;
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 17 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

884. Uncommon Words from Two Sentences
Solved
Easy
Topics
Companies
A sentence is a string of single-space separated words where each word consists only of lowercase letters.

A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.

Given two sentences s1 and s2, return a list of all the uncommon words. You may return the answer in any order.

 

Example 1:

Input: s1 = "this apple is sweet", s2 = "this apple is sour"

Output: ["sweet","sour"]

Explanation:

The word "sweet" appears only in s1, while the word "sour" appears only in s2.

Example 2:

Input: s1 = "apple apple", s2 = "banana"

Output: ["banana"]

 

Constraints:

1 <= s1.length, s2.length <= 200
s1 and s2 consist of lowercase English letters and spaces.
s1 and s2 do not have leading or trailing spaces.
All the words in s1 and s2 are separated by a single space.


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
       string s = s1 + " " + s2;
        stringstream str(s);

        cout<<s1.max_size();

        // store all words from s
        unordered_map<string,int> um;
        string tmp;
        while(str>>tmp){
            um[tmp]++;
        }

        // check unique means single count
        vector<string> ans;
        for(auto& val:um){ // auto it=um.begin();it<um.end();it++

            // val.first = apple, val.second = 2

            if(val.second==1){
                ans.emplace_back(val.first); // can use push_back also                
            }

        }

        return ans; 
    }
};