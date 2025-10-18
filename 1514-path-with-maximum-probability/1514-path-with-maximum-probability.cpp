class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int,double>>adj[n+1];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
             adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>dist(n+1,0.0);
        pq.push({1.0,start_node});
        dist[start_node]=1.0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            double prob=it.first;
            int node=it.second;
            for(auto it:adj[node]){
                double adjProb=it.second;
                int adjNode=it.first;
                double newProb=prob*adjProb;
                if(dist[adjNode]<newProb){
                    dist[adjNode]=newProb;
                    pq.push({dist[adjNode],adjNode});
                }

            }
        }
       
        return dist[end_node];
    }
};