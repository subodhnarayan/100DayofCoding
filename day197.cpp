-- -- -- -- -- -- -- -- -GFG - POTD - 16 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        vector<int> ans;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                ans.push_back(arr[i]);
            }
        }
        for(int i=0;i<ans.size();i++){
            arr[i]=ans[i];
        }
        for(int i=ans.size();i<arr.size();i++){
            arr[i]=0;
        }
    }
};