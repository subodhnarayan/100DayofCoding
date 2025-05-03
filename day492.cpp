-- -- -- -- -- -- -- -- -GFG - POTD - 03 / 05 / 2025 -----------------------------------

Prime List
Difficulty: MediumAccuracy: 53.68%Submissions: 39K+Points: 4
You are given the head of a linked list. You have to replace all the values of the nodes with the nearest prime number. If more than one prime number exists at an equal distance, choose the smallest one. Return the head of the modified linked list.

Examples :

Input: head = 2 → 6 → 10
Output: 2 → 5 → 11

Explanation: The nearest prime of 2 is 2 itself. The nearest primes of 6 are 5 and 7, since 5 is smaller so, 5 will be chosen. The nearest prime of 10 is 11.
Input: head = 1 → 15 → 20
Output: 2 → 13 → 19

Explanation: The nearest prime of 1 is 2. The nearest primes of 15 are 13 and 17, since 13 is smaller so, 13 will be chosen. The nearest prime of 20 is 19.
Constraints:
1 <= no. of Nodes <= 104
1 <= node.val <= 104

Expected Complexities
Time Complexity: O(n * sqrt(node.val))
Auxiliary Space: O(1)



unordered_map<int,bool>mp;
  
  bool isprime(int n) {
      if (n <= 1) return false;
      if (n <= 3) return true;
      if (n % 2 == 0 || n % 3 == 0) return false;
     
     
      if (mp.find(n) != mp.end()) {
          return mp[n];
      }
      
      for (int i = 5; i * i <= n; i += 6) {
          if (n % i == 0 || n % (i + 2) == 0) {
              mp[n] = false;
              return false;
          }
      }
      
      mp[n] = true;
      return true;
  }
  int nearestPrime(int val){
      int l = val -1;
      int r = val + 1;
      while(true){
          if(l>=2 && isprime(l)){
              return l;
          }
          if(isprime(r)){
              return r;
          }
          l--;
          r++;
      }
  }

class Solution {
  public:
    Node *primeList(Node *head) {
        // code here
           Node *temp = head;
        while(temp){
            if(!isprime(temp->val))
            temp->val=nearestPrime(temp->val);

            temp = temp ->next;
        }
        return head;
    }
};



-- -- -- -- -- -- -- -- -Leetcode - POTD - 03 / 05 / 2025 -----------------------------------


1007. Minimum Domino Rotations For Equal Row
Solved
Medium
Topics
Companies
In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)

We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.

Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.

If it cannot be done, return -1.

 

Example 1:


Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
Output: 2
Explanation: 
The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
Example 2:

Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
Output: -1
Explanation: 
In this case, it is not possible to rotate the dominoes to make one row of values equal.
 

Constraints:

2 <= tops.length <= 2 * 104
bottoms.length == tops.length
1 <= tops[i], bottoms[i] <= 6




class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int res = INT_MAX;
    
            int face[7] = {};
            for(int i = 0; i < tops.size(); i++) {
                face[tops[i]]++;
                if(bottoms[i] != tops[i]) face[bottoms[i]]++;
            }
    
            // for each possible face from 1...6
            for(int x = 1; x <= 6; x++) {
                if(face[x] < tops.size()) continue;      // can't fill entire row
    
                int maintainTop = 0, maintainBottom = 0;
                bool possible = true;
    
                // count flips
                for(int i = 0; i < tops.size(); i++) {
                    if (tops[i] != x)      maintainTop++;
                    if (bottoms[i] != x)   maintainBottom++;
                }
    
                if (possible) 
                    res = min(res, min(maintainTop, maintainBottom));
            }
    
            return res == INT_MAX ? -1 : res;
        }
 };


 
