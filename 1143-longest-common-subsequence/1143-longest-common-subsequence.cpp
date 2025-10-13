class Solution {
    vector<vector<int>>dp;
public:
int solve(int m,int n,string &s1,string &s2){
    if(m<0||n<0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    if(s1[m]==s2[n]) return dp[m][n]=1+solve(m-1,n-1,s1,s2);
    else return dp[m][n]=max(solve(m,n-1,s1,s2),solve(m-1,n,s1,s2));
    return dp[m][n];
}
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        dp=vector<vector<int>>(m+1,vector<int>(n+1,-1));
       return solve(m-1,n-1,text1,text2);
    }
};