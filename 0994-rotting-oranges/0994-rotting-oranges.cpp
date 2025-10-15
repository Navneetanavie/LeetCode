class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis=grid;
        int countFreshOranges=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==2)
                   q.push({i,j});
                if(vis[i][j]==1)
                   countFreshOranges++;
                 
            }
        }

        int minutes=-1;
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        while(!q.empty()){
            int size=q.size();
            while(size--){
            int r=q.front().first;
            int c=q.front().second;
            
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&vis[nr][nc]==1){
                         vis[nr][nc]=2;
                         countFreshOranges--;
                         q.push({nr,nc});
                }
             }
            }
            minutes++;
        }
       
           
       
       if(countFreshOranges>0)  return -1;
         if(minutes==-1) return 0;
       return minutes;
    }
};