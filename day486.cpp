-- -- -- -- -- -- -- -- -GFG - POTD - 27 / 04 / 2025 -----------------------------------
Multiply two strings
Difficulty: MediumAccuracy: 20.06%Submissions: 233K+Points: 4Average Time: 20m
Given two numbers as strings s1 and s2. Calculate their Product.
Note: The numbers can be negative and You are not allowed to use any built-in function or convert the strings to integers. There can be zeros in the begining of the numbers. You don't need to specify '+' sign in the begining of positive numbers.

Examples:

Input: s1 = "0033", s2 = "2"
Output: "66"
Explanation: 33 * 2 = 66
Input: s1 = "11", s2 = "23"
Output: "253"
Explanation: 11 * 23  = 253
Input: s1 = "123", s2 = "0"
Output: "0"
Explanation: Anything multiplied by 0 is equal to 0.
Constraints:
1 ≤ s1.size() ≤ 103
1 ≤ s2.size() ≤ 103

Expected Complexities
Time Complexity: O(n * m)
Auxiliary Space: O(n * m)


class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
         int a=s1.length(),b=s2.length();
       string s="";
       int sign1 = (s1[0] == '-') ? -1 : 1;
       int sign2 = (s2[0] == '-') ? -1 : 1;
       if (s1[0] == '-') {s1=s1.substr(1);a--;}
       if (s2[0] == '-') {s2=s2.substr(1);b--;}
       vector<int>v(a+b,0);
       for(int i=a-1;i>=0;i--){
           for(int j=b-1;j>=0;j--){
               int p=(s1[i]-'0')*(s2[j]-'0');
               int s=p+v[i+j+1];
               v[i+j+1]=s%10;
               v[i+j]+=s/10;
           }
       }
       int finalsign=sign1*sign2;
       for(int i=0;i<v.size();i++) {
          if (finalsign ==-1&&!(s.empty()&&v[i] == 0)) {
              s ="-"+s;finalsign=1;
          }
           if(!(s.empty()&&v[i]==0)) s+=to_string(v[i]);
       }
       return s.empty()?"0":s;
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 27 / 04 / 2025 -----------------------------------


3392. Count Subarrays of Length Three With a Condition
Solved
Easy
Topics
Companies
Hint
Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.

 

Example 1:

Input: nums = [1,2,1,4,1]

Output: 1

Explanation:

Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.

Example 2:

Input: nums = [1,1,1]

Output: 0

Explanation:

[1,1,1] is the only subarray of length 3. However, its first and third numbers do not add to half the middle number.

 

Constraints:

3 <= nums.length <= 100
-100 <= nums[i] <= 100



class Solution {
    public:
        int countSubarrays(vector<int>& nums) {
             int n = nums.size();
            int ans = 0;
            for (int i = 1; i < n - 1; ++i) {
                if (nums[i] == (nums[i - 1] + nums[i + 1]) * 2) {
                    ++ans;
                }
            }
            return ans;
        }
};

