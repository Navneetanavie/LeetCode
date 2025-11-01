class Solution {
public:
  void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>&vis,int &cnt, int n, int m){
    vis[row][col]=1;
    cnt++;
    int dr[]={-1,1,0,0};
    int dc[]={0,0,1,-1};
    for(int i=0;i<4;i++){
        int nr=row+dr[i];
        int nc=col+dc[i];
        if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1&&!vis[nr][nc]){
            dfs(nr,nc,grid,vis,cnt,n,m);
        }
    }
  }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int maxArea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt=0;
                if(grid[i][j]==1&&!vis[i][j]){
                   dfs(i,j,grid,vis,cnt,n,m);
                   maxArea=max(maxArea,cnt);
                }
                 
            }
        }
        return maxArea;
    }
};