class Solution {
public:
 long long func(vector<int>& nums,int divisor){
    int cnt=0;
    int n=nums.size();
    long long sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=ceil(double(nums[i])/(double(divisor)));
    }
    return sum;
 }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        if(nums.size()>threshold) return -1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(func(nums,mid)<=threshold)
            high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};