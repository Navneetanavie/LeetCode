class Solution {
public:
vector<vector<int>>dp;
   int lcs(int n, int m , string &s1, string &s2){
     if(n<0||m<0) return 0;
     if(dp[n][m]!=-1) return dp[n][m];
     if(s1[n]==s2[m]) return dp[n][m]=1+lcs(n-1,m-1,s1,s2);
     else return dp[n][m]=max(lcs(n-1,m,s1,s2),lcs(n,m-1,s1,s2));
   }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
        int totalChar=n+m;
        int commonChar=lcs(n-1,m-1,word1,word2);
        return totalChar-(2*commonChar);

    }
};