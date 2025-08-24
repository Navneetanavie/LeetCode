class Solution {
    vector<int>dp;
private:
int solve(vector<int>&nums,int ind){
    if(ind==0) return nums[ind];
    if(ind<0) return 0;
    if(dp[ind]!=-1) return dp[ind];
    int pick=nums[ind]+solve(nums,ind-2);
    int notpick=solve(nums,ind-1);
    dp[ind]=max(pick,notpick);
    return dp[ind];
    
}
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
     dp=vector<int>(n+1,-1);
      return solve(nums,n-1);
    }
};