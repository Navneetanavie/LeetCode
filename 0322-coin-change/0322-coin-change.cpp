class Solution {
public:
vector<vector<int>>dp;
int solve(int n ,int amount,vector<int>& coins){
   if(amount==0) return 0;
   if(n==0) {
    if(amount%coins[0]==0)
    return amount/coins[0];
     return 1e9;
   }
   if(dp[n][amount]!=-1) return dp[n][amount];
   int notPick=solve(n-1,amount,coins);
   int pick=1e9;
   if(coins[n]<=amount)
    pick=1+solve(n,amount-coins[n],coins);
   return dp[n][amount]=min(pick,notPick);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp=vector<vector<int>>(n,vector<int>(amount+1,-1));
        int ans=0;
        ans= solve(n-1,amount,coins);
        if(ans==1e9) return -1;
        return ans;
    }
};