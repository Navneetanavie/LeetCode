class Solution {
public:
vector<vector<int>>dp;
int lcs(int n, int m,string &s1,string &s2){
    if(n==0||m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s1[n-1]==s2[m-1]) return dp[n][m]=1+lcs(n-1,m-1,s1,s2);
    else return dp[n][m]=max(lcs(n-1,m,s1,s2),lcs(n,m-1,s1,s2));
}
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
        int size=lcs(n,m,str1,str2);
        int i=n,j=m;
        string a=str1;
        string b=str2;
        string ans="";
        while(i>0&&j>0){
            if(a[i-1]==b[j-1]){
                ans+=a[i-1];
                i--;
                j--;
            }
            else if(dp[i][j-1]>dp[i-1][j]){
                ans+=b[j-1];
                j--;
            }
            else{
                ans+=a[i-1];
                i--;
            }
        }
        while(i>0){
            ans+=a[i-1];
            i--;
        }
        while(j>0){
            ans+=b[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};