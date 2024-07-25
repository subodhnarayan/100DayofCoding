//GFG POTD 25/7/2024

Array to BST
Difficulty: EasyAccuracy: 46.02%Submissions: 74K+Points: 2
Given a sorted array. Convert it into a Height Balanced Binary Search Tree (BST). Return the root of the BST.

Height-balanced BST means a binary tree in which the depth of the left subtree and the right subtree of every node never differ by more than 1.

Note: The driver code will check the BST, if it is a Height-balanced BST, the output will be true otherwise the output will be false.

Examples :

Input: nums = [1, 2, 3, 4]
Output: true
Explanation: The preorder traversal of the following BST formed is [2, 1, 3, 4]:
           2
         /   \
        1     3
               \
                4
Input: nums = [1, 2, 3, 4, 5, 6, 7]
Ouput: true
Explanation: The preorder traversal of the following BST formed is [4, 2, 1, 3, 6, 5, 7]:
        4
       / \
      2   6
     / \   / \
    1 3  5 7
Expected Time Complexity: O(n)
Expected Auxillary Space: O(n)

Constraints:
1 ≤ nums.size() ≤ 105
1 ≤ nums[i] ≤ 105


class Solution {
  public:
  Node* help(vector<int> & nums,int start,int end){
      if(start>end){
          return NULL;
      }
      int mid=(start+end)/2;
      Node* root=new Node(nums[mid]);
      root->left=help(nums,start,mid-1);
      root->right=help(nums,mid+1,end);
      return root;
  }
    Node* sortedArrayToBST(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        return help(nums,start,end);
    }
};

912. Sort an Array
Solved
Medium
Topics
Companies
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 

Constraints:

1 <= nums.length <= 5 * 104
-5 * 104 <= nums[i] <= 5 * 104


class Solution {
public:
    void merge(vector<int> &nums,int start,int mid,int end){
        vector<int> temp;
        int left=start;
        int right=mid+1;
        while(left<=mid && right<=end){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }
            else{
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left<=mid){
              temp.push_back(nums[left]);
            left++;
        }

        while(right<=end){
            temp.push_back(nums[right]);
                right++;
        }

        for(int i=start;i<=end;i++){
            nums[i]=temp[i-start];
        }
    }
    void Mergesort(vector<int> &nums,int start,int end){
        if(start>=end){
            return;
        }
        int mid=(start+end)/2;
        Mergesort(nums,start,mid);  //including mid
        Mergesort(nums,mid+1,end);   //excluded mid
        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int end=nums.size()-1;
        // Mergesort(nums,0,end);
        // return nums;
         vector<int> counting(2 * 50000 + 1, 0);
        for (int num : nums) {
            // we add 5 * 10^4 because for smallest possible element -5 * 10^4 index must be 0
            counting[num + 50000]++;
        }
        int write_ind = 0;
        for (int number_ind = 0; number_ind < counting.size(); ++number_ind) {
            int freq = counting[number_ind];
            while (freq != 0) {
                nums[write_ind] = number_ind - 50000;
                write_ind++;
                freq--;
            }
        }
        return nums;  tc=0(n) nd sc=0(1)
    }
};