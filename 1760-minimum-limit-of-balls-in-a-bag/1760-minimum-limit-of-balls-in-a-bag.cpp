class Solution {
public:
bool solve(vector<int>& nums, int mid,long int maxOp){
    long long totOp=0;
    for(int i=0;i<nums.size();i++){
        
        totOp+=(nums[i]-1)/mid;
    }
    return (totOp<=(long long)maxOp);
}
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(solve(nums,mid,maxOperations)){
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