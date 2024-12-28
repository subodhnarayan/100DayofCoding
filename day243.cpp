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

