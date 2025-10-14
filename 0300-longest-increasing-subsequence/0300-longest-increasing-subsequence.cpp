#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
class Solution {
private:
int solve(int ind,int prev_ind,vector<int>&nums,int n){
if(ind==n)
return 0;
if(dp[ind][prev_ind+1]!=-1)
return dp[ind][prev_ind+1];
int len=solve(ind+1,prev_ind,nums,n);
if(prev_ind==-1||nums[ind]>nums[prev_ind]){
len=max(len,1+solve(ind+1,ind,nums,n));
}
dp[ind][prev_ind+1]=len;
return dp[ind][prev_ind+1];
}
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       dp=vector<vector<int>>(n,vector<int>(n+1,-1));
      return solve(0,-1,nums,n);
    }
};