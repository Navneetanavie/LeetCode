#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
class Solution {
    private:
    int solve(int i,int j){
        if(i==0&&j==0) return 1;
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up=solve(i-1,j);
        int left=solve(i,j-1);
         dp[i][j]=up+left;
        return dp[i][j];
    }
public:
    int uniquePaths(int m, int n) {
      dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
      return solve(n-1,m-1);
    }
};