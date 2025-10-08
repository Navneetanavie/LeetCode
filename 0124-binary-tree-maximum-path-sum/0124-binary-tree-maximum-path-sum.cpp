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
  unordered_map<TreeNode*, int>map;
  int maxValue=INT_MIN;
  int solve(TreeNode* root){
    if(root==NULL) return 0;
    if(map.count(root)) return map[root];

     int leftMaxPath=max(0,solve(root->left));
    int rightMaxPath=max(0,solve(root->right));

     maxValue=max(maxValue,leftMaxPath+rightMaxPath+root->val);
     
     return map[root]=root->val+max(leftMaxPath,rightMaxPath);
  }
    int maxPathSum(TreeNode* root) {
       solve(root);
       return maxValue;

    }
};