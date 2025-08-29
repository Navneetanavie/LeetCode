class Solution {
public:
vector<vector<int>>dp;
int solve(int i, int j,vector<vector<int>>& grid, vector<vector<int>>& moveCost,int m, int n){
     if(i==m-1) return grid[i][j];
     if(dp[i][j]!=-1) return dp[i][j];
     int ans=INT_MAX;
     for(int k=0;k<n;k++){
      ans=min(ans,moveCost[grid[i][j]][k]+grid[i][j]+solve(i+1,k,grid,moveCost,m,n));
     }
     return dp[i][j]=ans;
}
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m=grid.size();
        int n=grid[0].size();
        dp=vector<vector<int>>(m,vector<int>(n,-1));
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
          ans=min(ans,solve(0,j,grid,moveCost,m,n));
        }
        return ans;
    }
};