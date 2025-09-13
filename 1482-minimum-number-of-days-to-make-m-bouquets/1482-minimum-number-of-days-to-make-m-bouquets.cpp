class Solution {
public:
   bool possible(vector<int>& bloomDay, int day,int m,int k){
    int n=bloomDay.size();
    int cnt=0;
    int NoB=0;
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=day){
            cnt++;
        }
        else{
            NoB+=cnt/k;
            cnt=0;
        }
    }
    NoB+=cnt/k;
    return (NoB>=m);
   }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low=*min_element(bloomDay.begin(),bloomDay.end());
         int high=*max_element(bloomDay.begin(),bloomDay.end());
         int ans=-1;
         while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                ans=mid;
              high=mid-1;
            }
            
            else low=mid+1;
         }
         return ans;
    }
};