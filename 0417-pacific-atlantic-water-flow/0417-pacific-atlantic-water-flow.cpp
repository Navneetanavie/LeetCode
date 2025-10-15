class Solution {
public:
void dfs(int row, int col,vector<vector<int>>& heights,vector<vector<int>>&vis,int m, int n){
    vis[row][col]=1;
    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nr=row+dr[i];
        int nc=col+dc[i];
        if(nr>=0&&nr<m&&nc>=0&&nc<n&&!vis[nr][nc]&&heights[nr][nc]>=heights[row][col])
          dfs(nr,nc,heights,vis,m,n);
    }
}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>pacific(m,vector<int>(n,0));
        vector<vector<int>>atlantic(m,vector<int>(n,0));
        for(int i=0;i<m;i++) dfs(i,0,heights,pacific,m,n);
        for(int j=0;j<n;j++) dfs(0,j,heights,pacific,m,n);
        for(int i=0;i<m;i++) dfs(i,n-1,heights,atlantic,m,n);
        for(int j=0;j<n;j++) dfs(m-1,j,heights,atlantic,m,n);
       
       vector<vector<int>>res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j]&&atlantic[i][j])
                  res.push_back({i,j});
            }
        }
           return res;
    }
};