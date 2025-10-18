class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>dis(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++){
            dis[i][i]=0;
        }
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            dis[u][v]=wt;
            dis[v][u]=wt;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dis[i][k]==1e8) continue;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        int min_neighbour_cities=n+1;
        int ans=0;
       
     for(int i=0;i<n;i++){
        int k=0;
        for(int j=0;j<n;j++){
            if(dis[i][j]<=distanceThreshold)
            k++;
        }
         if(k<=min_neighbour_cities){
            min_neighbour_cities=k;
            ans=i;
         }
     }
      
            return ans;
    }
};