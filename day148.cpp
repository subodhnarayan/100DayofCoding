-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 29 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

Difficulty: MediumAccuracy: 51.08%Submissions: 69K+Points: 4
There is an array arr of heights of stone and Geek is standing at the first stone and can jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be |hi-hj| is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches the last stone.

Example:

Input: k = 3, arr[]= [10, 30, 40, 50, 20]
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum
Input: k = 1, arr[]= [10, 20, 10]
Output: 20
Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.
Expected Time Complexity: O(n*k)
Expected Auxilary Space: O(n)

Constraint:
1<= arr.size() <=104
1 <= k <= 100
1 <= arr[i] <= 104

class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // int n=arr.size();
        // int ans=0;
        // for(int i=0;i<n-k;i++){
        //     int ind=i+1;
        //     int min=abs(arr[i+1]-arr[i]);
        //     for(int j=i+2;j<=k+i;j++){
        //         if(abs(arr[j]-arr[i])<=min){
        //             ind=j;
        //             min=abs(arr[j]-arr[i]);
        //         }
        //     }
        //     ans+=min;
        //     i=ind;
        //     
         int n = arr.size();
        vector<int> dp(n, INT_MAX); // dp[i] stores the minimum cost to reach stone i
        dp[0] = 0; // No cost to stay on the first stone
        
        // Iterate over each stone from the second to the last
        for (int i = 1; i < n; i++) {
            // Check all stones j that can jump to i, where j is within k steps
            for (int j = max(0, i - k); j < i; j++) {
                dp[i] = min(dp[i], dp[j] + abs(arr[i] - arr[j]));
            }
        }
        
        return dp[n - 1];
      
    }
};




641. Design Circular Deque
Solved
Medium
Topics
Companies
Design your implementation of the circular double-ended queue (deque).

Implement the MyCircularDeque class:

MyCircularDeque(int k) Initializes the deque with a maximum size of k.
boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
boolean isEmpty() Returns true if the deque is empty, or false otherwise.
boolean isFull() Returns true if the deque is full, or false otherwise.
 

Example 1:

Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 

Constraints:

1 <= k <= 1000
0 <= value <= 1000
At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.