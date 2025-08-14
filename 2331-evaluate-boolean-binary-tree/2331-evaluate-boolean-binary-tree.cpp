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
bool dfs(TreeNode* root){
    if(root->val==0||root->val==1) return root->val;
     bool left=dfs(root->left);
     bool right=dfs(root->right);
     if(root->val==2)  return left|right;
      if(root->val==3)  return left&right;
      return false;

  }
    bool evaluateTree(TreeNode* root) {
       
       return dfs(root);
      
    }
};