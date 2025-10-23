class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(int i=0;i<s.size();i++){  
          if(s[i]==']'){
             string res="";
            while(st.top()!="["){
                res=st.top()+res;
                st.pop();
            }
            st.pop();
             string times="";
             int to_times;
             while(!st.empty()&&isdigit(st.top()[0])){
                times=st.top()+times;
                st.pop();
             }
             to_times=stoi(times);
             string ans="";
             while(to_times--)
              ans=res+ans;
              st.push(ans);
          }
          else{
            st.push(string(1,s[i]));
          }

        }

        string decoded="";
        while(!st.empty()){
            decoded=st.top()+decoded;
            st.pop();
        }
        
        return decoded;
    }
};