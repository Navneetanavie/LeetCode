class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        for(int ast:asteroids){
            bool destroyed=false;
            while(!st.empty()&&ast<0&&st.top()>0){
                if(abs(st.top())<abs(ast)){
                    st.pop();
                }
                else if(abs(st.top())==abs(ast)){
                    destroyed=true;
                    st.pop();
                    break;
                }
                else{
                   destroyed=true;
                   break;
                }
              
            }
              if(!destroyed) st.push(ast);  
        }
        vector<int>res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
      reverse(res.begin(),res.end());
      return res;
    }
};