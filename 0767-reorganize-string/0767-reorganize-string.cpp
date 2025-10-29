class Solution {
public:
    string reorganizeString(string s) {
      unordered_map<char,int>mp;
        priority_queue<pair<int,char>>pq;
        for(auto &c:s){
            mp[c]++;
        }
        for(auto &[ch, freq]:mp){
              pq.push({freq,ch});
        }
        
      string ans="";
        while(pq.size()>1){
         auto it1=pq.top();
         pq.pop();
         auto it2=pq.top();
         pq.pop();
          int freq1=it1.first;
          int freq2=it2.first;
          char res1=it1.second;
          char res2=it2.second;
          ans+=res1;
          ans+=res2;
          if(--freq1>0) pq.push({freq1,res1});
          if(--freq2>0) pq.push({freq2,res2});

        }

        if(!pq.empty()){
          if(pq.top().first>1)
          return "";
          else ans+=pq.top().second;
        }

        return ans;
    }
};