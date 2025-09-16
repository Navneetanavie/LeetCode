/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        constructGraph(root);

        queue<int>q;
        q.push(target->val);

        unordered_set<int>vis;
        vis.insert(target->val);

        vector<int>res;

        int dis=0;
        while(!q.empty()){
            int size=q.size();
            if(dis==k){
                while(!q.empty()){
                    res.push_back(q.front());
                    q.pop();
                }
                return res;
            }
         for(int i=0;i<size;i++){
            int node=q.front();
            q.pop();
           
            for(auto it:adj[node]){
                if(!vis.count(it)){
                    q.push(it);
                     vis.insert(it);
                }
            }
         }
         dis++;
      }
      return res;
 } 

    void constructGraph(TreeNode* root){
        if(!root) return;
        if(root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        constructGraph(root->left);
        constructGraph(root->right);
    }
};