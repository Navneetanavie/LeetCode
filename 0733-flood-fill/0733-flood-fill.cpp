class Solution {
public:
void dfs(int row,int col,int dr[],int dc[],vector<vector<int>>& image,vector<vector<int>>&ans,int color,int inicol){
    ans[row][col]=color;
    int n=image.size();
    int m=image[0].size();
    for(int i=0;i<4;i++){
      int nr=row+dr[i];
      int nc=col+dc[i];
      if(nr>=0&&nr<n&&nc>=0&&nc<m&&ans[nr][nc]==inicol&&ans[nr][nc]!=color){
        dfs(nr,nc,dr,dc,image,ans,color,inicol);
      }
    }

 }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inicol=image[sr][sc];
        int dr[]={1,0,-1,0};
        int dc[]={0,-1,0,1};
        vector<vector<int>>ans=image;
         dfs(sr,sc,dr,dc,image,ans,color,inicol);
         return ans;

    }
};