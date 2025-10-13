class Solution {
public:
vector<vector<int>>dp;
int lcs(int n,int m, string &s1,string &s2){
    if(n<0||m<0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s1[n]==s2[m]) return dp[n][m]=1+lcs(n-1,m-1,s1,s2);
    else return dp[n][m]=max(lcs(n-1,m,s1,s2),lcs(n,m-1,s1,s2));

}
    int minInsertions(string s) {
        int n=s.size();
        int m=n;
        dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
        string reversed=s;
        reverse(reversed.begin(),reversed.end());
        return n-lcs(n-1,m-1,s,reversed);
    }
};