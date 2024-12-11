-- -- -- -- -- -- -- -- -GFG - POTD - 10 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Merge Without Extra Space
Difficulty: HardAccuracy: 32.01%Submissions: 271K+Points: 8
Given two sorted arrays a[] and b[] of size n and m respectively, the task is to merge them in sorted order without using any extra space. Modify a[] so that it contains the first n elements and modify b[] so that it contains the last m elements.

Examples:

Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
Output:
2 2 3 4
7 10
Explanation: After merging the two non-decreasing arrays, we get, 2 2 3 4 7 10
Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
Output:
1 2 3 5 8 9
10 13 15 20
Explanation: After merging two sorted arrays we get 5 10 12 18 20.
Input: a[] = [0, 1], b[] = [2, 3]
Output:
0 1
2 3
Explanation: After merging two sorted arrays we get 0 1 2 3.
Constraints:
1 <= a.size(), b.size() <= 105
0 <= a[i], b[i] <= 107


class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        
        //approach using extra space
    //   vector<int> ans;
    //   int m=a.size();
    //   int n=b.size();
    //   for(int i=0;i<a.size();i++){
    //       ans.push_back(a[i]);
    //   }
    //   for(int i=0;i<n;i++){
    //       ans.push_back(b[i]);
    //   }
    //   sort(ans.begin(),ans.end());
    //   for(int i=0;i<m;i++){
    //       a[i]=ans[i];
    //   }
    //   for(int i=0;i<n;i++){
    //       b[i]=ans[m+i];
    //   }
    
    int m=a.size();
    int n=b.size();
    
    int gp=ceil((double)(m+n)/2.0);
    
    while(gp>0){
        int i=0,j=gp;
        
        while(j<m+n){
            
        
        if(j<m && a[i]>a[j]){
            swap(a[i],a[j]);
        }
        else if(i<m && j>=m && a[i]>b[j-m]){
            swap(a[i],b[j-m]);
        }
        else if(i>=m && j>=m && b[i-m]>b[j-m]){
            swap(b[i-m],b[j-m]);
        }
        i++;
        j++;
    }
    
    if(gp==1) break;
    gp=ceil((double)gp/2.0);
    }
    
    }
};
-- -- -- -- -- -- -- -- -Leetcode - POTD - 10 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -






