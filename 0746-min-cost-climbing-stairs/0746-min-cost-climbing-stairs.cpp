class Solution {
public:
 vector<int>dp;
 int solve(int n,vector<int>& cost){
    if(n<=1) return dp[n]=cost[n];
    if(dp[n]!=-1) return dp[n];
    return dp[n]=cost[n]+min(solve(n-1,cost),solve(n-2,cost));
 }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp=vector<int>(n+1,-1);
        return min(solve(n-1,cost),solve(n-2,cost));
    }
};