
-- -- -- -- -- -- -- -- -GFG - POTD - 16 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------
Minimum Jumps
Difficulty: MediumAccuracy: 11.91%Submissions: 970K+Points: 4
You are given an array arr[] of non-negative numbers. Each number tells you the maximum number of steps you can jump forward from that position.

For example:

If arr[i] = 3, you can jump to index i + 1, i + 2, or i + 3 from position i.
If arr[i] = 0, you cannot jump forward from that position.
Your task is to find the minimum number of jumps needed to move from the first position in the array to the last position.

Note:  Return -1 if you can't reach the end of the array.

Examples : 

Input: arr[] = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
Output: 3 
Explanation: First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last. 
Input: arr = [1, 4, 3, 2, 6, 7]
Output: 2 
Explanation: First we jump from the 1st to 2nd element and then jump to the last element.
Input: arr = [0, 10, 20]
Output: -1
Explanation: We cannot go anywhere from the 1st element.
Constraints:
2 ≤ arr.size() ≤ 104
0 ≤ arr[i] ≤ 104

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        if(arr[0]==0) return -1;
        int mx=0;
        int jump=arr[0];
        int n=arr.size();
        int ans=1;
        for(int i=1;i<n;i++){
            mx--;
            jump--;
            mx=max(mx,arr[i]);
            if(!jump and i!=n-1){
                if(mx<=0) return -1;
                jump=mx;
                mx=0;
                ans++;
            }
        }
        return ans;
    }
};


-- -- -- -- -- -- -- -- -LeetCode - POTD - 16 / 03 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------


2594. Minimum Time to Repair Cars
Medium
Topics
Companies
Hint
You are given an integer array ranks representing the ranks of some mechanics. ranksi is the rank of the ith mechanic. A mechanic with a rank r can repair n cars in r * n2 minutes.

You are also given an integer cars representing the total number of cars waiting in the garage to be repaired.

Return the minimum time taken to repair all the cars.

Note: All the mechanics can repair the cars simultaneously.

 

Example 1:

Input: ranks = [4,2,3,1], cars = 10
Output: 16
Explanation: 
- The first mechanic will repair two cars. The time required is 4 * 2 * 2 = 16 minutes.
- The second mechanic will repair two cars. The time required is 2 * 2 * 2 = 8 minutes.
- The third mechanic will repair two cars. The time required is 3 * 2 * 2 = 12 minutes.
- The fourth mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
Example 2:

Input: ranks = [5,1,8], cars = 6
Output: 16
Explanation: 
- The first mechanic will repair one car. The time required is 5 * 1 * 1 = 5 minutes.
- The second mechanic will repair four cars. The time required is 1 * 4 * 4 = 16 minutes.
- The third mechanic will repair one car. The time required is 8 * 1 * 1 = 8 minutes.
It can be proved that the cars cannot be repaired in less than 16 minutes.​​​​​
 

Constraints:

1 <= ranks.length <= 105
1 <= ranks[i] <= 100
1 <= cars <= 106


class Solution {
public:
 bool timeIsSuff(vector<int>& ranks, int cars, long long minGiven) {
        long long carsDone = 0;
        for (int r : ranks) {
            long long c2 = minGiven / r;
            long long c = floor(sqrt(c2));
            carsDone += c;
        }
        return carsDone >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
         long long l = 1, r = 1e14;
        while (l < r) {
            long long mid = (l + r) / 2;
            if (timeIsSuff(ranks, cars, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};