class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int ans=0;
        int n=heights.size();
        heights.push_back(0);
        for(int i=0;i<=n;i++){
           while(!st.empty()&&heights[i]<heights[st.top()]){
             int currHeight=heights[st.top()];
              st.pop();
              int left=st.empty()?-1:st.top();
             int width=i-left-1;
             
             ans=max(ans,currHeight*width);

           }
           st.push(i);
        }
        return ans;
    }
};