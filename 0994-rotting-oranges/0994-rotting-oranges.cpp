class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
       // vector<vector<int>>vis=grid;
        int countFreshOranges=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) countFreshOranges++;
            }
        }
        int dr[]={0,0,1,-1};
        int dc[]={1,-1,0,0};
        int minutes=-1;
        while(!q.empty()){
          int size=q.size();
          while(size--){
            auto it=q.front();
            int row=it.first;
            int col=it.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&grid[nr][nc]==1){
                    grid[nr][nc]=2;
                    q.push({nr,nc});
                    countFreshOranges--;
                }
            }
               
          }
          minutes++;
          
        }

        if(countFreshOranges>0) return -1;
        if(minutes==-1) return 0;
        return minutes;
    }
};