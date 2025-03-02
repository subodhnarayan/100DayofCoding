-- -- -- -- -- -- -- -- -GFG - POTD - 01 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Decode the string
Difficulty: MediumAccuracy: 44.28%Submissions: 48K+Points: 4Average Time: 10m
Given an encoded string s, the task is to decode it. The encoding rule is :

k[encodedString], where the encodedString inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
Note: The test cases are generated so that the length of the output string will never exceed 105 .

Examples:

Input: s = "1[b]"
Output: "b"
Explanation: "b" is present only one time.
Input: s = "3[b2[ca]]"
Output: "bcacabcacabcaca"
Explanation:
1. Inner substring “2[ca]” breakdown into “caca”.
2. Now, new string becomes “3[bcaca]”
3. Similarly “3[bcaca]” becomes “bcacabcacabcaca ” which is final result.
Constraints:
1 ≤ |s| ≤ 105 
1 <= k <= 100
s contains only lowercase english alphabets

Time Complexity: O(n)Auxiliary Space: O(n)


class Solution {
    public:
      string decodedString(string &s) {
          // code here
          stack<char>st;
          string ans="";
         for(auto &it:s){
             if(it==']'){
                 string str="";
                while(!st.empty() && st.top()!='['){
                    str=st.top()+str;
                    st.pop();
                }
                st.pop();
                int num=0,mt=1;
                while(!st.empty() && isdigit(st.top())){
                     num=(st.top()-'0')*mt+num;
                     mt*=10;
                     st.pop();
                }
              //   cout<<str<<" "<<num<<endl;
                while(num--){
                    for(auto &ch:str) st.push(ch);
                }
             }
             else st.push(it);
         }
         while(!st.empty()) {
             ans+=st.top();
             st.pop();
         }
         reverse(ans.begin(),ans.end());
          return ans;
      }
  };

-- -- -- -- -- -- -- -- -LeetCode - POTD - 01 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


2460. Apply Operations to an Array
Solved
Easy
Topics
Companies
Hint
You are given a 0-indexed array nums of size n consisting of non-negative integers.

You need to apply n - 1 operations to this array where, in the ith operation (0-indexed), you will apply the following on the ith element of nums:

If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.
After performing all the operations, shift all the 0's to the end of the array.

For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end, is [1,2,1,0,0,0].
Return the resulting array.

Note that the operations are applied sequentially, not all at once.

 

Example 1:

Input: nums = [1,2,2,1,1,0]
Output: [1,4,2,0,0,0]
Explanation: We do the following operations:
- i = 0: nums[0] and nums[1] are not equal, so we skip this operation.
- i = 1: nums[1] and nums[2] are equal, we multiply nums[1] by 2 and change nums[2] to 0. The array becomes [1,4,0,1,1,0].
- i = 2: nums[2] and nums[3] are not equal, so we skip this operation.
- i = 3: nums[3] and nums[4] are equal, we multiply nums[3] by 2 and change nums[4] to 0. The array becomes [1,4,0,2,0,0].
- i = 4: nums[4] and nums[5] are equal, we multiply nums[4] by 2 and change nums[5] to 0. The array becomes [1,4,0,2,0,0].
After that, we shift the 0's to the end, which gives the array [1,4,2,0,0,0].
Example 2:

Input: nums = [0,1]
Output: [1,0]
Explanation: No operation can be applied, we just shift the 0 to the end.
 

Constraints:

2 <= nums.length <= 2000
0 <= nums[i] <= 1000

class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
            vector<int> newNums(n, 0); 
            int count = 0;
    
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] != 0) {
                    if (nums[i] == nums[i + 1]) {
                        newNums[count] = nums[i] * 2; 
                        nums[i + 1] = 0;
                        i++; 
                    } else {
                        newNums[count] = nums[i]; 
                    }
                    count++;
                }
            }
            if (nums[n - 1] != 0) {
                newNums[count++] = nums[n - 1];
            }
            return newNums;
        }
    };