class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int max_=nums[0];
        int min_=nums[0];
        // cout<<max_<<" "<<min_<<" "<<ans<<endl;
        for(int i=1;i<nums.size();i++){
            int prevmax=max_;
            int prevmin=min_;
            max_=max(nums[i],max(nums[i]*prevmax,nums[i]*prevmin));
            
            min_=min(nums[i],min(nums[i]*prevmax,nums[i]*prevmin));
            // cout<<nums[i]<<" "<<nums[i]*max_<<" "<<nums[i]*min_<<endl;
            ans=max(ans,max_);
            // cout<<max_<<" "<<min_<<" "<<ans<<endl;
        }
        return ans;
    }
};