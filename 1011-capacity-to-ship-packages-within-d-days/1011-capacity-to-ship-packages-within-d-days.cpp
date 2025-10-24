class Solution {
public:
int func(vector<int>& weights, int cap){
    int n=weights.size();
     int load=0;
     int day=1;
    for(int i=0;i<n;i++){
        if(load+weights[i]>cap){
            day++;
            load=weights[i];
        }
        else{
            load+=weights[i];
        }
    }
    return day;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int high=accumulate(weights.begin(),weights.end(),0);
        int low = *max_element(weights.begin(), weights.end());
       
        while(low<=high){
            int mid=(low+high)/2;
            if(func(weights,mid)<=days)
            high=mid-1;
            else low=mid+1;
        }
      return low;
    }
};