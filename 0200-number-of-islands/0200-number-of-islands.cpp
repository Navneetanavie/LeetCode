class Solution {
public:
void dfs(int row,int col, int n, int m, vector<vector<int>>&vis, vector<vector<char>>& grid){
    vis[row][col]=1;
    int dr[]={-1,1,0,0};
    int dc[]={0,0,1,-1};
    for(int i=0;i<4;i++){
        int nr=dr[i]+row;
        int nc=dc[i]+col;
        if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]&&grid[nr][nc]=='1')
          dfs(nr,nc,n,m,vis,grid);
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    cnt++;
                    dfs(i,j,n,m,vis,grid);
                }
            }
        }
        return cnt;
    }
};