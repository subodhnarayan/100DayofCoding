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