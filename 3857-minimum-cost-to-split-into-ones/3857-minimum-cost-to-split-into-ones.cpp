class Solution {
public:

    int r(int x,vector<int>dp){
        if(x==2){
            return 1;
        }
        if(x==1){
            return 0;
        }
        if(dp[x]!=-1){
            return dp[x];
        }
        int ans=INT_MAX;
        for(int i=1;i<x;i++){
            ans=min(ans,i*(x-i)+r(i,dp)+r(x-i,dp));
        }
        dp[x]=ans;
        return ans;
    }
    int minCost(int n) {
        vector<int>dp(n+1,-1);
        // int ans=r(n,dp);
        int ans=0;
        for(int i=1;i<n;i++){
            ans+=i;
        }
        return ans;
    }
};