class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);//u,w
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));//u,k
        dist[src][0]=0;
        queue<vector<int>>q;
        q.push({0,src,0});//w,u,k
        while(!q.empty()){
            vector<int>f=q.front();
            q.pop();
            if(dist[f[1]][f[2]]<f[0]){
                continue;
            }
            f[2]++;
            if(f[2]>(k+1)){
                continue;
            }
            for(auto i:adj[f[1]]){
                int w=i.second;
                int u=i.first;
                if(dist[u][f[2]]>dist[f[1]][f[2]-1]+w){
                    dist[u][f[2]]=dist[f[1]][f[2]-1]+w;
                    q.push({dist[u][f[2]],u,f[2]});
                }
            }
        }
        int ans=INT_MAX;
        for(int i:dist[dst]){
            ans=min(ans,i);
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};