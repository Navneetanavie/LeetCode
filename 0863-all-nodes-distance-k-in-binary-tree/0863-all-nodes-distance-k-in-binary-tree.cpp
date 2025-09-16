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
    unordered_map<int, vector<int>> adj;

    void constructGraph(TreeNode* root) {
        if (!root) return;
        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        constructGraph(root->left);
        constructGraph(root->right);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        constructGraph(root);

        queue<int> q;
        q.push(target->val);
        unordered_set<int> vis;
        vis.insert(target->val);
        vector<int> res;

        int dist = 0;
        while (!q.empty()) {
            int levelSize = q.size();
            if (dist == k) {
                while (!q.empty()) {
                    res.push_back(q.front());
                    q.pop();
                }
                return res;
            }

            for (int i = 0; i < levelSize; i++) {
                int node = q.front();
                q.pop();

                for (auto neighbor : adj[node]) {
                    if (!vis.count(neighbor)) {
                        vis.insert(neighbor);
                        q.push(neighbor);
                    }
                }
            }
            dist++;
        }
        return res;
    }
};
