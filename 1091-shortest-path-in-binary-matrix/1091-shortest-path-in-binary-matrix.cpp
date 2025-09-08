class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if(grid[0][0]==1) return -1;
        if(n==1) return 1;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<pair<int,pair<int,int>>>q;
        q.push({1,{0,0}});
        dist[0][0]=1;
        int dr[]={-1,1,0,0,1,1,-1,-1};
        int dc[]={0,0,1,-1,-1,1,-1,1};
        while(!q.empty()){
            int dis=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
          if(r==n-1&&c==m-1) return dis;
            for(int i=0;i<8;i++){
              int nr=r+dr[i];
              int nc=c+dc[i];
              if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==0&&1+dis<dist[nr][nc]){
                dist[nr][nc]=1+dis;
               
                q.push({dist[nr][nc],{nr,nc}});
              }
            }

        }
        return -1;

    }
};