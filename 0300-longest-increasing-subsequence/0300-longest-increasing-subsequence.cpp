class Solution {
public:
vector<int>dp;
int solve(int n,vector<int>&nums){ 
   if(dp[n]!=-1) return dp[n];
   int ans=1;
   for(int i=0;i<n;i++){
    if(nums[i]<nums[n])
      ans=max(ans,1+solve(i,nums));
   }
   return dp[n]=ans;
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp=vector<int>(n+1,-1);
        int ans=0;
        for(int i=0;i<n;i++){
         ans=max(ans,solve(i,nums));
        }
      return ans;
    }
};