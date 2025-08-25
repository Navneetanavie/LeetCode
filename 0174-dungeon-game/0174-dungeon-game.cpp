class Solution {
public:
vector<vector<int>>dp;

int solve(vector<vector<int>>& dungeon, int i,int j){
    int m=dungeon.size();
     int n=dungeon[0].size();
    if(i==m-1&&j==n-1) return max(1,1-dungeon[i][j]);
    if(i>=m||j>=n) return 1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    int total=min(solve(dungeon,i+1,j),solve(dungeon,i,j+1))-dungeon[i][j];
    return dp[i][j]=max(1,total);
}
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        dp=vector<vector<int>>(m,vector<int>(n,-1));
        return solve(dungeon,0,0);
        
    }
};