class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>dp(nums.size()+2);
        vector<int>dp1(nums.size()+2);
        
        for(int i=nums.size()-1;i>=1;i--){
            dp[i]=max(dp[i+1],nums[i]+dp[i+2]);
        }
        for(int i=nums.size()-2;i>=0;i--){
            dp1[i]=max(dp1[i+1],nums[i]+dp1[i+2]);
        }
        return max(dp[1],dp1[0]);
    }
};