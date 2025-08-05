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
vector<int>inOrder;
  void inOrderTrav(TreeNode* root){
    if(root==NULL) return ;
    inOrderTrav(root->left);
    inOrder.push_back(root->val);
    inOrderTrav(root->right);
  }
    int kthSmallest(TreeNode* root, int k) {
       inOrderTrav(root);
       return inOrder[k-1]; 
    }
};