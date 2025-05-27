-- -- -- -- -- -- -- -- -GFG - POTD - 27 / 05 / 2025 ----------------------------------------
Print leaf nodes from preorder traversal of BST
Difficulty: MediumAccuracy: 47.26%Submissions: 34K+Points: 4
Given a preorder traversal of a BST, find the leaf nodes of the tree without building the tree.


Examples:

Input: preorder[] = [5, 2, 10]
Output: [2, 10]
Explaination: 

2 and 10 are the leaf nodes as shown in the figure.
Input: preorder[] = [4, 2, 1, 3, 6, 5]
Output: [1, 3, 5]
Explaination: 

1, 3 and 5 are the leaf nodes as shown in the figure.
Input: preorder[] = [8, 2, 5, 10, 12]
Output: [5, 12]
Explaination: 

5 and 12 are the leaf nodes as shown in the figure.

Constraints:
1 ≤ preorder.size() ≤ 103
1 ≤ preorder[i] ≤ 103

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        queue<vector<int>>q;
        q.push(preorder);
        vector<int>ans;
        while(!q.empty())
        {
            vector<int>t=q.front();
            q.pop();
            vector<int>small;
            vector<int>large;
            if(t.size()==1)
            ans.push_back(t[0]);
            else
            {
                for(int i=1;i<t.size();i++)
                {
                    if(t[i]>t[0])
                    large.push_back(t[i]);
                    else
                    small.push_back(t[i]);
                    
                }
                if(!small.empty())
                q.push(small);
                if(!large.empty())
                q.push(large);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

-- -- -- -- -- -- -- -- -Leetcode - POTD - 27 / 05 / 2025 ----------------------------------------


