class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(auto op:operations){
            if(op=="C"){
                st.pop();
            }
            else if(op=="D"){
                st.push(2*st.top());
            }
            else if(op=="+"){
                int first=st.top();
                st.pop();
                int second=st.top();
                st.pop();
                st.push(second);
                st.push(first);
                st.push(first+second);
            }
            else st.push(stoi(op));
        }
        int res=0;
        while(!st.empty()){
          res+=st.top();
          st.pop();
        }
        return res;
    }
};