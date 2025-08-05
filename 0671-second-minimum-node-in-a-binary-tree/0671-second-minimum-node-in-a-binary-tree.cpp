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
long ans=LONG_MAX;
int min1;
void dfs(TreeNode* root){
       if(root==NULL) return;
       if(min1<root->val&&root->val<ans) ans=root->val;
        dfs(root->left);
        dfs(root->right);
       
}
    int findSecondMinimumValue(TreeNode* root) {
     min1=root->val;
     dfs(root);
     return ans<LONG_MAX?(int) ans:-1;
      
    }
};