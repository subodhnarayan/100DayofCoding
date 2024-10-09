-- -- -- -- -- -- -- -- -- -- -- -- -- -GFG - POTD - 10 / 10 / 2024 -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --


struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/

// function must return the pointer to the first element of the in linked list i.e. that
// should be the element at arr[0][0]
class Solution {
  public:
    Node* constructLinkedMatrix(vector<vector<int>>& mat) {
        // 
        // int row=mat.size();
        // int col=mat[0].size();
        // Node tem=new Node(0);
        // Node* rt=NULL,dn=NULL;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         Node* temp=new Node(mat[i][j]);
                
        //     }
        // }
        
        // //when i am solving this problem i am getting issue like how to set the right and down  link
        Node *ans, *prev;
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; i++) {
            Node *curH = new Node(mat[i][0]);
            Node *iter = curH;
            if (i == 0)
                ans = curH;
            for (int j = 1; j < m; j++) {
                Node *newNode = new Node(mat[i][j]);
                iter -> right = newNode;
                iter = iter -> right;
            }
            iter = curH;
            if (i != 0) {
                while (prev && iter) {
                    prev -> down = iter;
                    prev = prev -> right;
                    iter = iter -> right;
                }
            }
            prev = curH;
        }
        return ans;
    }
};