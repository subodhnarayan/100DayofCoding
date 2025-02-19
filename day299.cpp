-- -- -- -- -- -- -- -- -GFG - POTD - 19 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -------

Merge K sorted linked lists
Difficulty: MediumAccuracy: 57.01%Submissions: 96K+Points: 4Average Time: 60m
Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, then return the head of the merged linked list.

Examples:

Input: arr[] = [1 -> 2 -> 3, 4 -> 5, 5 -> 6, 7 -> 8]
Output: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 7 -> 8
Explanation:
The arr[] has 4 sorted linked list of size 3, 2, 2, 2.
1st list: 1 -> 2-> 3
2nd list: 4 -> 5
3rd list: 5 -> 6
4th list: 7 -> 8
The merged list will be:
 
Input: arr[] = [1 -> 3, 8, 4 -> 5 -> 6]
Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
Explanation:
The arr[] has 3 sorted linked list of size 2, 3, 1.
1st list: 1 -> 3
2nd list: 8
3rd list: 4 -> 5 -> 6
The merged list will be:

Constraints
1 <= total no. of nodes <= 105
1 <= node->data <= 103


class Solution {
    public:
    
     void merge(vector<int> &res,Node* head){
         if(head==NULL) return;
         Node* curr=head;
         while(curr!=NULL){
             res.push_back(curr->data);
             curr=curr->next;
         }
         return;
     }
      Node* mergeKLists(vector<Node*>& arr) {
          
          vector<int> res;
          for(int i=0;i<arr.size();i++){
              merge(res,arr[i]);
          }
          
          sort(res.begin(),res.end());
          Node* ans=new Node(0);
          Node* ret=ans;
          for(int i=0;i<res.size();i++){
              ret->next=new Node(res[i]);
              ret=ret->next;
          }
          
          return ans->next;
      }
  };


-- -- -- -- -- -- -- -- -LeetCode - POTD - 19 / 02 / 2025 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


1415. The k-th Lexicographical String of All Happy Strings of Length n
Solved
Medium
Topics
Companies
Hint
A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

 

Example 1:

Input: n = 1, k = 3
Output: "c"
Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
Example 2:

Input: n = 1, k = 4
Output: ""
Explanation: There are only 3 happy strings of length 1.
Example 3:

Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
 

Constraints:

1 <= n <= 10
1 <= k <= 100

class Solution {
    public:
       int n2;
        string dfs(string prefix, int n, int k) {
            if (n == 0)
                return prefix;
            for (char c = 'a'; c <= 'c'; c++) {
                if (!prefix.empty() && c == prefix.back())
                    continue;
                int cnt = (1 << (n2 - prefix.length() - 1));
                if (cnt >= k)
                    return dfs(prefix + c, n - 1, k);
                else
                    k -= cnt;
            }
            return "";
        }
        string getHappyString(int n, int k) {
            n2 = n;
            return dfs("", n, k);
        }
};