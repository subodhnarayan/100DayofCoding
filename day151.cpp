-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 01 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Multiply two linked lists
Difficulty: EasyAccuracy: 46.33%Submissions: 74K+Points: 2
Given elements as nodes of the two singly linked lists. The task is to multiply these two linked lists, say L1 and L2.

Note: The output could be large take modulo 109+7.

Examples :

Input: LinkedList L1 : 3->2 , LinkedList L2 : 2
Output: 64
Explanation: 

Multiplication of 32 and 2 gives 64.
Input: LinkedList L1: 1->0->0 , LinkedList L2 : 1->0
Output: 1000
Explanation: 

Multiplication of 100 and 10 gives 1000.
Expected Time Complexity: O(max(n,m))
Expected Auxilliary Space: O(1)
where n is the size of L1 and m is the size of L2

Constraints:
1 <= number of nodes <= 9
0 <= node->data <= 9


class solution {
  public:
//   string mult(string a,string b){
//       string ans="";
//       int carr=0;
//       int as=a.size()-1;
//       int bs=b.size()-1;
//       while(as>=0 && bs>=0){
//           int mul=((a[as]-'0')*(b[bs]-'0'))+carr;
//               carr=mul/10;
//               ans=to_string(mul%10)+ans;
//               as--,bs--;
//       }
//       while(as>=0){
//           int mul=(a[as]-'0')+carr;
//               carr=mul/10;
//               ans=to_string(mul%10)+ans;
//               as--;
//           }

//       }
//       while(bs>=0){
//           int mul=(b[bs]-'0')+carr;
//               carr=mul/10;
//               ans=to_string(mul%10)+ans;
//               bs--;
          
//       }
//       if(carr>0){
//           ans=to_string(carr)+ans;
//       }
//       return ans;
//   }
    long long multiplyTwoLists(Node *first, Node *second) {
    //     long long fir = 0;
    // long long sec = 0;
    // int mod = 10000000;  // Use an integer, not a floating-point number

    // // Build the number from the first list
    // while (first) {
    //     fir = ((fir * 10) % mod + first->data) % mod;
    //     first = first->next;
    // }

    // // Build the number from the second list
    // while (second) {
    //     sec = ((sec * 10) % mod + second->data) % mod;
    //     second = second->next;
    // }

    // // Return the product modulo `mod`
    // return (fir * sec) % mod;
    string p1="";
        string p2="";
        while(first!=NULL){
            p1.push_back(first->data+'0');
            first=first->next;
        }
         while(second!=NULL){
            p2.push_back(second->data+'0');
            second=second->next;
        }
        long long n1=stoll(p1);
        long long n2=stoll(p2);
        return (n1*n2)%1000000007;
    }
};



1497. Check If Array Pairs Are Divisible by k
Solved
Medium
Topics
Companies
Hint
Given an array of integers arr of even length n and an integer k.

We want to divide the array into exactly n / 2 pairs such that the sum of each pair is divisible by k.

Return true If you can find a way to do that or false otherwise.

 

Example 1:

Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
Output: true
Explanation: Pairs are (1,9),(2,8),(3,7),(4,6) and (5,10).
Example 2:

Input: arr = [1,2,3,4,5,6], k = 7
Output: true
Explanation: Pairs are (1,6),(2,5) and(3,4).
Example 3:

Input: arr = [1,2,3,4,5,6], k = 10
Output: false
Explanation: You can try all possible pairs to see that there is no way to divide arr into 3 pairs each with sum divisible by 10.
 

Constraints:

arr.length == n
1 <= n <= 105
n is even.
-109 <= arr[i] <= 109
1 <= k <= 105


class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
         vector<int> freq(k, 0);
        for (int num : arr) {
            int rem = num % k;
            if (rem < 0) {
                rem += k;
            }
            freq[rem]++;
        }
        
        if (freq[0] % 2 != 0) {
            return false;
        }
        
        for (int i = 1; i <= k / 2; i++) {
            if (freq[i] != freq[k - i]) {
                return false;
            }
        }
        
        return true;
    }
};