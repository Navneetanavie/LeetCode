class Solution {
public:
int dfs(int headID, vector<vector<int>>&adj, vector<int>& informTime){
    int maxi=0;
    for(auto it:adj[headID]){
        maxi=max(maxi,informTime[it]+dfs(it,adj,informTime));
    }
   return maxi;
}
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       vector<vector<int>>adj(n);
       for(int i=0;i<n;i++){
          if(manager[i]!=-1) adj[manager[i]].push_back(i);
       } 
       return dfs(headID, adj, informTime)+informTime[headID];
    }
};