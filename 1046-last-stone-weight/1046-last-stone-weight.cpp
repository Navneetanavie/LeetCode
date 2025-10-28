class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            int new_ele=first-second;
            if(new_ele!=0)
            pq.push(new_ele);
        }
        return pq.empty()?0:pq.top();
    }
};