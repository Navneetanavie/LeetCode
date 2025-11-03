class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n=numCourses;
        vector<vector<int>>adj(n);
        for(auto it:prerequisites){
           adj[it[0]].push_back(it[1]);
        }
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
        for(auto it:adj[i]){
           indegree[it]++;
          }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        vector<vector<bool>>dp(n,vector<bool>(n,false));

        while(!q.empty()){
            int u=q.front();
            q.pop();
            
            for(auto &v:adj[u]){
                dp[u][v]=true;
                for(int i=0;i<n;i++){
                    if(dp[i][u]) dp[i][v]=true;
                }
                if(--indegree[v]==0) q.push(v);
            } 
        }
        vector<bool>ans;
       for(auto &it:queries){
          ans.push_back(dp[it[0]][it[1]]);
       }
       return ans;
    }
};