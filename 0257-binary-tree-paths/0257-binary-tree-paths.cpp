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
  void Paths(TreeNode* root, string temp, vector<string>&ans){
       temp+=to_string(root->val);
       if(root->left)  Paths(root->left,temp+"->",ans);
       if(root->right) Paths(root->right,temp+"->",ans);
       if(!root->left&&!root->right) ans.push_back(temp);

  }
    vector<string> binaryTreePaths(TreeNode* root) {
      
       vector<string>ans;
       if(root) Paths(root,"",ans);
        return ans;
        
    }
};