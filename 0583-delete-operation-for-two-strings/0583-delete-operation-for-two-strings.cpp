class Solution {
public:
vector<vector<int>>dp;
    int lcs(string& s1, string& s2, int m, int n){
        if(m<0 || n<0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        
        if(s1[m]==s2[n]) return dp[m][n] = 1 + lcs(s1, s2, m-1, n-1);
        else return dp[m][n] = max(lcs(s1, s2, m-1, n),lcs(s1, s2, m, n-1));
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
       dp=vector<vector<int>>(m+1, vector<int>(n+1, -1));
        int CommonChar=lcs(word1,word2,m-1,n-1);
        int steps=(m-CommonChar)+(n-CommonChar);
        return steps;

    }
};