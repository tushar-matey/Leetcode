class Solution {
public:
    int r(int i,int d,const vector<vector<int>>&adj,vector<int>&depth){
        if(adj[i].empty()){
            depth[i]=d;
            return 1;
        }
        depth[i]=d;
        int ans=0;
        d++;
        for(int j:adj[i]){
            ans=max(ans,r(j,d,adj,depth));
        }
        return 1+ans;
    }
    
    long long weightedSum(vector<int>& p, vector<int>& n) {
        vector<vector<int>>adj(p.size());
        for(int i=1;i<p.size();i++){
            if(p[i]!=-1){
                adj[p[i]].push_back(i);
            }
        }
        vector<int>depth(n.size());
        long long h=r(0,1,adj,depth);
        long long ans=0;
        // for(int i:depth){
        //     cout<<i<<" ";
        // }
        for(int i=0;i<n.size();i++){
            ans+=n[i]*(h-depth[i]+1);
        }
        return ans;
    }
};