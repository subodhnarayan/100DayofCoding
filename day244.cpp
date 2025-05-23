-- -- -- -- -- -- -- -- -GFG - POTD - 29 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Find All Triplets with Zero Sum
Difficulty: MediumAccuracy: 50.36%Submissions: 43K+Points: 4
Given an array arr[], find all possible triplets i, j, k in the arr[] whose sum of elements is equals to zero. 
Returned triplet should also be internally sorted i.e. i<j<k.

Examples:

Input: arr[] = [0, -1, 2, -3, 1]
Output: [[0, 1, 4], [2, 3, 4]]
Explanation: Triplets with sum 0 are:
arr[0] + arr[1] + arr[4] = 0 + (-1) + 1 = 0
arr[2] + arr[3] + arr[4] = 2 + (-3) + 1 = 0
Input: arr[] = [1, -2, 1, 0, 5]
Output: [[0, 1, 2]]
Explanation: Only triplet which satisfies the condition is arr[0] + arr[1] + arr[2] = 1 + (-2) + 1 = 0
Input: arr[] = [2, 3, 1, 0, 5]
Output: [[]]
Explanation: There is no triplet with sum 0.
Constraints:
3 <= arr.size() <= 103
-104 <= arr[i] <= 104

class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &nums) {
         vector<vector<int>> res;
        
        for(int i=0;i<nums.size();i++)
        {
            unordered_map<int,unordered_set<int>> mp;
            
            for(int j=i+1;j<nums.size();j++)
            mp[nums[j]].insert(j);
            
            for(int j=i+1;j<nums.size();j++)
                if(mp.find(((-1) * nums[i])-nums[j])!=mp.end())
                    for(auto it : mp[((-1) * nums[i])-nums[j]])
                        if(it>i && it>j)
                            res.push_back({i,j,it});
        }

        return res;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 29 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

689. Maximum Sum of 3 Non-Overlapping Subarrays
Solved
Hard
Topics
Companies
Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

 

Example 1:

Input: nums = [1,2,1,2,6,7,5,1], k = 2
Output: [0,3,5]
Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
Example 2:

Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
Output: [0,2,4]
 

Constraints:

1 <= nums.length <= 2 * 104
1 <= nums[i] < 216
1 <= k <= floor(nums.length / 3)



class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
         const int n=nums.size();
        vector<int> ksum(n-k+1, 0), L(n-3*k+1, -1);
        int maxKsum=ksum[0]=accumulate(nums.begin(), nums.begin()+k, 0);
        L[0]=0;
        for(int i=1; i<n-k+1; i++){
            ksum[i]=ksum[i-1]-nums[i-1]+nums[i+k-1];
            if (i>n-3*k) continue;
            if (maxKsum<ksum[i]){
                maxKsum=ksum[i];
                L[i]=i;
            }
            else L[i]=L[i-1];
        //    cout<<i<<"->L->"<<L[i]<<" maxKsum="<<maxKsum<<endl;
        }
        vector<int> R(n-3*k+1, -1);
        maxKsum=ksum.back();
        R.back()=n-k;
        for(int i=n-k-1; i>=2*k; i--){
            if (maxKsum<=ksum[i]){// multiple answers, return the lexico smallest one
                maxKsum=ksum[i];
                R[i-2*k]=i;
            }
            else R[i-2*k]=R[i+1-2*k];
        //    cout<<i-2*k<<"->R->"<<R[i-2*k]<<" maxKsum="<<maxKsum<<endl;
        }
        vector<int> ans(3,-1);
        int max3K=0;
        for(int i=0; i<=n-3*k; i++){
             int sum3K=ksum[L[i]]+ksum[i+k]+ksum[R[i]];
             if (sum3K> max3K){
                max3K=sum3K;
                ans={L[i], i+k, R[i]};
             }
        }
        return ans;  
    }
};

