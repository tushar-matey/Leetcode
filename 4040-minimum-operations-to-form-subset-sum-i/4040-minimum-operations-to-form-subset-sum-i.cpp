class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<vector<pair<int,int>>>dp(nums.size()+1,vector<pair<int,int>>(sum+1,{0,INT_MAX-35}));
        dp[0][0]={1,0};
        for(int i=1;i<=nums.size();i++){
            dp[i][0]={1,0};
            for(int j=1;j<=sum;j++){
                int ans=0;
                int op=INT_MAX;
                //notTake
                ans=dp[i-1][j].first;
                op=dp[i-1][j].second;
                //take
                int x=1;
                int cop=0;
                while((j-(x*nums[i-1]))>=0){
                    if(dp[i-1][j-(x*nums[i-1])].first==1 && op>(dp[i-1][j-(x*nums[i-1])].second+cop)){
                        ans=dp[i-1][j-(x*nums[i-1])].first;
                        op=dp[i-1][j-(x*nums[i-1])].second+cop;
                    }
                    x*=2;
                    cop++;
                }
                x=1;
                cop=0;
                while((j-(nums[i-1]/x))<0){
                    x*=2;
                    cop++;
                }
                while((j-(nums[i-1]/x))>=0 && nums[i-1]/x>0){
                    if(dp[i-1][j-(nums[i-1]/x)].first && op>(dp[i-1][j-(nums[i-1]/x)].second+cop)){
                        ans=dp[i-1][j-(nums[i-1]/x)].first;
                        op=dp[i-1][j-(nums[i-1]/x)].second+cop;
                    }
                    x*=2;
                    cop++;
                    // if(i==1){
                    //     cout<<nums[i-1]/x<<endl;
                    // }
                }
                if((j-(nums[i-1]/x))>=0 && dp[i-1][j-(nums[i-1]/x)].first && op>dp[i-1][j-(nums[i-1]/x)].second){
                    ans=dp[i-1][j-(nums[i-1]/x)].first;
                    op=dp[i-1][j-(nums[i-1]/x)].second;
                }
                dp[i][j]={ans,op};
            }
        }
        // for(auto i :dp){
        //     for(auto j:i){
        //         cout<<j.first<<" "<<j.second<<", ";
        //     }
        //     cout<<endl;
        // }
        if(dp[nums.size()][sum].second==INT_MAX-35){
            return -1;
        }
        return dp[nums.size()][sum].second;
    }
};