class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        map<pair<int,int>,vector<pair<pair<int,int>,int>>>adj;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                
                vector<pair<pair<int,int>,int>>v;
                if( (j+1)<grid[0].size()){
                    if(grid[i][j]==1){
                        v.push_back({{i,j+1},0});
                    }
                    else{
                        v.push_back({{i,j+1},1});
                    }
                }
                if((j-1)>=0){
                    if(grid[i][j]==2){
                        v.push_back({{i,j-1},0});
                    }
                    else{
                        v.push_back({{i,j-1},1});
                    }
                }
                if((i+1)<grid.size()){                   
                    if(grid[i][j]==3){
                        v.push_back({{i+1,j},0});
                    }
                    else{
                        v.push_back({{i+1,j},1});
                    }
                }
                if((i-1)>=0){                   
                    if(grid[i][j]==4){
                        v.push_back({{i-1,j},0});
                    }
                    else{
                        v.push_back({{i-1,j},1});
                    }
                }
                adj[{i,j}]=v;
            }
        }
        map<pair<int,int>,int>dist;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        dist[{0,0}]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            pair<int,int> u=pq.top().second;
            pq.pop();
            if(d>dist[u]){
                continue;
            }
            for(auto i :adj[u]){
                pair<int,int> v=i.first;
                int w=i.second;
                if(dist.count(v)==0){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
                else if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist[{grid.size()-1,grid[0].size()-1}];

    }
};