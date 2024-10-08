- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 12 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Middle of a Linked List
Difficulty: EasyAccuracy: 57.93%Submissions: 343K+Points: 2
Given the head of a linked list, the task is to find the middle. For example, the middle of 1-> 2->3->4->5 is 3. If there are two middle nodes (even count), return the second middle. For example, middle of 1->2->3->4->5->6 is 4.

Examples:

Input: Linked list: 1->2->3->4->5
Output: 3

Explanation: The given linked list is 1->2->3->4->5 and its middle is 3.
Input: Linked list: 2->4->6->7->5->1
Output: 7 

Explanation: The given linked list is 2->4->6->7->5->1 and its middle is 7.
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= no. of nodes <= 105


class Solution {
  public:
    /* Should return data of middle node. If linked list is empty, then -1 */
    int getMiddle(Node* head) {
        Node* slow=head;
        Node*fast=head;
        int count=0;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow->data;
    }
};


- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 12 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

1684. Count the Number of Consistent Strings
Solved
Easy
Topics
Companies
Hint
You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.
Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.
Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.
 

Constraints:

1 <= words.length <= 104
1 <= allowed.length <= 26
1 <= words[i].length <= 10
The characters in allowed are distinct.
words[i] and allowed contain only lowercase English letters.


class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[26] = {0};
        for (char c : allowed) {
            arr[c - 'a'] = 1;
        }
        
        int count = 0;
        for (string word : words) {
            int flag = 1;
            for (char c : word) {
                if (arr[c - 'a'] == 0) {
                    flag = 0;
                    break;
                }
            }
            count += flag;
        }
        return count;
    }
};