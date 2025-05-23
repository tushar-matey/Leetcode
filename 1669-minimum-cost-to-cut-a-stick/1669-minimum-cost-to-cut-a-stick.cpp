class Solution {
public:
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size()));
        for(int i=cuts.size()-1;i>0;i--){
            for(int j=0;j<cuts.size()-1;j++){
                if(i>j){
                    continue;
                }
                int ans=INT_MAX;
                for(int k=i;k<=j;k++){
                    ans=min(ans,cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=ans;
                
            }
        }
        return dp[1][cuts.size()-2];
       
    }
};