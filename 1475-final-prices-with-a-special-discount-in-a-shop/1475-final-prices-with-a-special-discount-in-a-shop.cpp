class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        vector<int>res=prices;
        int n=prices.size();
        for(int i=0;i<n;i++){
            while(!st.empty()&&prices[i]<=prices[st.top()]){
                int ind=st.top();
                st.pop();
                res[ind]=prices[ind]-prices[i];
            }
            st.push(i);
        }
        return res;
    }
};