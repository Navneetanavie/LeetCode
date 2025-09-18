class Solution {
public:


  void Union(vector<int>&parent,vector<int>&size,int i,int j){
        int u=find(parent,i);
        int v=find(parent,j);
        if(u==v)return;
        if(size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }
        else{
            parent[v]=u;
            size[u]+=size[v];
        }
    }
  int find(vector<int>&parent,int node){
    if(parent[node]==node)  return node;
    return find(parent,parent[node]);
  }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>parent(n+1,0),size(n+1,1);
        for(int i=0;i<n;i++)
         parent[i]=i;
        for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
             if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
              Union(parent,size,i,j);
           } 
        }
            int cnt=0;
        for(int i=0;i<n;i++)
           if(parent[i]==i) cnt++;
        return n-cnt;
    }
};