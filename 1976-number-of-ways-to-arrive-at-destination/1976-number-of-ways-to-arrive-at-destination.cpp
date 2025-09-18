class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         vector<vector<pair<int,int>>>adj(n);
    
        for(auto &it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        const int MOD=1e9+7;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<> >pq;
        pq.push({0,0});

        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        dist[0]=0;
        ways[0]=1;


        while(!pq.empty()){
          auto [dis,node]=pq.top();
          pq.pop();
          for(auto &[adjNode,edWt]:adj[node]){
            if(dis+edWt<dist[adjNode]){
                dist[adjNode]=dis+edWt;
                ways[adjNode]=ways[node];
                pq.push({dist[adjNode],adjNode});
            }
            else if(dis+edWt==dist[adjNode])
            ways[adjNode]=(ways[adjNode]+ways[node])%MOD;
          }

        }
       return ways[n-1]%MOD;
    }
};