class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int top=0,bottom=n-1;
        int left=0,right=n-1;
        int cnt=1;
        while(top<=bottom&&left<=right){
           for(int j=left;j<=right;j++){
            matrix[top][j]=cnt++;
      
           }
           top++;
           for(int i=top;i<=bottom;i++){
            matrix[i][right]=cnt++;
           
           }
           right--;
           if(top<=bottom){
           for(int j=right;j>=left;j--){
            matrix[bottom][j]=cnt++;
            
            }
           }
           bottom--;
           if(left<=right){
            for(int i=bottom;i>=top;i--){
            matrix[i][left]=cnt++;
           
            }
           }
           left++;
            
        }
        return matrix;
    }
};