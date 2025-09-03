class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>set;
        int n=nums.size();
        int left=0;
        int sum=0;
        int maxSum=0;
        for(int i=0;i<n;i++){
        
                while(set.count(nums[i])!=0){
                  set.erase(nums[left]);
                  sum-=nums[left];
                  left++;
                }
                
                  sum+=nums[i];
                set.insert(nums[i]);
           
             maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};