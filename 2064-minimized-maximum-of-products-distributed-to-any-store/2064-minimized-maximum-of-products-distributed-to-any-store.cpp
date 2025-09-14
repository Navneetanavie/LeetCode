class Solution {
public:
bool solve(vector<int>& quantities,int mid,int n){
    int cnt=0;
    for(int i=0;i<quantities.size();i++){
        cnt+=ceil((double)quantities[i]/(double)mid);
    }
    return(cnt<=n);
}
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=*max_element(quantities.begin(),quantities.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(quantities,mid,n)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};