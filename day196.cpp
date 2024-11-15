-- -- -- -- -- -- -- -- -GFG - POTD - 15 / 11 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        
        int n=arr.size();
        int flar=-1;
        int slar=-1;
        
        for(int i=0;i<n;i++){
            if(arr[i]>flar){
                slar=flar;
                flar=arr[i];
            }
            else if(arr[i]>slar && arr[i]!=flar){
                slar=arr[i];
            }
        }
        return slar;
    }
};
