class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        q.push(1);
        vector<int>vis(n+1,0);
        vis[1]=1;
        vector<double>prob(n+1,0);
        prob[1]=1.0;
        while(!q.empty()&&t--){
             int size=q.size();
             for(int i=0;i<size;i++){
                int node=q.front();
                q.pop();
                int child_cnt=0;
                for(auto it:adj[node]){
                    if(!vis[it])
                    child_cnt++;
                }
                for(auto it:adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                        prob[it]=prob[node]/child_cnt;
                    }
                }
                if(child_cnt>0) prob[node]=0;

             }
        }
      return prob[target];
    }
};