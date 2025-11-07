class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
       int prod1=nums[0],prod2=nums[0],res=nums[0];
       for(int i=1;i<n;i++){
        int temp=max({nums[i],prod1*nums[i],prod2*nums[i]});
         prod2=min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1=temp;
        res=max(res,prod1);
       }
       return res;
    }
};