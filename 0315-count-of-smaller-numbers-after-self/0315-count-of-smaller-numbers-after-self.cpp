class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts;

        for (int i=0;i<nums.size();i++){
            int x=0;
            for (int j=i+1;j<nums.size();j++){
                if (nums[j]<nums[i]){
                    x++;
                }
            }
            counts.push_back(x);
        }

        return counts;
    }
};