class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>freq(26,0);
        for(auto&ch:tasks){
            freq[ch-'A']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>0) pq.push(freq[i]);
        }
        int time=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=0;i<n+1;i++){
                  if(!pq.empty()){
                  int curr_freq=pq.top();
                  pq.pop();
                  curr_freq--;
                  temp.push_back(curr_freq);
            }
          }
          for(auto &it:temp) {
            if(it>0)pq.push(it);
          }
          if(pq.empty()) time+=temp.size();
          else time+=(n+1); 
        }
         
       return time;
    }
};