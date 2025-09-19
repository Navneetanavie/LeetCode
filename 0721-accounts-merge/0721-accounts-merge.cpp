class Solution {
public:
vector<int>parent;
vector<int>size;
int find(int node){
     if(node==parent[node]) return node;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=i;
        }
        sort(accounts.begin(),accounts.end());
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string str=accounts[i][j];
                if(mp.find(str)==mp.end())
                    mp[str]=i;
                else
                    Union(i,mp[str]);
            }
        }


      vector<string>adj[n];
      for(auto it:mp){
        int node=find(it.second);
        adj[node].push_back(it.first);
      }
      vector<vector<string>>ans;
      for(int i=0;i<n;i++){
        if(adj[i].size()==0) continue;
        sort(adj[i].begin(),adj[i].end());
        adj[i].insert(adj[i].begin(),accounts[i][0]);
        ans.push_back(adj[i]);
      }
      return ans;


    }
};