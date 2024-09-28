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


-- -- -- -- -- -- -- -- -- -- -- -- -- -letcode - POTD - 29 / 09 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

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



class MyCircularDeque {
public:
     vector<int> v;
    int front, back, sizee, capacity;

    MyCircularDeque(int k) {
         v = vector<int>(k, -1);
        front = 0;
        back = 0;
        sizee = 0; // Keeps track of the current number of elements
        capacity = k;
    }
    
    bool insertFront(int value) {
         if (isFull()) {
            return false;
        }

        // Way - 01
        if (front == 0) {
            front = capacity - 1; // Wrap around to the end
        } 
        else {
            front--; // Simply decrement front
        }

        // Way  - 02
        // front--;
        // front = capacity + front;
        // front %= capacity;

        v[front] = value;

        sizee++;
        return true;
    }
    
    bool insertLast(int value) {
         if (isFull()) {
            return false;
        }

        v[back] = value;

        // Way - 01
        if (back == capacity - 1) {
            back = 0; // Wrap around to the beginning
        } 
        else {
            back++; // Simply increment back
        }

        // Way - 02
        // back++;
        // back %= capacity;

        sizee++;
        return true;
    }
    
    bool deleteFront() {
         if (isEmpty()) {
            return false;
        }

        v[front] = -1;

        // Way - 01
        if (front == capacity - 1) {
            front = 0; // Wrap around to the beginning
        } 
        else {
            front++; // Simply increment front
        }
        
        // Way - 02
        // front++;
        // front %= capacity;

        sizee--;
        return true;
    }
    
    bool deleteLast() {
            if (isEmpty()) {
            return false;
        }

        if (back == 0) {
            back = capacity - 1; // Wrap around to the end
        } 
        else 
        {
            back--; // Simply decrement back
        }
        v[back] = -1;
        
        sizee--;
        return true;
    }
    
    int getFront() {
        if (isEmpty()){return -1;}
        return v[front];
    }
    
    int getRear() {
         if (isEmpty()){return -1;} 
        if (back == 0) {
            return v[capacity - 1]; // Wrap around to the last valid element
        } 
        else {
            return v[back - 1]; // Get the last element
        }
    }
    
    bool isEmpty() {
        return (sizee == 0);
    }
    
    bool isFull() {
        return (sizee == capacity);
    }
};