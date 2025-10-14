class Solution {
public:
vector<vector<int>>dp;
int solve(int i, int j, string &s){
    if(i>=j) return 0;
    if(isPalindrome(i,j,s)==true) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mn=INT_MAX;
    for(int k=i;k<j;k++){
       if(isPalindrome(i,k,s)){
          int temp=1+solve(i,k,s)+solve(k+1,j,s);
       if(mn>temp) mn=temp;
     }
    }
    return dp[i][j]=mn;
}
bool isPalindrome(int i, int j, string &s){
     while(i<j){
        if(s[i++]!=s[j--]) return false;
     }
     return true;
}
    int minCut(string s) {
        int n=s.size();
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s);
    }
};