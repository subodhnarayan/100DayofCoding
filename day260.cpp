-- -- -- -- -- -- -- -- -GFG - POTD - 13 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Container With Most Water
Difficulty: MediumAccuracy: 53.84%Submissions: 64K+Points: 4
Given an array arr[] of non-negative integers, where each element arr[i] represents the height of the vertical lines, find the maximum amount of water that can be contained between any two lines, together with the x-axis.

Note: In the case of a single vertical line it will not be able to hold water.

Examples:

Input: arr[] = [1, 5, 4, 3]
Output: 6
Explanation: 5 and 3 are 2 distance apart. So the size of the base is 2. Height of container = min(5, 3) = 3. So, total area to hold water = 3 * 2 = 6.
Input: arr[] = [3, 1, 2, 4, 5]
Output: 12
Explanation: 5 and 3 are 4 distance apart. So the size of the base is 4. Height of container = min(5, 3) = 3. So, total area to hold water = 4 * 3 = 12.
Input: arr[] = [2, 1, 8, 6, 4, 6, 5, 5]
Output: 25 
Explanation: 8 and 5 are 5 distance apart. So the size of the base is 5. Height of container = min(8, 5) = 5. So, the total area to hold water = 5 * 5 = 25.
Constraints:
1<= arr.size() <=105
1<= arr[i] <=104

class Solution {

  public:
    int maxWater(vector<int> &arr) {
        // code here
        int i=0, j = arr.size() - 1;
        int water = 0;
        
        while(i<j){
            int area = min(arr[i], arr[j])*(j-i);
            
            water = max(water, area);
            if(arr[i] <= arr[j]){
                i++;
            }
            else{
                j--;
            }
        }
        
        return water;
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 13 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
3223. Minimum Length of String After Operations
Solved
Medium
Topics
Companies
Hint
You are given a string s.

You can perform the following process on s any number of times:

Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
Delete the closest character to the left of index i that is equal to s[i].
Delete the closest character to the right of index i that is equal to s[i].
Return the minimum length of the final string s that you can achieve.

 

Example 1:

Input: s = "abaacbcbb"

Output: 5

Explanation:
We do the following operations:

Choose index 2, then remove the characters at indices 0 and 3. The resulting string is s = "bacbcbb".
Choose index 3, then remove the characters at indices 0 and 5. The resulting string is s = "acbcb".
Example 2:

Input: s = "aa"

Output: 2

Explanation:
We cannot perform any operations, so we return the length of the original string.

 

Constraints:

1 <= s.length <= 2 * 105
s consists only of lowercase English letters.

class Solution {
public:
    int minimumLength(string s) {
        // Step 1: Count the frequency of each character in the string
        unordered_map<char, int> charFrequencyMap;
        for (char currentChar : s) {
            charFrequencyMap[currentChar]++;
        }

        // Step 2: Calculate the number of characters to delete
        int deleteCount = 0;
        for (auto& pair : charFrequencyMap) {
            int frequency = pair.second;
            if (frequency % 2 == 1) {
                // If frequency is odd, delete all except one
                deleteCount += frequency - 1;
            } else {
                // If frequency is even, delete all except two
                deleteCount += frequency - 2;
            }
        }

        // Step 3: Return the minimum length after deletions
        return s.length() - deleteCount;
    }
};
