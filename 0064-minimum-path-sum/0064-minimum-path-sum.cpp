#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
class Solution {
    private:
    int solve(int i,int j,vector<vector<int>>&grid){
        if(i<0||j<0)
        return 1e9;
        if(i==0&&j==0)
        return grid[0][0];
        if(dp[i][j]!=-1)
        return dp[i][j];
        dp[i][j]=min(grid[i][j]+solve(i,j-1,grid),grid[i][j]+solve(i-1,j,grid));
        return dp[i][j];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
       return solve(n-1,m-1,grid);
    }
};