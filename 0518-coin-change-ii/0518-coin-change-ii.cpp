class Solution {
    vector<vector<int>>dp;
private:
int solve(vector<int>&coins,int ind,int d){
    if(ind==0)
    return (d%coins[ind]==0);
    if(dp[ind][d]!=-1) return dp[ind][d];
    int notpick=solve(coins,ind-1,d);
    int pick=0;
    if(coins[ind]<=d) 
    pick=solve(coins,ind,d-coins[ind]);
    return dp[ind][d]=pick+notpick;
}
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
     dp=vector<vector<int>>(n+1,vector<int>(amount+1,-1));   
     return solve(coins,n-1,amount);
    }
};