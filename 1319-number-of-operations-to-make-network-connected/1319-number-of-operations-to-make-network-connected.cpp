class Solution {
public:
vector<int>parent;
vector<int>size;
  int find(int node){
    if(node==parent[node]) return node;
    return parent[node]=find(parent[node]);
  }

void Union(int nodeA, int nodeB){
    nodeA=find(nodeA);
    nodeB=find(nodeB);
    if(nodeA!=nodeB){
        if(size[nodeA]<size[nodeB])
          swap(nodeA,nodeB);
          parent[nodeB]=nodeA;
          size[nodeA]+=size[nodeB];
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
         parent[i]=i;
         size[i]=i;
        }
     for(auto it:connections){
         Union(it[0],it[1]);
     }
     int cnt=0;
     for(int i=0;i<n;i++){
        if(parent[i]==i) cnt++;
     }
        return cnt-1;
    }
};