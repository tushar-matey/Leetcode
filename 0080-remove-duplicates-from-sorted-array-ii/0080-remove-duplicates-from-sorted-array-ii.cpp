class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int>m;
        int x=0;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])==m.end()){
                m[nums[i]]=1; 
                swap(nums[i],nums[x]);
                x++;
            }
            else{
                m[nums[i]]++;
                if(m[nums[i]]<=2){
                    swap(nums[i],nums[x]);
                    x++;
                }
            }
        }
        return x;

    }
};