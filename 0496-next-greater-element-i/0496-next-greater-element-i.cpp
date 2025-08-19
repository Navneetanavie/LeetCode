class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       stack<int>st;
       unordered_map<int,int>mp;
       int n=nums2.size();
       
       for(int i=0;i<n;i++){
        while(!st.empty()&&nums2[i]>nums2[st.top()]){
            int ind=st.top();
            st.pop();
           mp[nums2[ind]]=nums2[i];
        }
        
        st.push(i);
       }
       while (!st.empty()) {
        mp[nums2[st.top()]] = -1;   
        st.pop();
    }

       vector<int>res;
       for(int num:nums1){
           res.push_back(mp[num]);
       }
       return res;
    }
};