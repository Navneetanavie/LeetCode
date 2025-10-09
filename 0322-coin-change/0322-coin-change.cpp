class Solution {
    vector<vector<int>>dp;
    private:
    int solve(vector<int>&coins,int ind,int t){
        
        if(ind==0) {
              if(t%coins[0]==0)
              return t/coins[0];
              return 1e9;
        }
        if(dp[ind][t]!=-1) return dp[ind][t];
         int notpick=solve(coins,ind-1,t);
         int pick=1e9;
         if(coins[ind]<=t)
         pick=1+solve(coins,ind,t-coins[ind]);
         return dp[ind][t]=min(pick,notpick);  

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp=vector<vector<int>>(n,vector<int>(amount+1,-1));
        int ans=0;
        ans= solve(coins,n-1,amount);
        if(ans==1e9) return -1;
         else return ans;
    }
};