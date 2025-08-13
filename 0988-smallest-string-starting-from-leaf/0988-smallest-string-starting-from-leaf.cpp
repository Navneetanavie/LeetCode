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
   void lexographicallySmall(TreeNode* root, string temp,vector<string>&ans){
     temp+=char('a'+root->val);
     if(root->left) lexographicallySmall(root->left,temp,ans);
     if(root->right) lexographicallySmall(root->right, temp,ans);
     if(!root->left&&!root->right){
        reverse(temp.begin(),temp.end());
        ans.push_back(temp);
     }

   }
    string smallestFromLeaf(TreeNode* root) {
        vector<string>ans;
        lexographicallySmall(root,"",ans);
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};