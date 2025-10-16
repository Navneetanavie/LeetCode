class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>adj[n];
        vector<int>indegree(n,0);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
             int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return n==count;
    }
};