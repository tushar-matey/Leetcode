class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long>ans;
        for(int curr:nums){
            long long i=curr;
            while(!ans.empty() && ans.back()==i){
                i+=ans.back();
                ans.pop_back();
            }
            ans.push_back(i);
        }
        return ans;
    }
};