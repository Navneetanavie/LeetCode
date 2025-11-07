class Solution {
public:
vector<vector<int>>dp;
bool solve(int n,vector<int>& nums, int targetSum){
    if(n==0) return nums[n]==targetSum;
    if(targetSum==0) return true;
    if(dp[n][targetSum]!=-1) return dp[n][targetSum];
    bool notpick=solve(n-1,nums,targetSum);
    bool pick=false;
    if(targetSum-nums[n]>=0)
    pick=solve(n-1,nums,targetSum-nums[n]);
    return dp[n][targetSum]=pick||notpick;
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        long long target=accumulate(nums.begin(),nums.end(),0);
        if(target%2==0) { 
        int targetSum=target/2;
        dp=vector<vector<int>>(n,vector<int>(targetSum+1,-1));
        return solve(n-1,nums,targetSum);
        }
        else return false;

    }
};