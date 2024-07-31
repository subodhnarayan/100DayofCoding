-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFg - POTD - 30 / 07 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Longest Common Prefix of Strings
Difficulty: EasyAccuracy: 29.52%Submissions: 279K+Points: 2
Given an array of strings arr. Return the longest common prefix among all strings present in the array. If there's no prefix common in all the strings, return "-1".

Examples :

Input: arr[] = ["geeksforgeeks", "geeks", "geek", "geezer"]
Output: gee
Explanation: "gee" is the longest common prefix in all the given strings.
Input: arr[] = ["hello", "world"]
Output: -1
Explanation: There's no common prefix in the given strings.
Expected Time Complexity: O(n*min(|arri|))
Expected Space Complexity: O(min(|arri|))

Constraints:
1 ≤ |arr| ≤ 103
1 ≤ |arr[i]| ≤ 103


class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
          sort(arr.begin(),arr.end(),[&](auto a,auto b){
            return a.length()<b.length();
        });
        int len=arr[0].size();
        string ans= arr[0];
        for(int i=1;i<arr.size();i++){
            for(int j=0;j<len;j++){
                if(arr[i][j]!=ans[j]){
                    len=j;
                }
            }
        }
        return len==0? "-1" :ans.substr(0,len);
    }
};



