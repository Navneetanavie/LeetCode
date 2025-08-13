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
void Paths(TreeNode* root, int targetSum,vector<int>&temp,vector<vector<int>>&ans){
    if(root==NULL) return;
    temp.push_back(root->val);
   if(root->left==NULL&&root->right==NULL&&targetSum==root->val) ans.push_back(temp); 
    if(root->left) Paths(root->left,targetSum-root->val,temp,ans);
    if(root->right) Paths(root->right, targetSum-root->val,temp,ans);
   temp.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        vector<vector<int>>ans;
        Paths(root,targetSum,temp,ans);
        return ans;
    }
};