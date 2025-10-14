class Solution {
public:
vector<vector<int>>dp;
bool solve(int n, int m,string &s, string &p){
    if(n<0){
        while(m>=0&&p[m]=='*') m--;
        if(m<0) return true;
         return false;
    }
    if(m<0) return false;
    
    if(dp[n][m]!=-1) return dp[n][m];
    if(s[n]==p[m]|| p[m]=='?') return dp[n][m]=solve(n-1,m-1,s,p);
     if(p[m]=='*') return dp[n][m]=solve(n-1,m,s,p)||solve(n-1,m-1,s,p)||solve(n,m-1,s,p);
    return dp[n][m]=false;

}
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        dp=vector<vector<int>>(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,p);
    }
};