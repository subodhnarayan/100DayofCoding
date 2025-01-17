-- -- -- -- -- -- -- -- -GFG - POTD - 17 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -



class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        
        
        //first brute force apporach
        // int n=arr.size();
        // vector<int> ans(n);
        // for(int i=0;i<n;i++){
        //   int mul=1;
        //   for(int j=0;j<n;j++){
        //       if(i!=j){
        //           mul=mul*arr[j];
        //       }
        //   }
        //   ans[i]=mul;
        // }
        // return ans;   // this solution gives TLE
        
        
        int n=arr.size();
        vector<int> ans(n,0);
        int mul=1;
        int zer=0;
        for(int i=0;i<n;i++){
               if(arr[i]!=0){
                   mul=mul*arr[i];
               }
               else{
                   zer++;
               }
        }
        if(zer>1){
            return ans;
        }
        else if(zer==1){
            for(int i=0;i<n;i++){
                if(arr[i]==0){
                    ans[i]=mul;
                }
                else{
                    ans[i]=0;
                }
            }
            return ans;
        }
        
        for(int i=0;i<n;i++){
            ans[i]=mul/arr[i];
        }
        return ans;
        
        
    }
};
-- -- -- -- -- -- -- -- -LeetCode - POTD - 17 / 01 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

