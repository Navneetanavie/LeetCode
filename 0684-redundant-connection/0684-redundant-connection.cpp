class Solution {
public:
vector<int>parent,size;
void make(int i){
 parent[i]=i;
 size[i]=i;
}
 int find(int node){
    if(parent[node]==node) return node;
    return parent[node]=find(parent[node]);
 }
 void Union(int node1,int node2){
    node1=find(node1);
    node2=find(node2);
    if(node1!=node2){
        if(size[node1]<size[node2]) 
          swap(node1,node2);
      parent[node2]=node1;
      size[node1]+=size[node2];
    }
 }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        size.resize(n+1);
        vector<int>res;
        for(int i=0;i<n;i++) make(i);
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            if(find(u)==find(v)){
               res.push_back(u);
               res.push_back(v);
               
            } 
            else Union(u,v);
            
        }
        return res;
    }
};