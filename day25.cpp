// You and your books
// EasyAccuracy: 50.0%Submissions: 30K+Points: 2
// In need of more Geekbits? Win from a pool of 3500+ Geekbits via DSA-based Coding Contest every sunday!

// banner
// You have n stacks of books. Each stack of books has some nonzero height arr[i] equal to the number of books on that stack ( considering all the books are identical and each book has a height of 1 unit ). In one move, you can select any number of consecutive stacks of books such that the height of each selected stack of books arr[i] <= k. Once such a sequence of stacks is chosen, You can collect any number of books from the chosen sequence of stacks.
// What is the maximum number of books that you can collect this way?

// Example 1

// Input
// 8 1
// 3 2 2 3 1 1 1 3
// Output
// 3
// Explanation
// We can collect maximum books from consecutive stacks numbered 5, 6, and 7 having height less than equal to K.
// Example 2

// Input
// 8 2
// 3 2 2 3 1 1 1 3
// Output
// 4
// Explanation
// We can collect maximum books from consecutive stacks numbered 2 and 3 having height less than equal to K.
// Your Task:
// You don't have to read input or print anything. Your task is to complete the function max_Books() which takes the integer arr, n, and k returns the maximum number of books you can collect.

// Expected Time Complexity: O(n)
// Expected Space Complexity: O(1)

class Solution
{
public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k)
    {
        long long sum = 0;
        int i = 0;
        while (i < n)
        {
            long long temp = 0;
            if (arr[i] <= k)
            {
                while (i < n && arr[i] <= k)
                {
                    temp += arr[i];
                    i++;
                }
                sum = max(sum, temp);
            }
            i++;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int ar[n];
        for (int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }
        Solution ob;
        cout << ob.max_Books(ar, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends