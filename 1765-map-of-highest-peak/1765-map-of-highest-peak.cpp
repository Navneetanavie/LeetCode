class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        queue<pair<pair<int,int>,int>>q;
         int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));;
        
         vector<vector<int>>vis(n,vector<int>(m,0));
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(isWater[i][j]==1){
                q.push({{i,j},0});
                ans[i][j]=0;
               }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int height=q.front().second;
            q.pop();
            int dr[]={0,0,1,-1};
            int dc[]={1,-1,0,0};
            for(int i=0;i<4;i++){
                int nr=dr[i]+row;
                int nc=dc[i]+col;
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&isWater[nr][nc]==0&&!vis[nr][nc]){
                   vis[nr][nc]=1;
                   q.push({{nr,nc},height+1});
                   ans[nr][nc]=height+1;
                }
            }
        }
      return ans;
    }
};