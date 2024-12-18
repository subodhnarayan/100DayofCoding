-- -- -- -- -- -- -- -- -GFG - POTD - 18 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -

Allocate Minimum Pages
Difficulty: MediumAccuracy: 35.51%Submissions: 233K+Points: 4
You are given an array arr[] of integers, where each element arr[i] represents the number of pages in the ith book. You also have an integer k representing the number of students. The task is to allocate books to each student such that:

Each student receives atleast one book.
Each student is assigned a contiguous sequence of books.
No book is assigned to more than one student.
The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).

Examples:

Input: arr[] = [12, 34, 67, 90], k = 2
Output: 113
Explanation: Allocation can be done in following ways:
[12] and [34, 67, 90] Maximum Pages = 191
[12, 34] and [67, 90] Maximum Pages = 157
[12, 34, 67] and [90] Maximum Pages = 113.
Therefore, the minimum of these cases is 113, which is selected as the output.
Input: arr[] = [15, 17, 20], k = 5
Output: -1
Explanation: Allocation can not be done.
Input: arr[] = [22, 23, 67], k = 1
Output: 112
Constraints:
1 <=  arr.size() <= 106
1 <= arr[i] <= 103
1 <= k <= 10


Time Complexity: O(n log n)Auxiliary Space: O(1)


//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int N=arr.size();
        int M=k;
        if(M>N)
        return -1;
        int start=0,end=0,ans,mid;
        for(int i=0;i<N;i++)
        {
            start=max(arr[i],start);
            end=end+arr[i];
        }
        while(start<=end)
        {
            mid=start+(end-start)/2;
            int count=1;
            int page=0;
            for(int i=0;i<N;i++)
            {
                page=page+arr[i];
                if(page>mid)
                {
                    count++;
                    page=arr[i];
                }
            }
            if(count<=M)
            {
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends


-- -- -- -- -- -- -- -- -Leetcode - POTD - 18 / 12 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -


