-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 29 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --
Quick Sort on Linked List
Difficulty: MediumAccuracy: 71.8%Submissions: 30K+Points: 4
You are given a Linked List. Sort the given Linked List using quicksort. 

Examples:

Input: Linked list: 1->6->2
Output: 1->2->6

Explanation:
After sorting the nodes, we have 1, 2 and 6.
Input: Linked list: 1->9->3->8
Output: 1->3->8->9

Explanation:
After sorting the nodes, we have 1, 3, 8 and 9. 
Constraints:
1<= size of linked list <= 105


class Solution {
  public:
   struct Node* Partition(struct Node* head,struct Node* last){
       struct Node* i=head;
       struct Node* j=head->next;
       while(j!=last){
           if(j->data<head->data){
               i=i->next;
               swap(i->data,j->data);
           }
           j=j->next;
       }
       swap(i->data,head->data);
       return i;
       
   }
   
   void QuickSort(struct Node* head,struct Node* last){
       if(head==last || head->next==last){
           return;
       }
       struct Node* p=Partition(head,last);
       QuickSort(head,p);
       QuickSort(p->next,last);
   }
    struct Node* quickSort(struct Node* head) {
        QuickSort(head,NULL);
        return head;
    }
};


-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -Leetcode - POTD - 29 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


2684. Maximum Number of Moves in a Grid
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed m x n matrix grid consisting of positive integers.

You can start at any cell in the first column of the matrix, and traverse the grid in the following way:

From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
Return the maximum number of moves that you can perform.

 

Example 1:


Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
Output: 3
Explanation: We can start at the cell (0, 0) and make the following moves:
- (0, 0) -> (0, 1).
- (0, 1) -> (1, 2).
- (1, 2) -> (2, 3).
It can be shown that it is the maximum number of moves that can be made.
Example 2:


Input: grid = [[3,2,4],[2,1,9],[1,1,7]]
Output: 0
Explanation: Starting from any cell in the first column we cannot perform any moves.
 

Constraints:

m == grid.length
n == grid[i].length
2 <= m, n <= 1000
4 <= m * n <= 105
1 <= grid[i][j] <= 106


class Solution {
public:
    int m,n;
    vector<int> dirs={-1,0,1};

    int dfs(int row,int col,vector<vector<int>> &gr,vector<vector<int>> &dp){

        if(dp[row][col]!=-1){
            return dp[row][col];
        }
       int move=0;
       for(int dir:dirs){
        int newrow=row+dir;
        int newcol=col+1;

        if(newrow>=0 && newrow<m && newcol<n && gr[newrow][newcol]>gr[row][col]){
            move=max(move,1+dfs(newrow,newcol,gr,dp));
        }
        
       }
       return dp[row][col]=move;
    }
    
    int maxMoves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        for(int i=0;i<m;i++){
            ans=max(ans,dfs(i,0,grid,dp));
        }
        return ans;
    }
};