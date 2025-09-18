class Solution {
public:
  void make(int i,vector<int>&parent,vector<int>&size){
      parent[i]=i;
      size[i]=i;
  }
  void Union(int nodeA, int nodeB,vector<int>&parent,vector<int>&size){
    nodeA=find(nodeA,parent);
    nodeB=find(nodeB,parent);
    if(nodeA!=nodeB){
        if(size[nodeA]<size[nodeB]){
            swap(nodeA,nodeB);
        }
        parent[nodeB]=nodeA;
        size[nodeA]+=size[nodeB];
    }
  }
  int find(int node,vector<int>&parent){
       if(node==parent[node]) return node;
       return parent[node]=find(parent[node],parent);
  }
  
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int>parent(n),size(n);
        for(int i=0;i<n;i++) make(i,parent,size);
        for(auto it:connections)
         Union(it[0],it[1],parent,size);
         int cnt=0;
         for(int i=0;i<n;i++){
            if(parent[i]==i) cnt++;
         }
         return cnt-1;
    }
};