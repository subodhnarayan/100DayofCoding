-- -- -- -- -- -- -- -- -GFG - POTD - 26 / 06 / 2025 ----------------------------------------

Game with String
Difficulty: MediumAccuracy: 53.96%Submissions: 66K+Points: 4Average Time: 15m
Given a string s consisting of lowercase alphabets and an integer k, your task is to find the minimum possible value of the string after removing exactly k characters.

The value of the string is defined as the sum of the squares of the frequencies of each distinct character present in the string.

Examples :

Input: s = "abbccc", k = 2
Output: 6
Explaination: We remove two 'c' to get the value as 12 + 22 + 12 = 6 or We remove one 'b' and one 'c' to get the value 12 + 12 + 22 = 6.
Input: s = "aaab", k = 2
Output: 2
Explaination: We remove two 'a'. Now we get the value as 12 + 12 = 2.
Constraints:
0 ≤ k ≤ s.length() ≤ 105 

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        priority_queue<int>pq;
        vector<int>v(26,0);
        for(auto &b: s){v[b-'a']++;}
        for(auto &b: v){
            if(b!=0){pq.push(b);}
        }
        while(k--){
            int x=pq.top(); pq.pop();
            x--;
            pq.push(x);
        }
        int ans=0;
        while(pq.size()){
            ans+=(pq.top()*pq.top()); pq.pop();
        }
        return ans;
    }
};


-- -- -- -- -- -- -- -- -Leetcode - POTD - 26 / 06 / 2025 ----------------------------------------


