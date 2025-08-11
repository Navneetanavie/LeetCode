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
    vector<double> averageOfLevels(TreeNode* root) {
         queue<TreeNode* >q;
        vector<double> avg;
        if(root==NULL) return avg;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
             double ans=0;
            for(int i=0;i<size;i++){
                 TreeNode* node=q.front();
                   q.pop();
                ans+=node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
             avg.push_back(ans/size);


        }
        return avg;
    }
};