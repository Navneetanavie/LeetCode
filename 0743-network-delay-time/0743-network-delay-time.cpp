class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].emplace_back(it[1],it[2]);
        }
       
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
         pq.emplace(0,k);
       while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int dis=it.first;
        for(auto it: adj[node]){
            int edWt=it.second;
            int adjNode=it.first;
            if(dis+edWt<dist[adjNode]){
                dist[adjNode]=dis+edWt;
                pq.emplace(dist[adjNode],adjNode);
            }
        }
       }
       int ans=-1;
       for(int i=1;i<=n;i++){
        if(dist[i]==INT_MAX){
            return -1;
            break;
        } 
        else
        ans=max(ans,dist[i]);
       }
       return ans;
    }
};