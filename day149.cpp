-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 29 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Total count
Difficulty: EasyAccuracy: 48.74%Submissions: 51K+Points: 2
You are given an array arr[] of positive integers and a threshold value k. For each element in the array, divide it into the minimum number of small integers such that each divided integer is less than or equal to k. Compute the total number of these integer across all elements of the array.

Examples:

Input: k = 3, arr[] = [5, 8, 10, 13]
Output: 14
Explanation: Each number can be expressed as sum of different numbers less than or equal to k as 5 (3 + 2), 8 (3 + 3 + 2), 10 (3 + 3 + 3 + 1), 13 (3 + 3 + 3 + 3 + 1). So, the sum of count of each element is (2+3+4+5)=14.
Input: k = 4, arr[] = [10, 2, 3, 4, 7]
Output: 8
Explanation: Each number can be expressed as sum of different numbers less than or equal to k as 10 (4 + 4 + 2), 2 (2), 3 (3), 4 (4) and 7 (4 + 3).So, the sum of count of each element is (3 + 1 + 1 + 1 + 2) = 8.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 105
1 ≤ k ≤ 105

class Solution {
  public:
    int totalCount(int k, vector<int>& arr) {
        int count=0;
        for(int i=0;i<arr.size();i++)
        {
            int ele=arr[i];
            while(ele>0)
            {
                count++;
                ele-=k;
            }
        }
        return count;
    }
};



-- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 29 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

432. All O`one Data Structure
Solved
Hard
Topics
Companies
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.

 

Example 1:

Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"
 

Constraints:

1 <= key.length <= 10
key consists of lowercase English letters.
It is guaranteed that for each call to dec, key is existing in the data structure.
At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.





class AllOne {
public:
    unordered_map<string,int> count;  // Stores the count of each key
    set<pair<int,string>> se;         // Sorted set to keep counts and keys
    AllOne() {
          count.clear();  // Initialize the count map
    }
    
    void inc(string key) {
          int n = count[key];   // Get current count
        count[key]++;         // Increment the count
        se.erase({n, key});   // Remove the old pair from set
        se.insert({n+1, key}); // Insert the new pair with updated count
    }
    
    void dec(string key) {
        int n = count[key];   // Get current count
        count[key]--;         // Decrement the count
        se.erase({n, key});   // Remove the old pair from set
        if (count[key] > 0) se.insert({n-1, key});  // If count > 0, insert updated pair
        else count.erase(key);  // If count reaches 0, remove the key from map
    }
    
    string getMaxKey() {
         if (!se.empty()) return se.rbegin()->second;  // Last element gives the maximum
        return "";
    }
    
    string getMinKey() {
        if (!se.empty()) return se.begin()->second;  // First element gives the minimum
        return "";
    }
};

