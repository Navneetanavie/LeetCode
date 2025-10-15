class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                      vis[i][j]=2;
                      q.push({{i,j},0});
                }
            }
        }
            int maximumTime=0;
            int dr[]={0,1,0,-1};
            int dc[]={1,0,-1,0};
          while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int tm=q.front().second;
            maximumTime=max(tm,maximumTime);
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]==0&&grid[nr][nc]==1){
                    vis[nr][nc]=2;
                    q.push({{nr,nc},tm+1});
                }
             }
          }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==1&&vis[i][j]!=2)
               return -1;
            }
         }
         return maximumTime;
    }
};