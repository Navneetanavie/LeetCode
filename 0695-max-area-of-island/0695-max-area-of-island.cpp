class Solution {
public:
  void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis,int &cnt,int delrow[],int delcol[]){
    
     vis[row][col]=1;
      cnt++;
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
     if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&grid[nrow][ncol]==1)
     dfs(nrow,ncol,grid,vis,cnt,delrow,delcol);
        
    }
     
  }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                if(!vis[i][j]&&grid[i][j]==1){
                    dfs(i,j,grid,vis,cnt,delrow,delcol);
                   maxi=max(cnt,maxi);
                }
            }
        }
        return maxi;
    }
};