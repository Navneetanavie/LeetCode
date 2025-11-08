class Solution {
public:
vector<int>dp;
int solve(string s, int n){
    if(n==s.size()) return 1;
    if(dp[n]!=-1) return dp[n];
    int ways=0;
    if(s[n]!='0')
     ways+=solve(s,n+1);
    if(n+1<s.size()&&(s[n]=='1'||(s[n]=='2'&&s[n+1]<='6')))
       ways+=solve(s,n+2);
       return dp[n]=ways;
}
    int numDecodings(string s) {
        int n=s.size();
        dp=vector<int>(n+1,-1);
        return solve(s,0);
    }
};