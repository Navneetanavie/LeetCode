#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int>dp;
    private:
    int solve(int ind){
        
        if(ind<=1) return 1;
        if(dp[ind]!=-1) return dp[ind];
        int one=solve(ind-1);
        int two=solve(ind-2);
        dp[ind]=one+two;
        return dp[ind];
    }
public:
    int climbStairs(int n) {
        dp=vector<int>(n+1,-1);
        return solve(n);

    }
};