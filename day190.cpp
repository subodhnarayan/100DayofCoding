-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 9 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Minimum sum
Difficulty: MediumAccuracy: 17.14%Submissions: 128K+Points: 4
Given an array arr[] such that each element is in the range [0 - 9], find the minimum possible sum of two numbers formed using the elements of the array. All digits in the given array must be used to form the two numbers. Return a string without leading zeroes.

Examples :

Input: arr[] = [6, 8, 4, 5, 2, 3]
Output: 604
Explanation: The minimum sum is formed by numbers 358 and 246.
Input: arr[] = [5, 3, 0, 7, 4]
Output: 82
Explanation: The minimum sum is formed by numbers 35 and 047.
Input: arr[] = [9, 4]
Output: 13
Explanation: The minimum sum is formed by numbers 9 and 4.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 9




class Solution {
  public:
    string minSum(vector<int> &arr) {
        sort(arr.begin(),arr.end());
        string num1="";
        string num2="";
        for(int i=0;i<arr.size();i++){
            if(i%2==0){
                num1+='0'+arr[i];
                
            }else{
                num2+='0'+arr[i];
                
            }
        }
        
        int n=num1.size();
        int m=num2.size();
        int i=n-1;
        int j=m-1;
        int carry=0;
        int d1,d2;
        string ans="";
        int temp;
        while(i>-1||j>-1||carry){
            
            if(i>-1){
             d1=num1[i]-'0';
            }else{
                d1=0;
            }
            if(j>-1){
            d2=num2[j]-'0';
            }else{
                d2=0;
            }
            temp=(d1+d2+carry);
            int n=temp%10;
            
            ans+=n+'0';
            carry=temp/10;
            i--;
            j--;
            
        }
        
        int k=0;
        reverse(ans.begin(),ans.end());
        for(k=0;k<ans.size();k++){
            if(ans[k]!='0'){
                break;
            }
        }
        return ans.substr(k);
    }
};





3133. Minimum Array End
Solved
Medium
Topics
Companies
Hint
You are given two integers n and x. You have to construct an array of positive integers nums of size n where for every 0 <= i < n - 1, nums[i + 1] is greater than nums[i], and the result of the bitwise AND operation between all elements of nums is x.

Return the minimum possible value of nums[n - 1].

 

Example 1:

Input: n = 3, x = 4

Output: 6

Explanation:

nums can be [4,5,6] and its last element is 6.

Example 2:

Input: n = 2, x = 7

Output: 15

Explanation:

nums can be [7,15] and its last element is 15.

 

Constraints:

1 <= n, x <= 108
