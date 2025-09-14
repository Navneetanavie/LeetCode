class Solution {
public:
bool solve(vector<int>& time, int minTrips,long long mid){
    long long totTrips=0;
    for(int i=0;i<time.size();i++){
       totTrips+=mid/time[i];
    }
    return ((long long)minTrips<=totTrips);
}
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=1;
        long long high=1LL*(*min_element(time.begin(),time.end()))*totalTrips;
        long long ans=0;
        while(low<=high){
            long long mid=(low+high)/2;
            if(solve(time,totalTrips,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};