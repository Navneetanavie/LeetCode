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
priority_queue<int,vector<int>,greater<int>>pq;
int perfectBT(TreeNode* root, int k){
    if(root==NULL) return 0;
    int lh=perfectBT(root->left,k);
    int rh=perfectBT(root->right,k);
    if(lh==-1||rh==-1||lh!=rh) return -1;
      pq.push(1+lh+rh);
      while(pq.size()>k) pq.pop();
     return 1+lh+rh;

}
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
       
        perfectBT(root,k);
        if(pq.size()<k) return -1;
        return pq.top();
    }
};