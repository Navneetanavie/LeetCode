class Solution {
public:

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();  
        
    int ans = INT_MAX; 
     vector<vector<int>> dp(n, vector<int>(n, 0));
     // all the base cases for the tabulation
     for(int i=0;i<n;i++){
         dp[0][i]=matrix[0][i];
     }
      
      for(int i=1;i<n;i++){
          for(int j=0;j<n;j++){
              int a=matrix[i][j]+dp[i-1][j];
              int b=matrix[i][j];
              int c=matrix[i][j];
              if(j-1>=0){
                  c+=dp[i-1][j-1];
              }
              else{
                  c+=1e8;
              }
              if(j+1<n){
                     b+=dp[i-1][j+1];
              }
              else{
                  b+=1e8;
              }
             dp[i][j]=min(a,min(b,c));
          }
      }
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
        return ans;
    }
};