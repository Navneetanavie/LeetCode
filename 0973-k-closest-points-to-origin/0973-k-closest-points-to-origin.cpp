class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(auto &it:points){
            int dis=sqrt((it[0]*it[0])+(it[1]*it[1]));
            pq.push({dis,{it[0],it[1]}});
        }
          vector<vector<int>>ans;
        while(k--){
            auto [dist,coord]=pq.top();
             pq.pop();
          ans.push_back({coord.first,coord.second});
         
          
        }
        return ans;
    }
};