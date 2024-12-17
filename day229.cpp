-- -- -- -- -- -- -- -- -GFG - POTD - 17 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Aggressive Cows
Difficulty: MediumAccuracy: 59.57%Submissions: 91K+Points: 4
You are given an array with unique elements of stalls[], which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. Your task is to assign stalls to k cows such that the minimum distance between any two of them is the maximum possible.

Examples :

Input: stalls[] = [1, 2, 4, 8, 9], k = 3
Output: 3
Explanation: The first cow can be placed at stalls[0], 
the second cow can be placed at stalls[2] and 
the third cow can be placed at stalls[3]. 
The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.
Input: stalls[] = [10, 1, 2, 7, 5], k = 3
Output: 4
Explanation: The first cow can be placed at stalls[0],
the second cow can be placed at stalls[1] and
the third cow can be placed at stalls[4].
The minimum distance between cows, in this case, is 4, which also is the largest among all possible ways.
Input: stalls[] = [2, 12, 11, 3, 26, 7], k = 5
Output: 1
Explanation: Each cow can be placed in any of the stalls, as the no. of stalls are exactly equal to the number of cows.
The minimum distance between cows, in this case, is 1, which also is the largest among all possible ways.
Constraints:
2 <= stalls.size() <= 106
0 <= stalls[i] <= 108
1 <= k <= stalls.size()


class Solution {
  public:
  
  bool isP(int diff, int n, int k, vector<int> &arr){
        int cnt=1;
        int prev=arr[0];
        for(int i=1; i<n; i++){
            if(arr[i]-prev>=diff){
                cnt++;
                if(cnt==k) return 1;
                prev=arr[i];
            }else{
                continue;
            }
        }
        return 0;
    }
  
 
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(), stalls.end());
        int lo=0;
        int hi=stalls[n-1]-stalls[0];
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(isP(mid, n, k, stalls)){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return lo-1;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
     return solve(stalls.size(), k, stalls);
    }
};



-- -- -- -- -- -- -- -- -Leetcode - POTD - 17 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

