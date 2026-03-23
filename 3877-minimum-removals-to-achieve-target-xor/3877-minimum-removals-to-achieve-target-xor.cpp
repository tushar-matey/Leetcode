class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
       vector<int>dp(1<<16,-1);
        dp[0]=0;
        vector<int>temp;
        for(int i:nums){
            temp=dp;
            for(int j=0;j<dp.size();j++){
                if(dp[j]!=-1){
                    temp[i^j]=max(temp[i^j],1+dp[j]);
                }
            }
            dp=temp;
        }
        if(dp[target]==-1){
            return -1;
        }
        return nums.size()-dp[target];
    }
};