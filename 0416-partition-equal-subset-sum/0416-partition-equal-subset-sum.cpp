class Solution {
vector<vector<int>>dp;
private:
bool solve(vector<int>&nums,int ind,int sum){
    
    if(sum==0) return true;
    if(ind==0) return nums[ind]==sum;
    if(dp[ind][sum]!=-1) return dp[ind][sum];
    bool notpick=solve(nums,ind-1,sum);
    bool pick=false;
    if(nums[ind]<=sum) pick=solve(nums,ind-1,sum-nums[ind]);
    return dp[ind][sum]=(pick||notpick);
}
public:
    bool canPartition(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        sum+=nums[i];
       
    if(sum%2==1) return false;
     else {
        int target=sum/2;
       dp=vector<vector<int>>(n+1,vector<int>(target+1,-1));
       return solve(nums,n-1,target);
     }  
    }
};