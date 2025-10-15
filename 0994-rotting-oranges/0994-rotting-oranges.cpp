class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                   q.push({{i,j},0});
                }
                 
            }
        }

        int maxTm=0;
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int tm=q.front().second;
            q.pop();
            maxTm=max(tm,maxTm);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&!vis[nr][nc]&&grid[nr][nc]!=0){
                         vis[nr][nc]=2;
                         q.push({{nr,nc},tm+1});
                }
            }
        }
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1&&!vis[i][j])
            return -1;
        }
       }
      return maxTm;
    }
};