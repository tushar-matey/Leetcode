class Solution {
public:
    int* parent;
    int* size;
    int find(int i){
        if(parent[i]==i){
            return i;
        }
        parent[i]=find(parent[i]);
        return parent[i];
    }
    bool union_(int u,int v){
        u=find(u);
        v=find(v);
        if(u==v){
            return false;
        }
        if(size[u]>size[v]){
            swap(u,v);
        }
        parent[u]=v;
        size[v]+=size[u];
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& p) {
        int n=p.size();
        parent=new int[n];
        size=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
        vector<vector<int>>e;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int w=abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
                e.push_back({w,i,j});
                // cout<<i<<" "<<j<<endl;
            }
        }
        sort(e.begin(),e.end());
        // for(auto i:e){
            // cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        // }
        int ans=0;
        int edges=0;
        for(auto i:e){
            int u=i[1];
            int v=i[2];
            if(union_(u,v)){
                ans+=i[0];
                edges++;
                if(edges==n-1){
                    break;
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     cout<<i<<" "<<parent[i]<<endl;
        // }
        return ans;
    }
};