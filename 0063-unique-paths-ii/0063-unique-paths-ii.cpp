class Solution {
public:
vector<vector<int>>dp;
int solve(vector<vector<int>>& obstacleGrid,int m, int n){
    if(m==0&&n==0&&obstacleGrid[0][0]!=1) return 1;
    if(m<0||n<0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    if(obstacleGrid[m][n]!=1) return dp[m][n]=solve(obstacleGrid,m-1,n)+solve(obstacleGrid,m,n-1);
    else return 0;
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        dp=vector<vector<int>>(m,vector<int>(n,-1));
        return solve(obstacleGrid,m-1,n-1);
    }
};