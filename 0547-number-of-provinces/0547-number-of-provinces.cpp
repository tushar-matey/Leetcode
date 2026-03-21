class Solution {
public:
    int find_set(int v,vector<int>&parent){
        if(parent[v]==v){
            return v;
        }
        return parent[v]=find_set(parent[v],parent);
    }

    
    void union_set(int u,int v,vector<int>&parent,vector<int>&size){
        u=find_set(u,parent);
        v=find_set(v,parent);
        if(u!=v){
            if(size[u]<size[v]){
                swap(u,v);
            }
            parent[v]=u;
            size[u]+=size[v];
        }
    }
    int findCircleNum(vector<vector<int>>& C) {
        vector<int>p(C.size());
        vector<int>s(C.size(),1);
        for(int i=0;i<C.size();i++){
            p[i]=i;
        }
        for(int i=0;i<C.size();i++){
            for(int j=0;j<C.size();j++){
                if(C[i][j]==1){
                    union_set(i,j,p,s);
                }
            }
        }
        int ans=0;
        for(int i=0;i<C.size();i++){
            if(find_set(i,p)==i){
                ans++;
            }
        }
        return ans;
    }
};