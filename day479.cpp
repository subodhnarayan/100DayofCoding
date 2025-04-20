-- -- -- -- -- -- -- -- -GFG - POTD - 20 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Find Only Repetitive Element from 1 to n-1
Difficulty: EasyAccuracy: 59.22%Submissions: 13K+Points: 2
Given an array arr[] of size n, filled with numbers from 1 to n-1 in random order. The array has only one repetitive element. Your task is to find the repetitive element.

Note: It is guaranteed that there is a repeating element present in the array.

Examples:

Input: arr[] = [1, 3, 2, 3, 4]
Output: 3 
Explanation: The number 3 is the only repeating element.
Input: arr[] = [1, 5, 1, 2, 3, 4]
Output: 1  
Explanation: The number 1 is the only repeating element.
Input: arr[] = [1, 1]  
Output: 1
Explanation: The array is of size 2 with both elements being 1, making 1 the repeating element.
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ n-1 

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)

class Solution {
    public:
      int findDuplicate(vector<int>& arr) {
          // code here
          int ans=0;
          for(int i=0;i<arr.size();i++) ans^=arr[i];
          for(int i=1;i<arr.size();i++) ans^=i;
          return ans;
      }
};
  

-- -- -- -- -- -- -- -- -Leetcode - POTD - 20 / 04 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

781. Rabbits in Forest
Solved
Medium
Topics
Companies
There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in the forest.

 

Example 1:

Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
Example 2:

Input: answers = [10,10,10]
Output: 11
 

Constraints:

1 <= answers.length <= 1000
0 <= answers[i] < 1000


class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for (int a : answers) {
            freq[a]++;
        }

        int count = 0;
        for (auto& [k, v] : freq) {
            int groupSize = k + 1;
            int groups = (v + k) / groupSize;
            count += groups * groupSize;
        }
        return count;
    }
};

