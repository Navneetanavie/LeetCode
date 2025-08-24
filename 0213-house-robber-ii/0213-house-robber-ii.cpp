#include<bits/stdc++.h>
using namespace std;
vector<int>dp;
class Solution {
    private:
    
    int solve(int ind,vector<int>&nums){
        if(ind==0)
        return nums[0];
        if(ind<0)
        return 0;
        if(dp[ind]!=-1)
        return dp[ind];
        int pick=nums[ind]+solve(ind-2,nums);
        int notpick=solve(ind-1,nums);
        dp[ind]=max(pick,notpick);
        return dp[ind];    }
public:

    int rob(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>nums1(nums.begin()+1,nums.end());
        vector<int>nums2(nums.begin(),nums.end()-1);
        if(n==1) return nums[0];
        dp=vector<int>(n,-1);
        int ans1=solve(nums1.size()-1,nums1);
        dp=vector<int>(n,-1);
        int ans2=solve(nums2.size()-1,nums2);
        return max(ans1,ans2);
    }
};