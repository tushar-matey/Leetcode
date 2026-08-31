class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        vector<vector<int>>dp(m.size(),vector<int>(m[0].size()));
        int ans=0;
        for(int i=0;i<m[0].size();i++){
            if(m[0][i]=='1'){
                dp[0][i]=1;
                ans=1;
            }
        }
        for(int i=1;i<m.size();i++){
            if(m[i][0]=='1'){
                dp[i][0]=1;
                ans=max(ans,1);
            }
            for(int j=1;j<m[0].size();j++){
                if(m[i][j]=='1'){
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        // for(auto i:dp){
        //     for(int j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<ans;
        if(ans==0){
            return 0;
        }
        return pow(ans,2);
    }
};