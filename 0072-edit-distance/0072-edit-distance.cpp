#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dp;
class Solution {
private:
int solve(string s1,string s2,int m,int n){
    if(m==0) return n;
    if(n==0) return m;
    if(dp[m][n]!=-1) return dp[m][n];
    if(s1[m-1]==s2[n-1]) 
    return dp[m][n]=solve(s1,s2,m-1,n-1);
    else
    return dp[m][n]=1+min({solve(s1,s2,m-1,n),solve(s1,s2,m,n-1),solve(s1,s2,m-1,n-1)});
    return dp[m][n];
    
}
public:
    int minDistance(string word1, string word2) {
       int m=word1.size();
       int n=word2.size();
       dp=vector<vector<int>>((m+1),vector<int>(n+1,-1));
       return solve(word1,word2,m,n); 
    }
};