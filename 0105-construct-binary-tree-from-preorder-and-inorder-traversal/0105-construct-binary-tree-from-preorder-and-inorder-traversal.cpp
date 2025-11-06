/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int idx=0;
unordered_map<int,int>mp;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++)
         mp[inorder[i]]=i;
         return solve(preorder, 0, inorder.size()-1);
    }

    TreeNode* solve(vector<int>& preorder, int start, int end){
        if(start>end) return NULL;
        int rootVal=preorder[idx++];
        TreeNode* root=new TreeNode(rootVal);
        int mid=mp[rootVal];
        root->left=solve(preorder,start, mid-1);
        root->right=solve(preorder,mid+1,end);
        return root;


    }
}; 
//preorder-> root left right
//inorder-> left root right