// GFG 8/7/2024
//  Search in Rotated Sorted Array
//  Difficulty: MediumAccuracy: 37.64%Submissions: 216K+Points: 4
//  Given a sorted (in ascending order) and rotated array arr of distinct elements which may be rotated at some point and given an element key, the task is to find the index of the given element key in the array arr. The whole array arr is given as the range to search.

// Rotation shifts elements of the array by a certain number of positions, with elements that fall off one end reappearing at the other end.

// Note:- 0-based indexing is followed & returns -1 if the key is not present.

// Examples :

// Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 10
// Output: 5
// Explanation: 10 is found at index 5.
// Input: arr[] = [3, 5, 1, 2], key = 6
// Output: -1
// Explanation: There is no element that has value 6.
// Expected Time Complexity: O(log n)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 106
// 1 ≤ key ≤ 105

class Solution
{
public:
    int search(vector<int> &arr, int key)
    {
        // int n=arr.size();
        // for(int i=0;i<n;i++){
        //     if(arr[i]==key){
        //         return i;
        //     }
        // }
        // return -1;  TC=0(N)

        // Another approach
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == key)
            {
                return mid;
            }

            // checking left is sorted or not cheking ascending order
            if (arr[start] <= arr[mid])
            {
                // checkingt key in right half
                if (arr[start] <= key && key < arr[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            // checking right side is sorted or not  in descending order
            else
            {
                // checkingt key in right half
                if (arr[mid] < key && key <= arr[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

// Leetcode 8/7/2024

// 1823. Find the Winner of the Circular Game
// Solved
// Medium
// Topics
// Companies
// Hint
// There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, and moving clockwise from the nth friend brings you to the 1st friend.

// The rules of the game are as follows:

// Start at the 1st friend.
// Count the next k friends in the clockwise direction including the friend you started at. The counting wraps around the circle and may count some friends more than once.
// The last friend you counted leaves the circle and loses the game.
// If there is still more than one friend in the circle, go back to step 2 starting from the friend immediately clockwise of the friend who just lost and repeat.
// Else, the last friend in the circle wins the game.
// Given the number of friends, n, and an integer k, return the winner of the game.

// Example 1:

// Input: n = 5, k = 2
// Output: 3
// Explanation: Here are the steps of the game:
// 1) Start at friend 1.
// 2) Count 2 friends clockwise, which are friends 1 and 2.
// 3) Friend 2 leaves the circle. Next start is friend 3.
// 4) Count 2 friends clockwise, which are friends 3 and 4.
// 5) Friend 4 leaves the circle. Next start is friend 5.
// 6) Count 2 friends clockwise, which are friends 5 and 1.
// 7) Friend 1 leaves the circle. Next start is friend 3.
// 8) Count 2 friends clockwise, which are friends 3 and 5.
// 9) Friend 5 leaves the circle. Only friend 3 is left, so they are the winner.
// Example 2:

// Input: n = 6, k = 5
// Output: 1
// Explanation: The friends leave in this order: 5, 4, 6, 2, 3. The winner is friend 1.

// Constraints:

// 1 <= k <= n <= 500

// Follow up:

// Could you solve this problem in linear time with constant space?

class Solution
{
public:
    int findwinnerindex(int n, int k)
    {
        if (n == 1)
        {
            return 0;
        } // base case
        int idx = findwinnerindex(n - 1, k); // to find the index of the winner
        idx = (idx + k) % n;
        return idx;
    }
    int findTheWinner(int n, int k)
    {
        // vector<int> arr(n+1,1);
        // arr[0]=0;
        // int ans;
        // int start=0;
        // int K=n;
        // while(K>1){
        //    int diff=(start+k)%n;
        //    arr[diff]=-1;
        //    start=diff;
        //    K--;
        // }
        // for(int i=1;i<n+1;i++){
        //     if(arr[i]==1){
        //         return i;
        //     }
        // }
        // return 1;
        // vector<int> friends;
        // for (int i = 1; i <= n; ++i) {
        //     friends.push_back(i);
        // }

        // int index = 0;

        // while (friends.size() > 1) {
        //     // Find the index of the friend to be eliminated
        //     index = (index + k - 1) % friends.size();
        //     // Eliminate the friend
        //     friends.erase(friends.begin() + index);
        // }

        // return friends[0];  T.C=0(N2)

        // another approach using queue

        //    queue<int> q;
        //    for(int i=1;i<=n;i++){
        //     q.push(i);
        //    }

        //    while(q.size()>1){
        //     for(int i=1;i<=k-1;i++){
        //         q.push(q.front());
        //         q.pop();

        //     }
        //     q.pop();
        //    }
        //    return q.front();  TC=O(n*k)

        // Another solution with recursion with time complexity 0(N) and space complexity o(N)
        int idx = findwinnerindex(n, k);
        return idx + 1;
    }
};
