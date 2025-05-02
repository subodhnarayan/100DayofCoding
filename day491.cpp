-- -- -- -- -- -- -- -- -GFG - POTD - 02 / 05 / 2025 -----------------------------------

Bitonic Point
Difficulty: EasyAccuracy: 58.67%Submissions: 147K+Points: 2Average Time: 15m
Given an array of integers arr[] that is first strictly increasing and then maybe strictly decreasing, find the bitonic point, that is the maximum element in the array.
Bitonic Point is a point before which elements are strictly increasing and after which elements are strictly decreasing.

Note: It is guaranteed that the array contains exactly one bitonic point.

Examples:

Input: arr[] = [1, 2, 4, 5, 7, 8, 3]
Output: 8
Explanation: Elements before 8 are strictly increasing [1, 2, 4, 5, 7] and elements after 8 are strictly decreasing [3].
Input: arr[] = [10, 20, 30, 40, 50]
Output: 50
Explanation: Elements before 50 are strictly increasing [10, 20, 30 40] and there are no elements after 50.
Input: arr[] = [120, 100, 80, 20, 0]
Output: 120
Explanation: There are no elements before 120 and elements after 120 are strictly decreasing [100, 80, 20, 0].
Constraints:
3 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)

class Solution {
    public:
      int findMaximum(vector<int> &arr) {
          // code here
          int start=0;
          int end=arr.size()-1;
          int ans=0;
          while(start<=end){
              int mid=start+(end-start)/2;
              if((mid==arr.size()-1||arr[mid]>arr[mid+1])&&(mid==0||arr[mid]>arr[mid-1])){
                  ans= arr[mid];
              }
              if(mid>0 && arr[mid]>arr[mid+1]){ 
                  //mid<arr.size()-1&&arr[mid]<arr[mid+1]
                  end=mid-1;
              }
              else{
                  start=mid+1;
              }
          }
          return ans;
      }
         
  };
-- -- -- -- -- -- -- -- -Leetcode - POTD - 02 / 05 / 2025 -----------------------------------


838. Push Dominoes
Solved
Medium
Topics
Companies
There are n dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string dominoes representing the initial state where:

dominoes[i] = 'L', if the ith domino has been pushed to the left,
dominoes[i] = 'R', if the ith domino has been pushed to the right, and
dominoes[i] = '.', if the ith domino has not been pushed.
Return a string representing the final state.

 

Example 1:

Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: The first domino expends no additional force on the second domino.
Example 2:


Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
 

Constraints:

n == dominoes.length
1 <= n <= 105
dominoes[i] is either 'L', 'R', or '.'.


class Solution {
    public:
        string pushDominoes(string s) {
            s = 'L' + s + 'R';
            string res;
    
            int prev = 0;
            for (int curr = 1; curr < s.size(); ++curr) {
                if (s[curr] == '.') {
                    continue;
                }
    
                int span = curr - prev - 1;
                if (prev > 0) 
                    res += s[prev];
    
                if (s[prev] == s[curr]) {
                    res += string(span, s[prev]);
                }
                else if (s[prev] == 'L' && s[curr] == 'R') {
                    res += string(span, '.');
                }
                else { 
                    res += string(span / 2, 'R')
                         + string(span % 2, '.')
                         + string(span / 2, 'L');
                }
                prev = curr;
            }
            return res;
        }
    };
