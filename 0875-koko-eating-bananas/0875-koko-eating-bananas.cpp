class Solution {
public:
long long solve(vector<int>&piles,int mid){
    long long bananas_eating_from_pile=0;
    for(int i=0;i<piles.size();i++){
         bananas_eating_from_pile+=ceil((double)piles[i]/(double)mid);
    }
    return bananas_eating_from_pile;
}
    int minEatingSpeed(vector<int>& piles, int h) {
       int low=1;
       int high=*max_element(piles.begin(),piles.end());
       int ans=0;
       while(low<=high){
        int mid=(low+high)/2;
        if(solve(piles,mid)<=h) {
           ans=mid; 
            high=mid-1;
        }
        else low=mid+1;
        
       }

       return ans;
    }
};