// POTD 3/7/2024
//  Remove all occurences of duplicates in a linked list
//  Difficulty: MediumAccuracy: 49.82%Submissions: 30K+Points: 4
//  Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list.

// Examples:

// Input: Linked List = 23->28->28->35->49->49->53->53
// Output: 23 35
// Explanation:

// The duplicate numbers are 28, 49 and 53 which are removed from the list.
// Input: Linked List = 11->11->11->11->75->75
// Output: Empty list
// Explanation:

// All the nodes in the linked list have duplicates. Hence the resultant list would be empty.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)
// Constraints:
// 1 ≤ size(list) ≤ 105

class Solution
{
public:
    Node *removeAllDuplicates(struct Node *head)
    {

        // Node *node=new Node(-1);
        // Node *curr=node;
        // int prev=-1;
        // while(head->next!=NULL){
        //     if(head->data!=head->next->data && head->data!=prev){
        //         curr->next=new Node(head->data);
        //         curr=curr->next;
        //     }
        //     prev=head->data;
        //     head=head->next;
        // }
        // if(prev!=head->data){
        //     curr->next=new Node(head->data);
        // }
        // return node->next;   TC=O(N) && SC=O(N)

        // optimized solution

        Node *node = new Node(-1);
        node->next = head;
        Node *curr = head;
        Node *prev = node;

        while (curr)
        {
            bool dupli = false;
            while (curr->next && curr->next->data == curr->data)
            {
                dupli = true;
                curr = curr->next;
            }

            if (dupli)
            {
                prev->next = curr->next;
            }
            else
            {
                prev = curr;
            }

            curr = curr->next;
        }

        Node *result = node->next;
        delete node;
        return result;
    }
};

// LeetCOde POTD 3/7/2024
//  1509. Minimum Difference Between Largest and Smallest Value in Three Moves
//  Solved
//  Medium
//  Topics
//  Companies
//  Hint
//  You are given an integer array nums.

// In one move, you can choose one element of nums and change it to any value.

// Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

// Example 1:

// Input: nums = [5,3,2,4]
// Output: 0
// Explanation: We can make at most 3 moves.
// In the first move, change 2 to 3. nums becomes [5,3,3,4].
// In the second move, change 4 to 3. nums becomes [5,3,3,3].
// In the third move, change 5 to 3. nums becomes [3,3,3,3].
// After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.
// Example 2:

// Input: nums = [1,5,0,10,14]
// Output: 1
// Explanation: We can make at most 3 moves.
// In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
// In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
// In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
// After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
// It can be shown that there is no way to make the difference 0 in 3 moves.
// Example 3:

// Input: nums = [3,100,20]
// Output: 0
// Explanation: We can make at most 3 moves.
// In the first move, change 100 to 7. nums becomes [3,7,20].
// In the second move, change 20 to 7. nums becomes [3,7,7].
// In the third move, change 3 to 7. nums becomes [7,7,7].
// After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

// class Solution {
//   public:
//     Node* removeAllDuplicates(struct Node* head) {

//         // Node *node=new Node(-1);
//         // Node *curr=node;
//         // int prev=-1;
//         // while(head->next!=NULL){
//         //     if(head->data!=head->next->data && head->data!=prev){
//         //         curr->next=new Node(head->data);
//         //         curr=curr->next;
//         //     }
//         //     prev=head->data;
//         //     head=head->next;
//         // }
//         // if(prev!=head->data){
//         //     curr->next=new Node(head->data);
//         // }
//         // return node->next;   TC=O(N) && SC=O(N)

//         //optimized solution

//         Node *node=new Node(-1);
//         node->next=head;
//         Node* curr=head;
//         Node* prev=node;

//         while(curr){
//             bool dupli=false;
//             while(curr->next && curr->next->data==curr->data){
//                 dupli=true;
//                 curr=curr->next;
//             }

//             if(dupli){
//                 prev->next=curr->next;
//             }
//             else{
//                 prev=curr;
//             }

//             curr=curr->next;
//         }

//         Node *result=node->next;
//         delete node;
//         return result;

//     }
// };

// Leetcode POTD 3/7/2024

// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given an integer array nums.

// In one move, you can choose one element of nums and change it to any value.

// Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

// Example 1:

// Input: nums = [5,3,2,4]
// Output: 0
// Explanation: We can make at most 3 moves.
// In the first move, change 2 to 3. nums becomes [5,3,3,4].
// In the second move, change 4 to 3. nums becomes [5,3,3,3].
// In the third move, change 5 to 3. nums becomes [3,3,3,3].
// After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.
// Example 2:

// Input: nums = [1,5,0,10,14]
// Output: 1
// Explanation: We can make at most 3 moves.
// In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
// In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
// In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
// After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
// It can be shown that there is no way to make the difference 0 in 3 moves.
// Example 3:

// Input: nums = [3,100,20]
// Output: 0
// Explanation: We can make at most 3 moves.
// In the first move, change 100 to 7. nums becomes [3,7,20].
// In the second move, change 20 to 7. nums becomes [3,7,7].
// In the third move, change 3 to 7. nums becomes [7,7,7].
// After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (n <= 4)
            return 0;
        int minv = INT_MAX;
        minv = min(nums[n - 4] - nums[0], minv);
        minv = min(nums[n - 1] - nums[3], minv);
        minv = min(nums[n - 3] - nums[1], minv);
        minv = min(nums[n - 2] - nums[2], minv);
        return minv;
    }
};