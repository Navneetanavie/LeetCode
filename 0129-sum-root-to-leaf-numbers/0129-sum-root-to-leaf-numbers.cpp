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
int sum=0;
  void allNumbers(TreeNode* node,int path){
    if(node==NULL) return ;
    path=path*10+node->val;
    if(node->left==NULL&&node->right==NULL) sum+=path;
    allNumbers(node->left,path);
    allNumbers(node->right,path);

  }

    int sumNumbers(TreeNode* root) {
       allNumbers(root,0);
       return sum; 
    }
};