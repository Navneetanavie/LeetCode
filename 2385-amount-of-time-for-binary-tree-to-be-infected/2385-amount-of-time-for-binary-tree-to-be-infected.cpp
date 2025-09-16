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
unordered_map<int, vector<int>>adj;
    int amountOfTime(TreeNode* root, int start) {
        constructGraph(root);

        queue<int>q;
        q.push(start);

        unordered_set<int>vis;

        int cnt=-1;

        while(!q.empty()){
            cnt++;
            for(int i=q.size();i>0;i--){
             int node=q.front();
              q.pop();
             vis.insert(node);
             for(auto it:adj[node]){
                if(!vis.count(it)){
                    q.push(it);
                }
              } 
            }
        }
           return cnt;
    }
    void constructGraph(TreeNode* root){
        if(root==NULL) return;
        if(root->left){
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if(root->right){
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        constructGraph(root->left);
        constructGraph(root->right);

    }
};