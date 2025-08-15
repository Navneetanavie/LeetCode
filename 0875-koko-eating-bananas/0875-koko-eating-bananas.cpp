class Solution {
public:
long long functionMinHours(vector<int>& piles,int mid){
    long long minimumHours=0;
    for(int i=0;i<piles.size();i++){
        
         minimumHours+=ceil((double)piles[i]/(double)mid); 
    }
   return minimumHours;

}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            long long minHours=functionMinHours(piles,mid);
            if(minHours<=h){
                  ans=mid;
                  high=mid-1;
            }
               
            
            else low=mid+1;
           
        }
        return ans;
    }
};//