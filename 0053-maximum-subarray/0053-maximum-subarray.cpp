class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
              sum=0;
            }
             maxi=max(maxi,sum);
        }
       int  mini_neg=*max_element(nums.begin(),nums.end());
        if(mini_neg<0)
        return mini_neg;
        else
        return maxi;
    }
}; // -4