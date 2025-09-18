class Solution {
public:
  void make(int i,vector<int>&parent,vector<int>&size){
     parent[i]=i;
     size[i]=1;
  }

  void Union(int node1, int node2, vector<int>&parent,vector<int>&size){
    node1=find(node1,parent);
    node2=find(node2,parent);
    if(node1!=node2){
        if(size[node1]<size[node2])
         swap(node1,node2);
    
    parent[node2]=node1;
    size[node1]+=size[node2];
    }
  }

  int find(int node,vector<int>&parent){
    if(parent[node]==node)  return node;
    return parent[node]=find(parent[node],parent);
  }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<int>parent(n),size(n);
        for(int i=0;i<n;i++)
          make(i,parent,size);
        for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
             if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1])
              Union(i,j,parent,size);
           } 
        }
            int cnt=0;
        for(int i=0;i<n;i++)
           if(parent[i]==i) cnt++;
        return n-cnt;
    }
};