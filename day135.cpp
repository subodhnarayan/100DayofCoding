- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 15 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Binary Tree to DLL
Difficulty: HardAccuracy: 53.36%Submissions: 152K+Points: 8
Given a Binary Tree (BT), convert it to a Doubly Linked List (DLL) in place. The left and right pointers in nodes will be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be the same as the order of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

Note: h is the tree's height, and this space is used implicitly for the recursion stack.

TreeToList

Examples:

Input:
      1
    /  \
   3    2
Output:
3 1 2 
2 1 3

Explanation: DLL would be 3<=>1<=>2
Input:
       10
      /   \
     20   30
   /   \
  40   60
Output:
40 20 60 10 30 
30 10 60 20 40

Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.
Expected Time Complexity: O(no. of nodes)
Expected Space Complexity: O(height of the tree)

Constraints:
1 ≤ Number of nodes ≤ 105
0 ≤ Data of a node ≤ 105


class Solution {
  public:
    void inorder(Node* root,vector<int> &ans){
        if(root==NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
        
    }
    Node* bToDLL(Node* root) {
       vector<int> ans;
       inorder(root,ans);
       Node* head=new Node(ans[0]);
       Node* curr=head;
       int n=ans.size();
       for(int i=1;i<n;i++){
          Node* newnode=new Node(ans[i]);
          curr->right=newnode;
          newnode->left=curr;
          curr=newnode;
       }
       return head;
    }
};



- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 15 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --



1371. Find the Longest Substring Containing Vowels in Even Counts
Solved
Medium
Topics
Companies
Hint
Given the string s, return the size of the longest substring containing each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.

 

Example 1:

Input: s = "eleetminicoworoep"
Output: 13
Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
Example 2:

Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.
Example 3:

Input: s = "bcbcbc"
Output: 6
Explanation: In this case, the given string "bcbcbc" is the longest because all vowels: a, e, i, o and u appear zero times.
 

Constraints:

1 <= s.length <= 5 x 10^5
s contains only lowercase English letters.





class Solution {
public:
    // bool checkevenvowel(string str){
    //     int ac=0,ec=0,ic=0,oc=0,uc=0;
    //     for(int i=0;i<str.size();i++){
    //         if(str[i]=='a'){
    //             ac++;
    //         }
    //         else if(str[i]=='e'){
    //             ec++;
    //         }
    //         else if(str[i]=='i'){
    //             ic++;
    //         }
    //         else if(str[i]=='o'){
    //             oc++;
    //         }
    //         else if(str[i]=='u'){
    //             uc++;
    //         }
    //     }
        
    //     if(ac%2!=0){
    //         return false;
    //     }
    //     if(ec%2!=0){
    //         return false;
    //     }
    //     if(ic%2!=0){
    //         return false;
    //     }
    //     if(o%2!=0){
    //         return false;
    //     }
    //     if(u%2!=0){
    //         return false;
    //     }
    //     return true;

    // }
        return ans;
      vector<int> mapy(32, -2);
        mapy[0] = -1;

        int maxLen = 0;
        int mask = 0;

        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];

            switch (ch) {
                case 'a':
                    mask ^= 1;
                    break;
                case 'e':
                    mask ^= 2;
                    break;
                case 'i':
                    mask ^= 4;
                    break;
                case 'o':
                    mask ^= 8;
                    break;
                case 'u':
                    mask ^= 16;
                    break;
            }

            int prev = mapy[mask];
            if (prev == -2) {
                mapy[mask] = i;
            } else {
                maxLen = max(maxLen, i - prev);
            }
        }

        return maxLen;
    }
};