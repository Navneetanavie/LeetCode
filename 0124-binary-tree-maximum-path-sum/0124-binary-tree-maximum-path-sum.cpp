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
int BTMaxSum(TreeNode* root, int &pathSum){
    if(root==NULL) return 0;
    int lh=max(0,BTMaxSum(root->left,pathSum));
    int rh=max(0,BTMaxSum(root->right,pathSum));
    pathSum=max(pathSum,root->val+lh+rh);
    return max(lh,rh)+root->val;

}
    int maxPathSum(TreeNode* root) {
        
        int pathSum=INT_MIN;
        BTMaxSum(root,pathSum);
        return pathSum;
    }
};