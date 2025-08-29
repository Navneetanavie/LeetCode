class Solution {
public:
int mod=1e9+7;
vector<vector<vector<int>>>dp;
int solve(int n,int m,int rem,vector<vector<int>>& grid, int k){
    if(m<0||n<0) return 0;
    rem=(rem+grid[n][m])%k;
    if(n==0&&m==0) return rem==0?1:0;
    if(dp[n][m][rem]!=-1) return dp[n][m][rem];
    return dp[n][m][rem]=(solve(n-1,m,rem,grid,k)+solve(n,m-1,rem,grid,k))%mod;
    

}
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
       dp= vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(k,-1)));
       return solve(n-1,m-1,0,grid,k);
    }
};