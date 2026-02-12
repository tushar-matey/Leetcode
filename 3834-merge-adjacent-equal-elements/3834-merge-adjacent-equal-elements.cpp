class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long>s;
        for(int j=0;j<nums.size();j++){
            long long i=(long long)nums[j];
            if(s.empty() || s.top()!=i){
                s.push(i);
            }
            else{
                long long sum=i;
                while(!s.empty() && s.top()==sum){
                    sum+=s.top();
                    s.pop();
                }
                s.push(sum);
            }
        }
        vector<long long>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};