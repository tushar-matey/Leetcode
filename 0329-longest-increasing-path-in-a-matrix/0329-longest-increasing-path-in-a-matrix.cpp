class Solution {
public:
    bool v(int i,int j,int n,int m){
        return i<n && i>=0 && j<m && j>=0;
    }
    int solve(const vector<vector<int>>& ma,vector<vector<int>>& dp,int i,int j,const int n,const int m){
        if(!v(i,j,n,m)){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=1;
        vector<pair<int,int>>d={{1,0},{-1,0},{0,1},{0,-1}};
        for(int k=0;k<4;k++){
            int i1=i+d[k].first;
            int j1=j+d[k].second;
            if(v(i1,j1,n,m) && ma[i1][j1]<ma[i][j]){
                ans=max(ans,1+solve(ma,dp,i1,j1,n,m));
            }
        }
        return dp[i][j]=ans;

    }
    int longestIncreasingPath(vector<vector<int>>& ma) {
        int n=ma.size();
        int m=ma[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int max_=1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                max_=max(max_,solve(ma,dp,i,j,n,m));
            }
        }
       
        
        return max_;
    }
};