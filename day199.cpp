-- -- -- -- -- -- -- -- -GFG - POTD - 18 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Rotate Array
Difficulty: MediumAccuracy: 37.06%Submissions: 377K+Points: 4
Given an unsorted array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.
Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.
Input: arr[] = [7, 3, 9, 1], d = 9
Output: [3, 9, 1, 7]
Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.
Constraints:
1 <= arr.size(), d <= 105
0 <= arr[i] <= 105


     void reverse(vector<int> &arr,int start,int end){
         while(start<end){
             int temp=arr[start];
             arr[start]=arr[end];
             arr[end]=temp;
             start++,end--;
             
         }
     }
     
    void rotateArr(vector<int>& arr, int k) {
        //soln with S.C=O(d)
        // int n=arr.size();
        // int ans = d % n;
        // vector<int> st;
        // for(int i=0;i<ans;i++){
        //     st.push_back(arr[i]);
        // }
        // int j=0;
        // for(int i=ans;i<n;i++){
        //     arr[j]=arr[i];
        //     j++;
        // }
        // int k=0;
        // for(int i=n-ans;i<n;i++){
        //     arr[i]=st[k];
        //     k++;
        // }
        
        //optimized solution
        int n=arr.size();
        k=k%n;
        reverse(arr,0,k-1);
        reverse(arr,k,n-1);
        reverse(arr,0,n-1);
    }



-- -- -- -- -- -- -- -- -Leetcode - POTD - 18 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


You have a bomb to defuse, and your time is running out! Your informer will provide you with a circular array code of length of n and a key k.

To decrypt the code, you must replace every number. All the numbers are replaced simultaneously.

If k > 0, replace the ith number with the sum of the next k numbers.
If k < 0, replace the ith number with the sum of the previous k numbers.
If k == 0, replace the ith number with 0.
As code is circular, the next element of code[n-1] is code[0], and the previous element of code[0] is code[n-1].

Given the circular array code and an integer key k, return the decrypted code to defuse the bomb!

 

Example 1:

Input: code = [5,7,1,4], k = 3
Output: [12,10,16,13]
Explanation: Each number is replaced by the sum of the next 3 numbers. The decrypted code is [7+1+4, 1+4+5, 4+5+7, 5+7+1]. Notice that the numbers wrap around.
Example 2:

Input: code = [1,2,3,4], k = 0
Output: [0,0,0,0]
Explanation: When k is zero, the numbers are replaced by 0. 
Example 3:

Input: code = [2,4,9,3], k = -2
Output: [12,5,6,13]
Explanation: The decrypted code is [3+9, 2+3, 4+2, 9+4]. Notice that the numbers wrap around again. If k is negative, the sum is of the previous numbers.
 

Constraints:

n == code.length
1 <= n <= 100
1 <= code[i] <= 100
-(n - 1) <= k <= n - 1



class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans;
        if(k==0){
         for(int i=0;i<n;i++){
            ans.push_back(0);
         }
         return ans;
        }
        else if(k>0){
            for(int i=0;i<n;i++){
                int sum=0;
                for(int j=1;j<=k;j++){
                    sum+=code[(i+j)%n];
                }
                ans.push_back(sum);
            }
            return ans;
        }
        else{
           for(int i=0;i<n;i++){
                int sum=0;
                for(int j=1;j<=-k;j++){
                    sum+=code[(i - j + n) % n];
                }
                ans.push_back(sum);
            }
            return ans;
        }
    }
};