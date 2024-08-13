-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 12 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -
Sum of Middle elements of two sorted arrays
Difficulty: MediumAccuracy: 47.98%Submissions: 80K+Points: 4
Given 2 sorted integer arrays arr1 and arr2 of the same size. Find the sum of the middle elements of two sorted arrays arr1 and arr2.

Examples:

Input: arr1 = [1, 2, 4, 6, 10], arr2 = [4, 5, 6, 9, 12]
Output: 11
Explanation: The merged array looks like [1, 2, 4, 4, 5, 6, 6, 9, 10, 12]. Sum of middle elements is 11 (5 + 6).
Input: arr1 = [1, 12, 15, 26, 38], arr2 = [2, 13, 17, 30, 45]
Output: 32
Explanation: The merged array looks like [1, 2, 12, 13, 15, 17, 26, 30, 38, 45]. Sum of middle elements is 32 (15 + 17).
Expected Time Complexity: O(log n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= arr1.size() == arr2.size() <= 103
1 <= arr1[i] <= 106
1 <= arr2[i] <= 106

class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        int n1=arr1.size();
        int n2=arr2.size();
          for(int i=0; i<arr2.size(); i++){
            arr1.push_back(arr2[i]);
        }
        sort(arr1.begin(), arr1.end());
        return arr1[arr1.size()/2] + arr1[(arr1.size()/2)-1];
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- Leetcode - POTD - 12 / 08 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

703. Kth Largest Element in a Stream
Solved
Easy
Topics
Companies
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.
 

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
 

Constraints:

1 <= k <= 104
0 <= nums.length <= 104
-104 <= nums[i] <= 104
-104 <= val <= 104
At most 104 calls will be made to add.
It is guaranteed that there will be at least k elements in the array when you search for the kth element.

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int num : nums) {
            if (minHeap.size() < k) {
                minHeap.push(num);
            } else if (num > minHeap.top()) {
                minHeap.push(num);
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }
    }

    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.push(val);
            minHeap.pop();
        }
        return minHeap.top();
    }

private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Min-heap to store the k largest elements
};


