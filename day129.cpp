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


2326. Spiral Matrix IV
Solved
Medium
Topics
Companies
Hint
You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.

 

Example 1:


Input: m = 3, n = 5, head = [3,0,2,6,8,1,7,9,4,2,5,5,0]
Output: [[3,0,2,6,8],[5,0,-1,-1,1],[5,2,4,9,7]]
Explanation: The diagram above shows how the values are printed in the matrix.
Note that the remaining spaces in the matrix are filled with -1.
Example 2:


Input: m = 1, n = 4, head = [0,1,2]
Output: [[0,1,2,-1]]
Explanation: The diagram above shows how the values are printed from left to right in the matrix.
The last space in the matrix is set to -1.
 

Constraints:

1 <= m, n <= 105
1 <= m * n <= 105
The number of nodes in the list is in the range [1, m * n].
0 <= Node.val <= 1000

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int left=0,right=n-1;
        int top=0,down=m-1;
        ListNode* curr=head;
        vector<vector<int>> arr(m,vector<int> (n,-1));
        while(left<=right && top<=down && curr!=NULL){
            for(int i=left;i<=right && curr != NULL;i++){
                arr[top][i]=curr->val;
                 curr=curr->next;
            }
            top++;
            for(int i=top;i<=down && curr != NULL;i++){
                arr[i][right]=curr->val;
                 curr=curr->next;
                }  
            right--;
            if(top<=down){
            for(int i=right;i>=left && curr != NULL;i--){
                arr[down][i]=curr->val;
                 curr=curr->next;
            }
            down--;
            }
            if(left<=right){
            for(int i=down;i>=top && curr != NULL;i--){
                arr[i][left]=curr->val;
                 curr=curr->next;
            }
            left++;
            }
        }
        return arr;
    }
};



