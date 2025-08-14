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
int longest=0;
  int sameNodes(TreeNode* root){
    if(root==NULL) return 0;
     int left=sameNodes(root->left);
     int right=sameNodes(root->right);
     int leftCount=0,rightCount=0;
     if(root->left&&root->left->val==root->val) leftCount=left+1;
     if(root->right&&root->right->val==root->val) rightCount=right+1;
     longest=max(longest,leftCount+rightCount);
     return max(leftCount,rightCount);


  }
    int longestUnivaluePath(TreeNode* root) {
        sameNodes(root);
        return longest;
    }
};