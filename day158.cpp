-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 06 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Largest Pair Sum
Difficulty: EasyAccuracy: 60.24%Submissions: 23K+Points: 2
Find the largest pair sum in an array of distinct integers.

Examples :

Input: arr[] = [12, 34, 10, 6, 40]
Output: 74
Explanation: Sum of 34 and 40 is the largest, i.e, 34 + 40 = 74.
Input: arr[] = [10, 20, 30]
Output: 50
Explanation: 20 + 30 = 50.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 106



class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
         int t1=arr[0];
        int t2=arr[1];
        for(int i=2;i<arr.size();i++){
            if(arr[i]>t2){
                if(t2>t1){
                    t1=t2;
                }
                t2=arr[i];
                }
                else{
                    if(arr[i]>t1){
                        t1=arr[i];
                    }
                }
            
        }
        return t1+t2;
    }
};