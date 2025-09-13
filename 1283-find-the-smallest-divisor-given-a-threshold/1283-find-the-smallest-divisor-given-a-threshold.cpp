class Solution {
public:
bool solve(vector<int>& nums, int threshold,int mid){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+=ceil((double)nums[i]/(double)mid);
    }
   return (sum<=threshold);
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(solve(nums,threshold,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
               low=mid+1; 
            }
        }
        return ans;
    }
};