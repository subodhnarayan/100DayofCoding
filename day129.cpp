- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 9 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Sort 0s, 1s and 2s
Difficulty: EasyAccuracy: 50.58%Submissions: 690K+Points: 2
Given an array arr containing only 0s, 1s, and 2s. Sort the array in ascending order.

Examples:

Input: arr[]= [0, 2, 1, 2, 0]
Output: 0 0 1 2 2
Explanation: 0s 1s and 2s are segregated into ascending order.
Input: arr[] = [0, 1, 0]
Output: 0 0 1
Explanation: 0s 1s and 2s are segregated into ascending order.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr.size() <= 106
0 <= arr[i] <= 2

class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zc=0,oc=0,tc=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                zc++;
            }
            else if(arr[i]==1){
                oc++;
            }
            else{
                tc++;
            }
        }
        
        for(int i=0;i<zc;i++){
            arr[i]=0;
        }
        for(int i=zc;i<zc+oc;i++){
            arr[i]=1;
        }
        for(int i=zc+oc;i<zc+oc+tc;i++){
            arr[i]=2;
        }
    }
};
