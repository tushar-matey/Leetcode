class Solution {
public:
    // int r(int i,vector<int>nums){
    //     if(i>nums.size()-1){
    //         return 0;
    //     }
    //     int ans=max(r(i+1,nums),nums[i]+r(i+2,nums));
    //     return ans;
    // }

    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+2);
        for(int i=nums.size()-1;i>=0;i--){
            dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
        }
        return dp[0];
    }
};