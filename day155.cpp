-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 05 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Courses
Tutorials
Jobs
Practice
Contests
S
21



Not a subset sum
Difficulty: MediumAccuracy: 45.92%Submissions: 34K+Points: 4
Given a sorted array arr[] of positive integers, find the smallest positive integer such that it cannot be represented as the sum of elements of any subset of the given array set.

Examples:

Input: arr[] = [1, 2, 3]
Output: 7
Explanation: 7 is the smallest positive number for which no subset is there with sum 7.
Input: arr[] = [3, 6, 9, 10, 20, 28]
Output: 1
Explanation: 1 is the smallest positive number for which no subset is there with sum 1.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints
1 <= arr.size() <= 106
1 <= arr[i] <= 108


class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // Your code goes here.
         int ans=1;
        for(int x:arr){
            if(x>ans) return ans;
            ans += x;
        }
        return ans;
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 05 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
          if (s1.length() > s2.length()) return false;

        vector<int> s1Count(26, 0), s2Count(26, 0);
        
        // Count frequencies of s1 and the first window in s2
        for (int i = 0; i < s1.length(); ++i) {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        // Slide the window over s2
        for (int i = 0; i < s2.length() - s1.length(); ++i) {
            if (s1Count == s2Count) return true;
            // Update the window
            s2Count[s2[i] - 'a']--;
            s2Count[s2[i + s1.length()] - 'a']++;
        }

        // Check the last window
        return s1Count == s2Count;
    }
};

