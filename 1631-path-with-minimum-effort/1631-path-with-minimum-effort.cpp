class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int dr[]={0,0,1,-1};
        int dc[]={1,-1,0,0};
        while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int diff=it.first;
        int r=it.second.first;
        int c=it.second.second;
         if(r==n-1&&c==m-1) return diff;
          for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m){
            int new_efforts=max(abs(heights[nr][nc]-heights[r][c]),diff);
            if(new_efforts<dist[nr][nc]){
            dist[nr][nc]=new_efforts;
            pq.push({new_efforts,{nr,nc}});
            }
            }
          }
        }
        return 0;
    }
};