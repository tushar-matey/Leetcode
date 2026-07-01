class Solution {
public:

    void print(queue<int>q){
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
    }
    int minReorder(int n, vector<vector<int>>& c) {
        vector<vector<int>>v(n);
        vector<vector<int>>in(n);
        vector<bool>vis(n);
        vis[0]=1;
        queue<int>q;
        q.push(0);
        for(int i=0;i<c.size();i++){
            v[c[i][0]].push_back(c[i][1]);
            in[c[i][1]].push_back(c[i][0]);
            if(c[i][1]==0){
                vis[c[i][0]]=1;
                q.push(c[i][0]);
            }
        }
        // print(q);
        int ans=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            if(f!=0){
                for(int i:in[f]){
                    if(!vis[i]){
                        vis[i]=true;
                        q.push(i);
                    }
                }
            }
            for(int i:v[f]){
                if(!vis[i]){
                    vis[i]=true;
                    q.push(i);
                    ans++;
                }
            }
        }
        return ans;
    }
};