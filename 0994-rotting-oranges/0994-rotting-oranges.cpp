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
                  q.push({{i,j},0});
                  vis[i][j]=2;
                }
                else
                vis[i][j]=0;
            }
        }
        int tm=0,cnt=0;
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
         while(!q.empty()){
         auto it=q.front();
         int row=it.first.first;
         int col=it.first.second;
         int t=it.second;
         tm=max(t,tm);
         q.pop();
         for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1&&vis[nr][nc]!=2){
                q.push({{nr,nc},t+1});
                vis[nr][nc]=2;
            }
         }

         }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1&&vis[i][j]!=2)
            return -1;
        }
     }
     return tm;
    }
};